class Address:
    def __init__(self, street, city, number):
        self.__street = street
        self.__city = city
        self.__number = number
        print(number)


class Person:
    def __init__(self, name, street, city, number):
        self.__name = name
        self.__address = Address(street, city, number)


class Markbook:
    __grades = {}

    def add_mark(self, subject, mark):
        if subject not in self.__grades:
            self.__grades[subject] = list([])
        self.__grades[subject].append(mark)

    def get_marks(self, subject):
        self.__grades[subject]
        

    def get_average(self, subject):
        return sum(self.__grades[subject]) / len(self.__grades[subject])


class Computer:
    def __init__(self, brand, model, year, os, cpu, ram, memory):
        self.__brand = brand
        self.__model = model
        self.__year = year
        self.__cpu = cpu
        self.__ram = ram
        self.__memory = memory


class Student(Person):
    def __init__(self):
        self.number = input('Enter number of student: ')
