#include <iostream>
using namespace std;

#define MAX 10

struct node {
    int id;
    string name, history, disease, t_plan[MAX];
};

class HashTable {
    node p[MAX];

public:
    HashTable() {
      
        for (int i = 0; i < MAX; i++) {
            p[i].id = -1;
        }
    }

    void insert();
    void search(int id);
    void deleter(int id);
    void display();
};

void HashTable::insert() {
    node newPatient;
    cout<<"Max 10 records can be inserted \n";

    cout << "Enter the patient id: ";
    cin >> newPatient.id;

    cout << "Enter the Patient Name: ";
    cin >> newPatient.name;

    cout << "Enter the medical history of patient: ";
    cin >> newPatient.history;

    cout << "Enter the disease of the patient: ";
    cin >> newPatient.disease;

    cout << "Enter the treatment plan for the patient: ";
    cin >> newPatient.t_plan[0]; 

    int b = newPatient.id % MAX;

    while (p[b].id != -1) {
        cout << "Collision occurred at position " << b << ". ";
        b = (b + 1) % MAX; 
    }

    p[b] = newPatient; 
    cout << "Patient " << newPatient.name << " inserted at position " << b << "." << endl;
}

void HashTable::search(int id) {
    int b = id % MAX;
    int initial_b = b;


    while (p[b].id != id && p[b].id != -1) {
        b = (b + 1) % MAX;

        if (b == initial_b) {
            cout << "Patient with ID " << id << " not found." << endl;
            return;
        }
    }

    if (p[b].id == id) {
        cout << "Patient found at position " << b << ":" << endl;
        cout << "ID: " << p[b].id << endl;
        cout << "Name: " << p[b].name << endl;
        cout << "Disease: " << p[b].disease << endl;
        cout << "History: " << p[b].history << endl;
        cout << "Treatment Plan: " << p[b].t_plan[0] << endl;
    } else {
        cout << "Patient with ID " << id << " not found." << endl;
    }
}

void HashTable::deleter(int id) {
    int b = id % MAX;
    int initial_b = b;

    while (p[b].id != id && p[b].id != -1) {
        b = (b + 1) % MAX;
       
        if (b == initial_b) {
            cout << "Patient with ID " << id << " not found." << endl;
            return;
        }
    }

    if (p[b].id == id) {
        p[b].id = -1; 
        cout << "Patient with ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Patient with ID " << id << " not found." << endl;
    }
}

void HashTable::display() {
    cout << "\nPatients in the Hash Table:" << endl;
    cout << "Index\tID\tName\tDisease\tHistory\tTreatment Plan" << endl;
    for (int i = 0; i < MAX; i++) {
        if (p[i].id != -1) {
            cout << i << "\t" << p[i].id << "\t" << p[i].name << "\t" << p[i].disease << "\t" << p[i].history << "\t" << p[i].t_plan[0] << endl;
        } else {
            cout << i << "\tEMPTY" << endl; 
        }
    }
}

int main() {
    HashTable h;
    int choice, id;

    do {
        cout << "\n1. Insert a Patient" << endl;
        cout << "2. Search for a Patient" << endl;
        cout << "3. Delete a Patient" << endl;
        cout << "4. Display all Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                cout << "Enter the ID of the patient you want to search: ";
                cin >> id;
                h.search(id);
                break;
            case 3:
                cout << "Enter the ID of the patient you want to delete: ";
                cin >> id;
                h.deleter(id);
                break;
            case 4:
                h.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
