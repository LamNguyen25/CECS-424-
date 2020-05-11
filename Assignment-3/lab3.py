from operator import attrgetter

# Sorting a list of integers
arr_int = [5, 35, 1, 0, -45, 23, 12, 78, 435]
arr_int.sort()
print(arr_int)

# Sorting a list of floats
arr_float = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
arr_float.sort()
print(arr_float)

# Sorting a list of strings
arr_str = ["apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant"]
arr_str.sort()
print(arr_str)
print("\n\n")
# Sorting a list of Person
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return str(self.name) + ", " + str(self.age)
person_list = [ Person("Hal", 20),
				Person("Susann", 31),
        		Person("Dwight", 19), 
				Person("Kassandra",21),
				Person("Lawrence", 25),
				Person("Cindy", 22),
				Person("Cory", 27),
				Person("Mac", 19),
				Person("Romana", 27),
				Person("Doretha", 32),
				Person("Danna", 20),
			    Person("Zara", 23),
				Person("Rosalyn", 26),
				Person("Risa", 24),
				Person("Benny", 28),
				Person("Juan", 33),
				Person("Natalie", 25)]

# Sort people alphabetically (lexicographically) by name
person_list.sort(key=lambda Person: Person.name)
for person in person_list: print(person.name, person.age)

# Sort people descending by age, where people of the same age should be sorted alphabetically:
print('Sort people descending by age, where people of the same age should be sorted alphabetically:')
person_list = sorted(person_list, key=attrgetter('name'))
person_list = sorted(person_list, key=attrgetter('age'), reverse=True)
for person in person_list: print(person.name, person.age)
