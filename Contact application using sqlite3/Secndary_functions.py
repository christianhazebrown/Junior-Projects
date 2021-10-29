import os
import Database as D
import time
def setup():
    #prints the menu
    print('==========Contact Menu==========\n'
          'What would you like to do?\n'
          '  1: Create new contact\n'
          '  2: Update contact\n'
          '  3: Delete contact\n'
          '  4: Search for contact\n'
          '  5: List all contacts\n'
          '  6: END PROGRAM')
    #collects the user choice
    choice = input_choice()
    #takes the users choice and calls the corresponding function
    results = choice_call(choice)
    return results

#function used to gather user choice and make sure the entered value is correct
def input_choice():
    while True:
        #get user input test if input is valid 1-6 and is integer
        try:
            choice = int(input('Choice: '))
        except ValueError:
            print("Value error! Please enter integer")
        else:
            if 0 < int(choice) < 7:
                break
            else:
                print("Please enter a valid choice(Between 0-6).")
    return choice
#function to switch user input of choice
def choice_call(choice):
    os.system('cls')
    if choice == 1:
        create_contact()
    elif choice == 2:
        update_contact()
    elif choice == 3:
        delete_contact()
    elif choice == 4:
        search_contact()
    elif choice == 5:
        list_all_contacts()
    elif choice == 6:
        return False

#function takes user input for data entry then checks if it correct format if not then corrects it
def entry():
    number = []
    n = input("Enter number:")

    for i in range(len(n)):
        number.append(n[i])

    while True:
        try:
            for i in range(len(number)):
                if type(int(number[i])) == int:
                    continue
        except:
            print(number[i])
            if number[i] != '(' and number[i] != ')' and number[i] != '-':
                print('Unknown input', number[i])
                entry()
        number = correct_entry(number)
        return number


def correct_entry(number):
    location = 0
    if "(" in number and ")" in number:
        for i in range(len(number)):
            if number[i] == '(':
                location = i
                if location != 0:
                    number.pop(location)
                    number.insert(0, '(')
            if number[i] == ')':
                location = i
                if location != 0:
                    number.pop(location)
                    number.insert(4, ')')

    if "(" in number or ")" in number:
        if '(' not in number:
            number.insert(0, '(')
        else:
            for i in range(len(number)):
                if number[i] == '(':
                    location = i
                    if location != 0:
                        number.pop(location)
                        number.insert(0, '(')
        if ')' not in number:
            number.insert(4, ')')
        else:
            for i in range(len(number)):
                if number[i] == ')':
                    location = i
                    if location != 0:
                        number.pop(location)
                        number.insert(4, ')')

    else:
        number.insert(0, '(')
        number.insert(4, ')')
    # check for - char and if found find loctaion and remove if in wrong index then inster into right index

    if '-' in number:
        for i in range(0, 6):
            if number[i] == '-':
                location = i
                print(number, "1")
                if location != 5:
                    number.pop(location)
                    number.insert(5, '-')

        for i in range(6, len(number)):
            if number[i] == '-':
                location = i
                if location != 9:
                    number.pop(location)
                    number.insert(9, '-')
    # check for - char and if not found insert
    else:
        number.insert(5, '-')
        number.insert(9, '-')
    return number


#funtion for create contact
def create_contact():
    print("=========Create contact==========")
    name = input('Enter the name of the contact: ')
    number = entry()
    number = "".join(number)
    D.data_entry(name, number)
    print(name, "has been added to database")
    time.sleep(3)
    setup()


def update_contact ():
    print("==========Update contact==========")
    name = input("Please enter the name of the contact you are looking to updater: ")
    number = entry()
    number = "".join(number)
    results = D.update_contact(name.upper(), number)
    if results == True:
        print("Contact", name, "Has been updated")
    else:
        print("The contact", name, "was not found")
    time.sleep(3)
    setup()
def delete_contact():
    print("==========Delete contact==========")
    name = input("Please enter the name of the contact you are looking for: ")
    results = D.delete_contact(name.upper())
    if results == True:
        print("Contact", name, "Has been deleted")
    else:
        print("The contact", name, "was not found")
    time.sleep(3)
    setup()


def search_contact():
    print("==========Search contact==========")
    name = input("Please enter the name of the contact you are looking for: ")
    results = D.data_retrive(name.upper())
    if results == False:
        print("That contact was not found")
    else:
        print(name,"contact is", results)
    time.sleep(3)
    setup()



def list_all_contacts():
    print("==========List all contacts==========")
    D.list_all()
    time.sleep(3)
    setup()

