import Data.List (sortBy)

data Person = Person { 
  name :: String,
  age :: Int 
} deriving(Show, Eq, Ord)

compare2 :: Person -> Person -> Ordering
compare2 (Person a b) (Person x y)
  | b < y  = GT          --  descendent by age
  | b > y  = LT          --  descendent by age
  | b == y = compare a x -- alphabetical by name

main = do
  let numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
  let people  = [ Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, 
                  Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, 
                  Person "Cory" 27, Person "Mac" 19, Person "Romana" 27, 
                  Person "Doretha" 32, Person "Danna" 20,Person "Zara" 23, 
                  Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, 
                  Person "Juan" 33, Person "Natalie" 25 ]

  putStrLn " "        
  putStrLn "Sort numbers ascending by numerical value:"
  print (sortBy compare numbers)

  putStrLn " "
  putStrLn "Sort people alphabetically (lexicographically) by name:"
  print (sortBy compare people)

  putStrLn " "
  putStrLn "Sort people descending by age, where people of the same age should be sorted alphabetically (lexicographically):"
  print (sortBy compare2 people)