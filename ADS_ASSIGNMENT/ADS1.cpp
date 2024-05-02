#include "iostream"
using namespace std;
const int max_node = 10;
struct node
{
    int book_no = -1;
    string title;
    string author;
    string isbn;
    int availability_stat;
    int next = 0;
};
node a[max_node];
int create()
{
    int head, i;
    cout << "Enter index of first node: ";
    cin >> i;
    head = i;
    while (i != 0)
    {
        cout << "Enter book number : " << endl;
        cin >> a[i].book_no;
        cout << endl;
        cout << "Enter Title of the Book : ";
        cin >> a[i].title;
        cout << endl;
        cout << "Enter Author : ";
        cin >> a[i].author;
        cout << "Enter ISBN : ";
        cin >> a[i].isbn;
        cout << endl;
        cout << "Enter availability status : ";
        cin >> a[i].availability_stat;
        cout << endl;
        cout << "Enter index of next book(press 0 to stop) : ";
        cin >> a[i].next;
        cout << endl;
        i = a[i].next;
    }
    return head;
}
void display_search(int head)
{
    cout << "\n\nBook No\t|\tTitle\t|\tAuthor\t|\tISBN\t| Availability\t|\tbook pos.\t|\n\n";
    cout << "--------------------------------------------------------------------------\n";
    int i = head;
    cout << a[i].book_no << "\t|\t" << a[i].title << "\t|\t" << a[i].author << "\t|\t" << a[i].isbn << "\t|\t" << a[i].availability_stat << i << "\t|\n";
}
void display(int head)
{
    int i = head;
    cout << "\n\ncount\t|\tBook No\t|\tTitle\t|\tAuthor\t|\tISBN\t| Availability\t|  book pos.\t|  next\n\n ";
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    int count = 1;
    while (i != 0)
    {
        if (a[i].book_no != -1)
        {
            cout << count << "\t|\t" << a[i].book_no << "\t|\t" << a[i].title << "\t|\t" << a[i].author << "\t|\t" << a[i].isbn << "\t|\t" << a[i].availability_stat << "\t|\t" << i << "\t|\t" << a[i].next << "\t|\n ";
        }
        count++;
        i = a[i].next;
    }
    cout << "NULL" << endl;
}
void insert()
{
    int new_book_no, temp;
    string new_title, new_author, new_isbn;
    int new_availability_stat;

    cout << "Enter book number : " << endl;
    cin >> new_book_no;
    cout << endl;
    cout << "Enter Title of the Book : ";
    cin >> new_title;
    cout << endl;
    cout << "Enter Author : ";
    cin >> new_author;
    cout << "Enter ISBN : ";
    cin >> new_isbn;
    cout << endl;
    cout << "Enter availability status : ";
    cin >> new_availability_stat;
    cout << endl;
    cout << "Enter book_no after which you want to insert: ";
    cin >> temp;
    for (int i = 0; i < max_node; i++)
    {
        if (a[i].book_no == temp)
        {
            for (int j = i + 1; j < max_node; j++)
            {
                if (a[j].book_no == -1)
                {
                    a[j].book_no = new_book_no;
                    a[j].title = new_title;
                    a[j].author = new_author;
                    a[j].isbn = new_isbn;
                    a[j].availability_stat = new_availability_stat;
                    a[j].next = a[i].next;
                    a[i].next = j;
                    return;
                }
            }
        }
    }
    cout << "Element not found" << endl;
}
int delete_data(int head)
{
    int temp;
    cout << "Enter book_no number you want to delete : ";
    cin >> temp;
    int prev = 0;
    int current = head;
    if (a[current].book_no == temp)
    {
        a[current].book_no = -1;
        head = a[current].next;
    }
    while (current != 0)
    {
        prev = current;
        current = a[current].next;
        if (a[current].book_no == temp)
        {
            a[current].book_no = -1;
            a[prev].next = a[current].next;
            a[current].next = 0;
            return 0;
        }
    }
    cout << "Element not found";
    return head;
}

void search(int head)
{
    int val;
    cout << "Enter element you want to find: ";
    cin >> val;
    int i = head;
    bool flag = true;
    while (i != 0)
    {
        if (a[i].book_no == val)
        {
            cout << "book_no found" << endl;
            display_search(i);
            flag = false;
        }
        i = a[i].next;
    }
    if (flag == true)
    {
        cout << "book_no not found";
    }
}
int main()
{
    int head = create();
    cout << " Library Created... " << endl;
    int ch;
    do
    {
        cout << "Menu\n1)insert\n2)display\n3)delete_book_no\n4)search\n5)exit\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display(head);
            break;
        case 3:
            delete_data(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            exit(0);
        }
        cout << "\ndo you want to continue(1/0) : ";
        cin >> ch;
    } while (ch == 1);
    return 0;
}