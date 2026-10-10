import pickle

def display_menu():
    print("---- Menu ----")
    print("1) Add suspect")
    print("2) Add accomplice")
    print("3) Display all suspects")
    print("4) Find potential accomplices")
    print('s) Statistics.')
    print("E) Exit")
def statistics(graph):
    suspects = len(graph)
    total_accomplices = 0
    for accomplices in graph.values():
        count = len(accomplices)
        total_accomplices += count

    if suspects > 0:
        avg = total_accomplices / suspects
        print(f"Total number of suspects : {suspects}")
        print(f"Number of accomplices on average : {avg:.1f}")
    else:
        print("No suspects in the graph.")


def display_suspect(suspect, graph):
    print(f"{suspect}:")
    for accomplice in graph.get(suspect, set()):
        print(f"    {accomplice}")

def display_all_suspects(graph):
    print("---- All suspects ----")
    for suspect in graph:
        display_suspect(suspect, graph)

def find_potential_accomplices(suspect, graph):
    potential = set()
    direct = graph.get(suspect, set())
    for accomplice in direct:
        potential.update(graph.get(accomplice, set()))
    potential.discard(suspect)
    potential -= direct
    return {suspect: potential}

def display_potential_accomplices(suspect, graph):
    print("---- Potential accomplices ----")
    print("Already known accomplices:")
    display_suspect(suspect, graph)
    print()
    print("Potential new accomplices:")
    potential = find_potential_accomplices(suspect, graph)
    display_suspect(suspect, potential)

def load_from_file(filename):
    try:
        with open(filename, 'rb') as f:
            graph = pickle.load(f)
        print("*** Graph loaded from file. ***")
        return graph
    except FileNotFoundError:
        print("*** File not found. Starting with empty graph. ***")
        return {}

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
        elif choice.lower() == 's':
            statistics(graph)
        elif choice.lower() == 'e':
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == '__main__':
    main()