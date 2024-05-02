#include <iostream>
using namespace std;
struct tree
{
    tree *left;
    tree *right;
    string name, relation;
    int age;
};
tree *create_node()
{
    tree *temp, *root;
    temp = new tree;
    temp->left = NULL;
    temp->right = NULL;
    cout << "Enter name " << endl;
    cin >> temp->name;
    cout << "enter relation" << endl;
    cin >> temp->relation;
    cout << "enter age";
    cin >> temp->age;
    return temp;
}
tree *create()
{
    tree *temp, *root, *ptr;
    int ch;
    root = NULL;

    int dir;
    do
    {
        ptr = create_node();

        if (root == NULL)
        {
            root = ptr;
        }
        else
        {
            temp = root;
            while (temp != NULL)
            {
                cout << "Which direction you want to add(left=2/right=3)" << endl;
                cin >> dir;
                if (dir == 2)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = ptr;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = ptr;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
            }
        }
        cout << "you want to continue(1/0)";
        cin >> ch;
    } while (ch == 1);
    return (root);
}
void inorder_dis(tree *h)
{
    if (h == NULL)
    {
        return;
    }
    else
    {

        inorder_dis(h->left);
        cout << h->name << endl;
        cout << h->relation << endl;
        cout << h->age << endl;
        inorder_dis(h->right);
    }
}
void preorder_dis(tree *h)
{
    if (h == NULL)
    {
        return;
    }
    else
    {

        cout << h->name << endl;
        cout << h->relation << endl;
        cout << h->age << endl;
        preorder_dis(h->left);
        preorder_dis(h->right);
    }
}
void postorder_dis(tree *h)
{
    if (h == NULL)
    {
        return;
    }
    else
    {

        postorder_dis(h->left);

        postorder_dis(h->right);
        cout << h->name << endl;
        cout << h->relation << endl;
        cout << h->age << endl;
    }
}
tree *insert()
{
    tree *temp, *root, *ptr;
    int ch;
    root = NULL;

    int dir;
    do
    {
        ptr = create_node();

        if (root == NULL)
        {
            root = ptr;
        }
        else
        {
            temp = root;
            while (temp != NULL)
            {
                cout << "Which direction you want to add(left=2/right=3)" << endl;
                cin >> dir;
                if (dir == 2)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = ptr;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = ptr;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
            }
        }
        cout << "you want to continue(1/0)";
        cin >> ch;
    } while (ch == 1);
    return (root);
}
int main()
{
    tree *h;
    h = create();
    int ch, che;
    do
    {
        cout << "1.Preorder Display \n 2.Inorder Display \n 3.Postorder Display \n4.Insert" << endl;
        cout << "enter Your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "----------------------------------------------" << endl;
            cout << "Preorder Traversal" << endl;
            preorder_dis(h);

            break;
        case 2:
            cout << "----------------------------------------------" << endl;
            cout << "Inorder Traversal" << endl;
            inorder_dis(h);

            break;
        case 3:
            cout << "----------------------------------------------" << endl;
            cout << "postorder Traversal" << endl;
            postorder_dis(h);
            break;
            case 4:
            insert(h);
            break;
        }
        cout << "You  Want to continue(1/0)" << endl;
        cin >> che;
    } while (che == 1);

    return 0;
}