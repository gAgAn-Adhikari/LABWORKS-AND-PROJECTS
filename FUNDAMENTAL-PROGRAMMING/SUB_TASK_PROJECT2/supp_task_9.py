def print_menu():
    print('--------- Menu ----------')
    print('a) Add a new test subject')
    print('s) Show all information')
    print('r) Read from file')
    print('w) Write to file')
    print('p) get times')
    print('q) Quit')
    print('-------------------------')


def get_times(subjects):
    times=[]
    for _,time in subjects:
        times.append(time)
    return times

def new_test_subject():
    print('---- New Test ----')
    number = input('Number assigned to a test subject: ')
    time = int(input('Enter the time in minutes: '))
    return (number, time)

def write_data(test_subjects, filename):
    with open(filename, 'w') as f:
        for subject in test_subjects:
            f.write(subject[0] + '\n')
            f.write(str(subject[1]) + '\n')

def read_data(filename):
    test_subjects = []
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
            for i in range(0, len(lines), 2):
                number = lines[i].strip()
                time = int(lines[i+1].strip())
                test_subjects.append((number, time))
    except FileNotFoundError:
        print("*** File not found ***")
    return test_subjects

def print_test_subjects(test_subjects):
    print('---- Registered test subjects ----')
    for number, time in test_subjects:
        print(f"Number : {number:>4}")
        print(f"Time   : {time:>4}")
        print()

def main():
    test_subjects = []
    while True:
        print_menu()
        choice = input('Enter your choice: ').lower()
        if choice == 'a':
            subject = new_test_subject()
            test_subjects.append(subject)
        elif choice == 's':
            print_test_subjects(test_subjects)
        elif choice == 'r':
            filename = input('Enter the name of the file: ')
            test_subjects = read_data(filename)
            print("*** Data read from file ***")
        elif choice == 'w':
            filename = input('Enter your filename: ')
            write_data(test_subjects, filename)
            print("*** Data written to file ***")
        elif choice == 'p':
            times = get_times(test_subjects)
            print("Lap times:")
            for t in times:
                print(t)

        elif choice == 'q':
            break
        else:
            print('Invalid input, try again')

if __name__ == '__main__':
    main()