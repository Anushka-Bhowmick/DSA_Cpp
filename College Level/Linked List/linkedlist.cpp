#include <iostream>
using namespace std;
class LinkedList
{
    private:
        struct Node
        {
            int data;
            Node *link;
        }*p;
    public :
        LinkedList();
        void append(int num);
        void addatbeg(int num);
        void addafter(int loc, int num);
        void display ();
        int count();
        void delend();
        ~LinkedList();
};
LinkedList :: LinkedList()
{ //initializes data memeber
    p = NULL;
}
// adds a node at the end
void LinkedList :: append (int num)
{
    Node *temp, *r;
    if (p == NULL)
    {   //if the list is empty, create first node
        temp = new Node;
        temp -> data = num;
        temp -> link = NULL;
       p = temp;
    }
    else
    {   //go to last node
        temp = p;
        while(temp -> link!=NULL)
            temp = temp->link;
        //add node at the end
        r = new Node;
        r -> data = num;
        r -> link = NULL;
        temp -> link = r;
    }
}
void LinkedList :: addatbeg(int num)
{   //adds a new node at the beginning of the Linked List
    Node *temp;
    //add a new node
    temp = new Node;
    temp -> data = num;
    temp -> link = p;
    p = temp;
}
void LinkedList :: addafter (int loc, int num)
{
    Node *temp, *r;
    temp = p;
    for (int i = 0;i<loc;i++)
    {
        temp = temp ->link;
        
        if(temp == NULL)
        {
            cout<<"There are less than "<< loc<< "elements" <<endl;
            return;
        }
    }
    //insert new node
    r = new Node;
    r -> data = num;
    r ->link = temp ->link;
    temp -> link = r;
}
void LinkedList :: display()
{
    Node *temp = p;
    cout<<endl;
    while (temp!= NULL)
    {   //traverse the entire linkedlist
        cout<< temp ->data<< " ";
        temp = temp ->link;
    }
}
int LinkedList ::  count()
{
    Node *temp = p;
    int c =0;    
    while(temp!=NULL)
    {
        temp = temp -> link;
        c++;
    }
    return c;
}
void LinkedList::delend() {
    Node *temp, *prev;
    temp = p;

    if (p == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Traverse to the last node
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == p) {
        // Only one node in the list
        delete temp;
        p = NULL;
    } else {
        // More than one node, delete the last node
        delete temp;
        prev->link = NULL; // Update the link of the second-to-last node
    }
}
LinkedList:: ~LinkedList()
{
    Node *q;
    while (p!=NULL)
    {
        q = p->link;
        delete p;
        p = q;
    }
}   
int main()
{
    LinkedList L;
    int n,loc,ch;
    do{
        cout<<"Enter 1. Append\n 2. Add at beg\n 3.Add after \n4. Display\n 5.Count\n 6.Exit"<<endl;
        cin>>ch;
    switch(ch)
    {
        case 1:
                cout<<"\nEnter a number"<<endl;
                cin>>n;
                L.append(n);
                break;
        case 2:
                cout<<"\nEnter a number"<<endl;
                cin>>n;
                L.addatbeg(n);        
                break;
        case 3:
                cout<<"\nEnter a number"<<endl;
                cin>>n;
                cout<<"\nEnter the location"<<endl;
                cin>>loc;
                L.addafter(loc,n);        
                break;
        case 4:
                cout<<"The LinkedList:"<<endl;
                L.display();
                break;
        case 5:
                cout<<"The count is "<<L.count()<<endl;
                break;
        case 6:
                cout<<"Deleted last node"<<endl;
                L.delend(); 
                break;       
        case 7:
                cout<<"Terminting the code"<<endl;
                break;
        default:
                cout<<"Enter the correct choice"<<endl;                

    }
    }while(ch!=7);
    return 0;
}