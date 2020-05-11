using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

namespace Lab_4 {
    class Program {
        static void Main(string[] args) {
            string path = "/Users/lamnguyen/Desktop/CSULB/Semesters/Spring-2020/CECS-424/Assignment-4/files";


            IEnumerable<string> files = EnumerateFilesRecursively(path);
            
            XDocument report = CreateReport(files);
            Console.WriteLine("Enter a name for the output file (HTML File):");
            string outputFolder = "/Users/lamnguyen/Desktop/CSULB/Semesters/Spring-2020/CECS-424/Assignment-4/" + Console.ReadLine();
            report.Save(outputFolder);

        }

        static XElement getFileInfo(IEnumerable<string> files) {
            var query = from file in files

                        group file by Path.GetExtension(file).ToLower() into e
                        select new {
                            Type = e.Key,
                            Count = e.Count(),
                            TotalSize = FormatByteSize(e.Select(f => new FileInfo(f).Length).Sum())
                        };

            XElement table = new XElement("table",
                new XAttribute("style", "width : 40%"),
                new XAttribute("border", 1),
                new XElement("thead",
                    new XElement("tr",
                        new XElement("th", "Type"),
                        new XElement("th", "Count"),
                        new XElement("th", "Total Size")),
                new XElement("tbody",
                    new XElement("tr", from value in query select 
                    new XElement("tr",
                        new XElement("td", value.Type),
                        new XElement("td", value.Count),
                        new XElement("td", value.TotalSize))))));

            return table;
        }
        // Enumerate all files in a given folder recursively including the entire sub-folder hierarchy
        static IEnumerable<string> EnumerateFilesRecursively(string path) {

            foreach (string file in Directory.GetFiles(path)) {
                yield return file; // yield a sequence of files (contains the path + file name) w/o exiting
                //yield return Path.GetFileName(file); // return file name only
            }

            foreach (string subDir in Directory.GetDirectories(path)) {
                foreach (string subFile in EnumerateFilesRecursively(subDir)) {
                    yield return subFile; // yield a sequence of files (contains the path + file name) w/o exiting
                    //yield return Path.GetFileName(subFile);
                }
            }
        }

        //Format a byte size in human readable form
        static string FormatByteSize(long byteSize) {
            int unit = 1000;
            string unitStr = "B";
            if (byteSize < unit)
                return string.Format("{0} {1}", byteSize, unitStr);
            int exp = (int)(Math.Log(byteSize) / Math.Log(unit));
            return string.Format("{0:##.##} {1}{2}", byteSize / Math.Pow(unit, exp), "kMGTPEZ"[exp - 1], unitStr);
        }

        // Create a HTML document containing a table with three columns: “Type”, “Count”, and “Size”
        static XDocument CreateReport(IEnumerable<string> files) {
            return new XDocument(new XElement("html",
                                 new XElement("head",
                                 new XElement("body",
                                 new XElement("td", getFileInfo(files))))));
        } 
    }
}
