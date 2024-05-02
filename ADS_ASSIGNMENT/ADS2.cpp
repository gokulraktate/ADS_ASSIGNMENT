// A Music Library System is a software application used to manage the storage and retrieval of music
// tracks and albums. System need to maintain information such as track title, artist, album, genre,
// duration, release year, and any other relevant attributes. System should able to add new music track,
// remove the track, update the information of the track, search the specific track also it should display
// the information of all the track which are present in the database. Use the Concept of Circular Linked
// list to implement the above system
#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
    string genre;
    string artist;
    string title_track, album;
    long int duration;
    long int release_year;
};

node *get_node()
{
    node *temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}

node *getdata(node *New)
{

    cout << "Enter the name of artist\n";
    cin >> New->artist;
    cout << endl;

    cout << "Enter the name of album\n";
    cin >> New->album;
    cout << endl;

    cout << "Enter the name of genre\n";
    cin >> New->genre;
    cout << endl;

    cout << "Enter the name of title track\n";
    cin >> New->title_track;
    cout << endl;

    cout << "Enter the duration(In seconds)\n";
    cin >> New->duration;
    cout << endl;

    cout << "Enter the release year\n";
    cin >> New->release_year;
    cout << endl;

    return New;
}
node *create()
{
    node *temp, *New, *head;
    bool flag = true;
    int ans;
    temp = NULL;

    do
    {
        New = get_node();
        if (New == NULL)
        {
            cout << "Memory not allocated..\n";
        }

        else
        {
            New = getdata(New);
        }
        if (flag == true)
        {
            head = New;
            New->next = head;
            temp = head;
            flag = false;
        }
        else
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
        cout << "Do you want to continue (1 or 0)\n";
        cin >> ans;
    } while (ans == 1);
    cout << "Music library list Created..\n";
    return head;
}

void display(node *head)
{
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Music library List is empty..\n";
        return;
    }
    else
    {
        cout << "Artist\t\tTitle_Track\tAlbum\tGenre\tDuration\tRelease_Year\t\n";
        do
        {

            cout << temp->artist << "\t\t" << temp->title_track << "\t\t"
                 << temp->album << "\t" << temp->genre << "\t"
                 << temp->duration << "\t\t" << temp->release_year << "\t\n";

            temp = temp->next;
        } while (temp != head);
    }
}

node *insert_at_head(node *head)
{
    node *temp, *New = get_node();

    if (New == NULL)
    {   
        cout << "Memory not allocated..\n";
        return head;
    }
    New = getdata(New);

    if (head == NULL)
    {
        cout << "Music list is empty.\n";
        head = New;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
        head = New;
        cout << "Music head list updated..\n";
        cout << endl;

        return head;
    }
    return head;
}

void insert_at_tail(node *head)
{
    node *temp = NULL, *New = get_node();
    New = getdata(New);
    temp = head;
    if (temp == NULL)
    {
        cout << "The Music list is empty\n";
        cout << "Inserting data at head node..\n";
        head = New;
    }

    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = head;
        cout << "Inserted at tail node..\n";
        cout << endl;
    }
}

node *insert_at_specific_node(node *head)
{
    node *New, *temp = head;
    string key;

    New = get_node();
    cout << "Enter after which artist name you want to insert.\n";
    cin >> key;
    New = getdata(New);

    if (New == NULL)
    {
        cout << "Music list is empty";
        return head;
    }

    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        temp = head;

        while (temp->artist != key)
        {
            temp = temp->next;
        }
        New->next = temp->next;
        temp->next = New;
    }
    return head;
}

node *delete_at_specific_node(node *head)
{
    node *temp = head, *prev = NULL;
    string del;
    bool found = false;

    cout << "Enter the name of artist to delete\n";
    cin >> del;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return NULL;
    }
    do
    {
        if (temp->artist == del)
        {
            if (prev == NULL)
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
            }
            cout << "Artist record deleted." << endl;
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (!found)
    {
        cout << "Artist record not found." << endl;
    }
    return head;
}
node *update_data(node *head)
{
    node *New;
    string val;
    cout << "Enter artist name to update : ";
    cin >> val;
    node *temp = head;
    if (head == NULL)
    {
        cout << "Music list is empty, Cannot search." << endl;
    }
    do
    {
        if (temp->artist == val)
        {

            cout << "Enter the name of artist\n";
            cin >> New->artist;
            cout << endl;

            cout << "Enter the name of album\n";
            cin >> New->album;
            cout << endl;

            cout << "Enter the name of genre\n";
            cin >> New->genre;
            cout << endl;

            cout << "Enter the name of title track\n";
            cin >> New->title_track;
            cout << endl;

            cout << "Enter the duration(In seconds)\n";
            cin >> New->duration;
            cout << endl;
        }
        temp = temp->next;
    } while (temp != head);
}

node *search_data(node *head)
{
    node *temp;
    string search;
    cout << "Enter the name of artist to search\n";
    cin >> search;
    temp = head;
    if (head == NULL)
    {
        cout << "Music list is empty, Cannot search." << endl;
        return NULL;
    }

    else
    {
        cout << "Data found..\n";

        cout << "Artist\t\tTitle_Track\tAlbum\tGenre\tDuration\tRelease_Year\t\n";
        do
        {

            cout << temp->artist << "\t\t" << temp->title_track << "\t\t"
                 << temp->album << "\t" << temp->genre << "\t"
                 << temp->duration << "\t\t" << temp->release_year << "\t\n";

            temp = temp->next;
        } while (temp != head);
    }
}

int main(void)
{
    node *head = create();
    int ch;
    int choice;

    do
    {
        cout << "----Menu---\n";
        cout << "1.Insert at Head\n";
        cout << "2.Insert at Tail\n";
        cout << "3.Display\n";
        cout << "4.Insert after specific node\n";
        cout << "5.Delete after specific node\n";
        cout << "6.Search Data\n";
        cout << "7.Update Data\n";
        cout << "Enter your choice\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            head = insert_at_head(head);
            break;

        case 2:
            insert_at_tail(head);
            break;

        case 3:
            display(head);
            break;
        case 4:
            head = insert_at_specific_node(head);
            break;
        case 5:
            head = delete_at_specific_node(head);
            break;
        case 6:
            search_data(head);
            break;
        case 7:
            head = update_data(head);
            break;
        default:
            cout << "Invalid data\n";
            break;
        }
        cout << "Do you want to continue(1/0)\n";
        cin >> choice;
    } while (choice == 1);
}