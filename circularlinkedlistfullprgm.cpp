#include <iostream>
using namespace std;
class node
{
    public:
  int info;
  node *next;
}*header=NULL;

void insert_at_end()
{
    node *t,*nw;
    nw=new node;
    cout<<"Enter the item to be inserted";
    cin>>nw->info;
    if(header==NULL)
    {
        header=nw;
        nw->next=header;
    }
    else if ( header->next==header)
    {
        header->next=nw;
        nw->next=header;
    }
    else
    {
        t=header;
        while(t->next!=header)
        t=t->next;
    t->next=nw;
    }
    nw->next=header;
}

void insert_at_beginning()
{
    node *nw,*t;
    nw=new node;
    cout<<"Enter the item to be inserted";
    cin>>nw->info;
    if(header==NULL)
    {
        header=nw;
        nw->next=header;
    }
    else
    {
        nw->next=header->next;
        header=nw;
    }
}

void insert_at_location()

{
    int loc;
    node *nw,*t;
    nw=new node;
    cout<<"Enter the item to be inserted";
    cin>>nw->info;
    cout<<"Enter the location to insert it";
    cin>>loc;
    if(loc<1)
    {
        cout<<"Enter valid location!";
        return;
    }
    else if(loc==1)
    {
        header=nw;
        nw->next=header;
    }
    else
    {
        t=header;
        for(i=1; i<loc-1; i++)
        {
            if(t->next==header)
            cout<<"The given location is not found!";
        t=t->next;
        }
        t->next=nw;
        nw->next=header;
    }
}

void display()
{
    node *t=header;
    if(t==NULL)
        cout<<"Empty list!";
        else if (t->next==header)
        cout<<t->info;
    else
    {
        while(t->next!=header)
        {
            cout<<t->info<<"\t";
            t=t->next;
        }
    }
}

void delete_from_end()
{
    if(header)
}

int main()
{
    int a;
    char c;
    do
    {
        cout<<"Press 1 to insert, press 2 to display";
        cin>>a;
        switch(a)
        {
            case 1 : insert();
            break;
            case 2 : display();
            break;
        }
        cout<<"Do you want to continue? Y/N";
        cin>>c;
    }while(c == 'y' || c == 'Y');
    return 0;
}