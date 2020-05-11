using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Lab3_424 {
    class Program {
        struct Person {
            public string name;
            public int age;
        };

        static int Compare(Person p1, Person p2) {
            if(p1.name.CompareTo(p2.name) == 0) {
                return p1.age.CompareTo(p2.age);
            }
            return p1.name.CompareTo(p2.name);
        }

        static int Compare1(Person p1, Person p2) {
            if(p1.age.CompareTo(p2.age) == 0) {
                return p1.name.CompareTo(p2.name);
            }
            return p1.age.CompareTo(p2.age);
        }
        // Generic function for print values of an array
        static void PrintArray<T>(T[] arr) {
            foreach (T item in arr) {
                Console.Write(item + " ");
            }
            Console.WriteLine("\n");
        }
        // Print struct type
        static void PrintPerson(Person[] p) {
            foreach(Person person in p) {
                Console.WriteLine(person.name + "-" + person.age + " ");
            }
            Console.WriteLine("\n");
        }
        static void Main(string[] args) {
            // Array of integers
            int[] arr_int = {6, 1, -3, 67, 0, -32, 98, 189, 56};
            Array.Sort(arr_int);
            PrintArray(arr_int);

            // Array of float
            float[] arr_float = { 645.32f, 37.40f, 76.30f, 5.40f, -34.23f, 1.11f, -34.94f, 23.37f, 635.46f, -876.22f, 467.73f, 62.26f };
            Array.Sort(arr_float);
            PrintArray(arr_float);

            // Array of String
            String[] arr_string = { "Dog", "Apple", "Banana", "Tall", "Zebra" };
            Array.Sort(arr_string);
            PrintArray(arr_string);

            // Array of Person
            Person[] arr_person = { new Person() { name = "Hal", age = 20 },
                                    new Person() { name = "Susann", age = 31},
                                    new Person() { name = "Dwight", age = 19},
                                    new Person() { name = "Kassandra",age = 21},
                                    new Person() { name = "Lawrence", age = 25},
                                    new Person() { name = "Cindy", age = 22},
                                    new Person() { name = "Cory", age = 27},
                                    new Person() { name = "Mac", age = 19},
                                    new Person() { name = "Romana", age = 27},
                                    new Person() { name = "Doretha", age = 32},
                                    new Person() { name = "Danna", age = 20},
                                    new Person() { name = "Zara", age = 23},
                                    new Person() { name = "Rosalyn", age = 26},
                                    new Person() { name = "Risa", age = 24},
                                    new Person() { name = "Benny", age = 28},
                                    new Person() { name = "Juan", age = 33},
                                    new Person() { name = "Natalie", age = 25} };
            // sort people alphabetically (lexicographically) by name
            Array.Sort<Person>(arr_person, Compare);
            PrintPerson(arr_person);

            //sort people descending by age, where people of the same age should be sorted
            // alphabetically
            Array.Sort<Person>(arr_person, Compare1);
            PrintPerson(arr_person);
        }

    }
}
