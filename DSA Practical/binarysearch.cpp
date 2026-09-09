#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

//Function To create a binary tree
Node *root = NULL;
class Tree
{
public:

    // Function to insert a node
    void insert(Node *&temp, int value)
    {
        if (temp == NULL)
        {
            temp=new Node;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
        }

        // Insert in left subtree first
        if (temp->left == NULL)
        {
            insert(temp->left, value);
        }
        else
        {
            insert(temp->right, value);
        }
    }

    // Function to create binary tree
    void createTree()
    {
        int value;

        while (true)
        {
            cin>>value;

            if(value == -1)
                break;
            insert(root, value);
        }
    }

    // Inorder Traversal
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder Traversal
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout<<temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
};

int main()
{
    Tree t;
    int choice, value;

    do
    {
        cout<<"\n===== Binary Tree Menu =====\n";
        cout<<"\n1. Create Binary Tree";
        cout<<"\n2. Insert Node";
        cout<<"\n3. Inorder Traversal";
        cout<<"\n4. Preorder Traversal";
        cout<<"\n5. Postorder Traversal";
        cout<<"\n6. Exit";

        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout <<"\nEnter values (-1 to stop): " << endl;
            t.createTree();
            break;

        case 2:
            cout << "\nEnter value: ";
            cin >> value;

            if (value == -1)
            {
                cout<<"\nInvalid value!";
            }
            else
            {
                t.insert(root, value);
                cout<<"\nNode inserted successfully!";
            }
            break;

        case 3:
            if (root == NULL)
            {
                cout<<"\nTree is empty!";
            }
            else
            {
                cout<<"\nInorder Traversal: ";
                t.inorder(root);
                cout<<endl;
            }
            break;

        case 4:
            if (root == NULL)
            {
                cout<<"\nTree is empty!";
            }
            else
            {
                cout<<"\nPreorder Traversal: ";
                t.preorder(root);
                cout<<endl;
            }
            break;

        case 5:
            if (root == NULL)
            {
                cout<<"\nTree is empty!";
            }
            else
            {
                cout<<"\nPostorder Traversal: ";
                t.postorder(root);
                cout<<endl;
            }
            break;

        case 6:
            cout<<"\nProgram Exited.";
            break;

        default:
            cout<<"\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}
