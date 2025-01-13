#include <iostream>
using namespace std;

struct node 
{
    char name[20];
    node* child[20]; 
    int tchapters;     
};

class GT 
{

    public:
    node* root;

    GT()
    {
        root = NULL;
    }

    node* create() 
    {
        root = new node;  
        cout << "Enter the name of the book: ";
        cin >> root->name;

        cout << "\nEnter the number of chapters: ";
        cin >> root->tchapters;

        for (int i = 0; i < root->tchapters; i++) 
        {
            root->child[i] = new node; 
            cout << "Enter the name of chapter: ";
            cin >> root->child[i]->name;

            cout << "\nEnter the number of sections in chapter: ";
            cin >> root->child[i]->tchapters;

            for (int j = 0; j < root->child[i]->tchapters; j++) 
            {
                root->child[i]->child[j] = new node; 
                cout << "Enter the name of section: ";
                cin >> root->child[i]->child[j]->name;

                cout << "\nEnter the number of subsections in section: ";
                cin >> root->child[i]->child[j]->tchapters;

                for (int k = 0; k < root->child[i]->child[j]->tchapters; k++) 
                {
                    root->child[i]->child[j]->child[k] = new node;  
                    cout << "Enter the name of subsection: ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
        return root;
    }

    void display(node* r1) 
    {
        if (r1 == NULL) 
        {
            cout << "Create a tree first!" << endl;
            return;
        }

        cout << "\n.............BOOK HIERARCHY............." << endl;
        cout << "\nName of the book is: " << r1->name;

        for (int i = 0; i < r1->tchapters; i++) 
        {
            cout<<endl;
            cout << "\n  Chapter: " << r1->child[i]->name;

            for (int j = 0; j < r1->child[i]->tchapters; j++) 
            {
                cout << "\n    Section: " << r1->child[i]->child[j]->name;

                for (int k = 0; k < r1->child[i]->child[j]->tchapters; k++) 
                {
                    cout << "\n      Subsection: " << r1->child[i]->child[j]->child[k]->name;
                }
            }
        }
        cout<<endl;
    }
};

int main() 
{
    GT obj;
    node* p;
    int choice;

    do 
    {
        cout << "\n1.CREATE  \n2.DISPLAY  \n3.EXIT " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
        
        case 1:
            p = obj.create();
            break;

        case 2:
            obj.display(p);
            break;

        case 3:
            cout << "\nEXITING...." << endl;
            break;

        default:
            cout << "Please Enter a valid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}

