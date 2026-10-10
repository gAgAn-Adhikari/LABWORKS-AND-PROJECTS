shopping_list = [] 
title = input('Enter the Name for your Shopping List : ')

while True:
    print('1. Add an item')
    print('2. Print currently added items')
    print('3. Finished')
    choice = input('enter your choice : ')
    
    if choice == '1':
        item = input('Enter the name of the item : ')
        shopping_list.append(item)
    elif choice == '2':
        if shopping_list:
            print("Currently added items:")
            print('\n'.join(shopping_list))
    elif choice == '3':
        break
    else:
        print('Error: Invalid choice, please try again.')

print('-'*20)
print(title.center(20))
print('-'*20)
print('\n'.join(shopping_list), end='')



# title = input("Enter the title: ")
# item_list = ""

# def menu():
#     print("")
#     print("1. Add an item")
#     print("2. Print currently added items")
#     print("3. Finished")


# while True:
#     menu()
#     choice = input("\nEnter your choice: ")

#     if choice == "1":
#         item = input("Enter an item: ") 
#         item_list += item + "\n"
#     elif choice == "2":
#         print("Currently added items:")
#         print(item_list)
#     elif choice == "3":
#         print("--------------------")
#         print(f"{title[:20]:^20}")
#         print("--------------------")
#         print(item_list)
#         break
#     else: 
#         print("Error: Invalid choice, please try again.")
