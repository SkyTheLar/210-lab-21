/****************************************

COMSC 210 | Lab 21 | Skylar Robinson | IDE Used: Eclipse

****************************************/

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20,
		  SIZE = 15, MAX_AG = 20, MIN_AG = 1;

class Goat {
private:
	int age;
	string name, color;
	string names[SIZE] = { "Johanna", "Micheal", "Mahadevi", "Minerva", "Rufus"
			               "Heilwig", "Gordana", "Vidar", "Iben", "Aminah"
						   "Amelia", "Magdalini", "Lina", "Tutgual", "Dex" };
	string colors[SIZE] = { "brown", "black", "white", "grey", "tan",
							"red", "yellow", "gold", "dark grey", "calico"
							"orange", "auburn", "maroon", "silver", "pink" };

public:
	//default constructor
	Goat() {
		age = (rand() % (MAX_AG - MIN_AG + 1)) + MIN_AG;
		name = names[rand() % SIZE];
		color = colors[rand() % SIZE];
	}

	//parameter instructor
	Goat(int a, string n, string c) {
		age = a;
		name = n;
		color = c;
	}

	//print funtion
	void print() {
		cout << name << " (" << color << ", " << age << endl;
	}
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(Goat value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) {
        	cout << "List is empty\n";
        	return;
        }
        while (current) {
            cout << current->data.print();
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data.print();
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
	srand(time(0));

    DoublyLinkedList list;


    return 0;
}
