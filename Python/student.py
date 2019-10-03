#!python3
import statistics
import readchar  # ----------------this needs to be installed----------------


class Student:
    def __init__(self, name, num):
        self.name = name
        self.num = num
        self.grades = dict()

    def add_grade(self, val, subject):
        self.grades[subject].append(val)

    def avg_grade(self, subject):
        print('Average grade for %s:' %
              subject, statistics.mean(self.grades[subject]))

    def add_subject(self, subject):
        if subject in self.grades:
            print('This subject already exists')
            return
        self.grades[subject] = []

    def print_grades(self, subject):
        print('%s: %s' % (subject, self.grades[subject]))


def input_subject(student):
    subject = input('Enter subject: ').strip().title()
    while(subject not in student.grades):
        subject = input(
            'This subject does not exists! Enter a valid subject: ').strip().title()
    return subject


def input_grade(student):
    grade = input('Enter a grade: ')
    while(not grade.isnumeric() or (int(grade) < 2 or int(grade) > 6)):  # error check
        grade = input('Please enter a valid grade: ')
    return int(grade)


def main():
    name = input('Name of student: ').title()
    num = input('Number of student: ')

    while(not num.isnumeric()):  # error check
        num = input('Please enter a number')
    num = int(num)

    student = Student(name, num)

    subjects = ['Math', 'English', 'Geography',
                'History', 'Chemistry', 'Biology', 'Physics']  # base subjects
    for subject in subjects:
        student.add_subject(subject)

    while(42):
        print('[Q]uit | Add [G]rade | Add [S]ubject | Get [A]verage For Subject | [P]rint grades: ',
              end='', flush=True)  # no newline
        operation = readchar.readchar().lower()
        print(operation)

        if operation == 'q':  # quit
            exit()

        elif operation == 'g':  # add grade
            subject = input_subject(student)
            grade = input_grade(student)

            student.add_grade(grade, subject)

        elif operation == 's':  # add subject
            subject = input_subject(student)
            student.add_subject(subject)

        elif operation == 'a':  # average grade
            subject = input_subject(student)
            student.avg_grade(subject)

        elif operation == 'p':  # print grades
            print('[A]ll or for One [S]ubject: ', end='', flush=True)
            op = readchar.readchar().lower()
            print(op)

            if op == 'a':  # print all subjects
                for subject in student.grades:
                    student.print_grades(subject)

            elif op == 's':  # print only one given subject
                subject = input_subject(student)
                student.print_grades(subject)

            else:
                print('Unknown operation. Try again')

        else:
            print('Unknown operation. Try again')


main()
