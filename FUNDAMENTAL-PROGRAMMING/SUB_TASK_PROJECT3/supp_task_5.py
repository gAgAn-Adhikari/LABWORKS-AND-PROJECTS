import pickle

def display_menu():
    print('-'*4 ,'Menu' ,'-'*4)
    print('1) Add suspect')
    print('2) Add accomplice')
    print('3) Display all suspects')
    print('4) Find potential accomplices')
    print('H) Has one accomplice')
    print('E) Exit')

def has_one_accomplice(graph):
    suspects = [suspect for suspect, accomplices in graph.items() if len(accomplices) == 1]
    if suspects:
        for suspect in suspects:
            print(suspect)
    else:
        print("INFO: There are no suspects with only one accomplice.")

def display_suspect(suspect,graph):
    print(f'{suspect}')
    for accomplice in graph.get(suspect,set()):
        print(f" {accomplice}")

def display_all_suspects(graph):
    print('---- All suspects ----')
    for suspect in graph:
        display_suspect(suspect,graph)


def find_potential_accomplices(suspect, graph):
    relation = set()
    direct = graph.get(suspect,set())
    for accomplice in direct:
        relation.update(graph(accomplice,set()))
    relation.discard(suspect)   
    relation -= direct
    return {suspect: relation}

def display_potential_accomplices(suspect, graph):
    print('---- Potential accomplices ----')
    print('Already known accomplices:')
    display_suspect(suspect,graph)
    print()
    print('Potential new accomplices:')
    relation = find_potential_accomplices(suspect,graph)
    display_suspect(suspect,relation)

def load_from_file(filename):
    with open(filename,'rb') as f:
        graph = pickle.load(f)
        print("*** Graph loaded from file. ***")
        return graph


def save_to_file(graph, filename):
    with open(filename, 'wb') as f:
        pickle.dump(graph, f)



    
def main():
    filename = input("Enter the filename to load the social graph: ").strip()
    graph = load_from_file(filename)

    while True:
        display_menu()
        choice = input("Choose an option: ").strip()

        if choice == '1':
            name = input("Enter suspect name: ").strip()
            if name not in graph:
                graph[name] = set()
                save_to_file(graph, filename)
        elif choice == '2':
            suspect = input("Enter suspect name: ").strip()
            accomplice = input("Enter accomplice name: ").strip()
            graph.setdefault(suspect, set()).add(accomplice)
            graph.setdefault(accomplice, set()).add(suspect)
            save_to_file(graph, filename)
        elif choice == '3':
            display_all_suspects(graph)
        elif choice == '4':
            suspect = input("Enter suspect name: ").strip()
            display_potential_accomplices(suspect, graph)
        elif choice.lower() == 'e':
            break
        elif choice.lower() == 'h':
            has_one_accomplice(graph)
        else:
            print("Invalid option. Please try again.")

if __name__ == '__main__':
    main()
