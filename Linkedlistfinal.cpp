#include <iostream>
using namespace std;
class Node 
{
	public:
    int data;
    Node* next;
}*header=NULL;

void insertion_at_end()
{
    Node *nw, *t;
    nw = new Node;
    cout << "Enter the number: ";
    cin >> nw->data;
    nw->next = NULL;
    
    if (header == NULL) // list empty aahnengil
     {  
        header = nw;
    } 
    else // list empty allengil
    {
        t = header;
        while (t->next != NULL) 
        {  
            t = t->next;
        }
        t->next = nw;  
    }
}

void insertion_at_beginning()
{
    Node *nw;
    nw = new Node;
    cout << "Enter the number: ";
    cin >> nw->data;
    nw->next = header;
    header = nw;
    
}

void insert_at_location()
{
    Node *nw, *t;
    int loc, i;
    nw = new Node;
    cout << "Enter the number: ";
    cin >> nw->data;
    nw->next = NULL;
    cout << "Enter the location: ";
    cin >> loc;
    if (loc == 1) //extra code to insert at beginning
    {
        nw->next = header;
        header = nw;
    }
    else 
    {
        t = header;
        for (i = 1; i < loc-1; i++) /* delete cheyyanda location nu thotu
        munbatha location ethhaan  */
        {
            if (t == NULL)
            {
                cout << "This location is not there in this list";
                return;
            }
            t = t->next;
        }
        nw->next = t->next;
        t->next = nw;
    }
}
void display()
{
    Node *t = header;
    if (t == NULL)
    {
        cout << "The list is empty.";
        return;
    }
    while (t != NULL) 
    {
        cout << t->data << "\n";
        t = t->next;
    }
}
void search()
{
    Node *t = header;
    int ele, i = 1;
    cout << "Enter the number to be searched: ";
    cin >> ele;
    while (t != NULL) //a variable i is used to keep track of the location of the number
    {
        if (t->data == ele) //if the number is found
        {
            cout << "The number is found at location " << i;
            return; //function ill ninn exit aavan
        }
        t = t->next;
        i++;
    }
    cout << "The number is not found in the list";
}
void delete_at_beginning()
{
    Node *t;
    if (header == NULL) // list empty aahnengil
    {
        cout << "The list is empty.";
        return;
    }
    t = header;
    header = header->next;
    delete t;
}

void delete_at_end()

{
    if (header == NULL) // list empty aahnengil
    {
        cout << "The list is empty.";
        return;
    }

    if (header->next == NULL) // listil oru node undengil
    {
        delete header;
        header = NULL;
        return;
    }

    Node *t = header;
    while (t->next->next != NULL) // to reach the second last node
    {
        t = t->next;
    }

    delete t->next;
    t->next = NULL;
}

void delete_at_location()
{
    Node *t, *temp;
    int loc, i;
    cout << "Enter the location: ";
    cin >> loc;
    if(loc<1) //if the location is invalid
    {
    	cout<<"Invalid location";
    	return;
    }
    if (header == NULL) // list empty aahnengil
    {
        cout << "The list is empty.";
        return;
    }
    if (loc == 1) //extra code to delete at beginning, already cheyytheya
    {
        t = header;
        header = header->next;
        delete t;
    }
    else
    {
        t = header;
        for (i = 1; i < loc-1; i++) //same as insert at location
        {
            if (t == NULL)
            {
                cout << "This location is not there in this list";
                return;
            }
            t = t->next;
        }
        if (t->next == NULL) //if the location is not there
        {
            cout << "This location is not there in this list";
            return;
        }
        temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

int main()
{
	int a,b,c;
	char d;
	do
	{
	cout<<"\t\t\tMENU\t\t\t"<<"\n";
	cout<<"1.Insertion"<<"\n"<<"2.Deletion"<<"\n"<<"3.Display"<<"\n"<<"4.Search"<<"\n"<<"5.Exit"<<"\n";
	cout<<"Enter your choice";
	cin>>a;
	switch(a)
	{
		case 1 : cout<<"Where do you want to insert?";
		cout<<"1.Insert at beginning"<<"\n"<<"2.Insert at end"<<"\n"<<"3.Insert at specific location"<<"\n";
		cin>>b;
		switch(b)
		{
			case 1: insertion_at_beginning();
			break;
			case 2: insertion_at_end();
			break;
			case 3: insert_at_location();
			break;
			default : cout<<"Error";
		}
		break;
		case 2 : cout<<"Where do you want to delete?";
		cout<<"1.Delete at beginning"<<"\n"<<"2.Delete at end"<<"\n"<<"3.Delete at specific location"<<"\n";
		cin>>c;
		switch(c)
		{
			case 1: delete_at_beginning();
			break;
			case 2: delete_at_end();
			break;
			case 3: delete_at_location();
			break;
			default : cout<<"Error";
		}
		break;
		case 3 : display();
		break;
		case 4 : search();
		break;
		case 5 : exit(0);
	}
	cout<<"Do you want to continue? Type Y/N";
	cin>>d;
}while(d=='y' || d=='Y');
return 0;
}