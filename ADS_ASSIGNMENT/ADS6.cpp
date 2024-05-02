#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class Hash {
private:
    struct Song {
        int song_id;
        string song_name;
        string singer;
        string track;
        string album;
        Song* next;
    };

    Song* ht[MAX];

public:
    Hash() {
        for (int i = 0; i < MAX; i++)
            ht[i] = nullptr;
    }

    void display();
    void insert();
    void search();
    void deleter();
};

void Hash::display() {
    cout << "\nMusic Library" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Index\tSong ID\tSinger\tSong Name\tTrack\tAlbum" << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < MAX; i++) {
        Song* current = ht[i];
        if (current == nullptr) {
            cout << i << "::\tEmpty" << endl;
        } else {
            cout << i << "\t";
            while (current != nullptr) {
                cout << current->song_id << "\t";
                cout << current->singer << "\t";
                cout << current->song_name << "\t";
                cout << current->track << "\t";
                cout << current->album << endl;
                if (current->next != nullptr)
                    cout << "\t\t";
                current = current->next;
            }
        }
    }
}

void Hash::insert() {
    Song* newSong = new Song;
    cout << "Enter Song ID: ";
    cin >> newSong->song_id;
    cout << "Enter Singer: ";
    cin >> newSong->singer;
    cout << "Enter Song Name: ";
    cin >> newSong->song_name;
    cout << "Enter Track: ";
    cin >> newSong->track;
    cout << "Enter Album: ";
    cin >> newSong->album;

    int hashValue = newSong->song_id % MAX;
    if (ht[hashValue] == nullptr) {
        ht[hashValue] = newSong;
    } else {
        Song* current = ht[hashValue];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newSong;
    }
}

void Hash::search() {
    int id;
    cout << "Enter the Song ID to search: ";
    cin >> id;

    int hashValue = id % MAX;
    Song* current = ht[hashValue];
    while (current != nullptr) {
        if (current->song_id == id) {
            cout << "Song Found:" << endl;
            cout << "Song ID: " << current->song_id << endl;
            cout << "Singer: " << current->singer << endl;
            cout << "Song Name: " << current->song_name << endl;
            cout << "Track: " << current->track << endl;
            cout << "Album: " << current->album << endl;
            return;
        }
        current = current->next;
    }
    cout << "Song not found." << endl;
}

void Hash::deleter() {
    int id;
    cout << "Enter the Song ID to delete: ";
    cin >> id;

    int hashValue = id % MAX;
    Song* current = ht[hashValue];
    Song* prev = nullptr;

    while (current != nullptr && current->song_id != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Song not found." << endl;
        return;
    }

    if (prev == nullptr) {
        ht[hashValue] = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    cout << "Song deleted successfully." << endl;
}

int main() {
    Hash musicLibrary;

    int choice;
    while (true) {
        cout << "\n---------------------------------" << endl;
        cout << "Music Library Management System" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Insert Song" << endl;
        cout << "2. Search Song" << endl;
        cout << "3. Delete Song" << endl;
        cout << "4. Display Library" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                musicLibrary.insert();
                break;
            case 2:
                musicLibrary.search();
                break;
            case 3:
                musicLibrary.deleter();
                break;
            case 4:
                musicLibrary.display();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
