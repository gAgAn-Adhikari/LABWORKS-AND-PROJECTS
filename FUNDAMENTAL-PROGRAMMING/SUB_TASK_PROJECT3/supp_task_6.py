import pickle
from idlelib.configdialog import is_int
def display_menu():
    print('-'*4+" Menu "+'-'*4)
    print('1) Add suspect\n'
          '2) Add accomplice\n'
          '3) Display all suspects\n'
          '4) Find potential accomplices\n'
          'G) Generate Test graph\n'
          'E) Exit')

def generate_graph():
    social_graph = dict()
    social_graph["Alice"] = {"Bob","Charlie"}
    social_graph["Bob"] = {"Alice"}
    social_graph["Charlie"] = {"Alice"}
    return social_graph

def display_suspect(suspect,graph):
    print(f'{suspect}:')
    accomplices = graph.get(suspect,set())
    for accomplice in accomplices:
        print(f'    {accomplice}')

def display_all_suspects(graph):
    print("---- All suspects ----")
    for suspect in graph:
        display_suspect(suspect,graph)


def find_potential_accomplices(suspect, graph):
    potential_suspect = set()
    direct_suspect = graph.get(suspect,set())
    for accomplice in direct_suspect:
        potential_suspect.update(graph.get(accomplice,set()))
    potential_suspect.discard(suspect)
    potential_suspect -= direct_suspect
    potential_suspect_dictionary = {suspect:potential_suspect}
    return potential_suspect_dictionary

def display_potential_accomplices(suspect,graph):
    print("---- Potential accomplices ----")
    print("Already known accomplices:")
    display_suspect(suspect,graph)
    print()
    print("Potential new accomplices:")
    potential_accomplices = find_potential_accomplices(suspect, graph)
    display_suspect(suspect,potential_accomplices)

def load_from_file(filename):
    with open(filename,'rb') as file:
        graph = pickle.load(file)
    return graph

def save_to_file(graph,filename):
    with open(filename, 'wb') as file:
        pickle.dump(graph,file)


def main():
    graph = dict()
    filename = input("Enter file name: ")
    try:
        graph = load_from_file(filename)
        print("*** Graph loaded from file. ***")
    except FileNotFoundError :
        print("*** File not found. Starting with empty graph. ***")
        graph = dict()
    done = False
    while not done:
        display_menu()
        choice = input()

        if choice == '1':
            suspect = input("Enter suspect name: ")
            if suspect not in graph:
                graph[suspect] = set()
                save_to_file(graph,filename)

        elif choice =='2':
            suspect = input("Enter suspect name: ")
            accomplice = input("Enter accomplice name: ")
            if suspect not in graph:
                graph[suspect] = set()
            graph[suspect].add(accomplice)
            if accomplice not in graph:
                graph[accomplice] = set()
            graph[accomplice].add(suspect)
            save_to_file(graph,filename)

        elif choice =='3':
            display_all_suspects(graph)

        elif choice == '4':
            suspect = input("Enter suspect name: ")
            if suspect in graph:
                display_potential_accomplices(suspect,graph)
            else:
                print("Suspect not found")

        elif choice == "G":
            filename = "examination.ser"
            graph = generate_graph()
            save_to_file(graph,filename)

        elif str(choice).casefold() == 'e':
            done = True


if __name__ == '__main__':
    main()