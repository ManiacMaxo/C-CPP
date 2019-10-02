import statistics
import readchar  # ----------------please pip install----------------


class Student:
    def __init__(self, name, num_class):
        self.name = name
        self.num_class = num_class
        self.grades = dict()

    def add_grade(self, val, subject):
        if not subject in self.grades:
            print('Such a subject does not exist!\nIf you want to add it, press 1')
            if (readchar.readchar() == '1'):
                self.add_subject(subject)
            return
            # self.grades[subject] = []
        self.grades[subject].append(val)

    def avg_grade(self, subject):
        print('Average grade for %s:' %
              subject, statistics.mean(self.grades[subject]))

    def add_subject(self, subject):
        if subject in self.grades:
            print('This subject already exists')
            return
        self.grades[subject] = []


def main():
    name = input('Name of student: ')
    num_class = input('Number in class: ')
    student = Student(name, num_class)
    subjects = ['Math', 'English', 'Geography',
                'History', 'Chemistry', 'Biology', 'Physics']  # base subjects
    for subject in subjects:
        student.add_subject(subject)
    student.add_subject('Russian')
    student.add_grade(4, 'Russian')
    print(student.grades)


main()
