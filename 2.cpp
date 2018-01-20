#include<iostream>
using namespace std;
struct node // Create a structure to define a node
{
	int data;
	node *next;
	node *pre;
};
class LL
{
	node *front,*rear; //Have a first and a last element in the linked list
	public:
	LL() //Constructor to point the first and the last to nothing
	{
		front=rear=NULL;	
	}	
	//Actual function definitions
	~LL();
	void add(int data, int pos);
	void addatend(int data);
	void del(int pos);
	void delatstart();
	void print();
}ob; //Creating an object 
void LL::addatend(int data)
{
	node *temp=new node; // Create a new node in the heap memory
	if(temp==NULL)
	{
		cout<<"\nOverflow!";
		return;
	} //If there is no space for temp, oops!
	temp->data=data;
	temp->next=temp->pre=NULL;
	if(front==NULL) // If there is nothing in the list, this node is the front and rear node
	{
		front=rear=temp;
		front->next=rear;
		rear->next=front;
		rear->pre=front;
		front->pre=rear;
	}
	else //Add to last
	{
		rear->next=temp;
		temp->pre=rear;
		rear=temp;
		rear->next=front;
		front->pre=rear;
	}
	temp=NULL;
	cout<<"\nIt has been added at the end!";
}
void LL::add(int data,int pos)
{
	node *temp=new node; // Create a new node in the heap memory
	if(temp==NULL)
	{
		cout<<"\nOverflow!";
		return;
	} //If there is no space for temp, oops!
	temp->data=data;
	temp->next=temp->pre=NULL;
	node *curr=front; //Start at front
	int i=1;
	if(pos==1)
	{
		temp->next=front;
		temp->pre=NULL;
		front->pre=temp;
		front=temp;
		rear->next=front;
		front->pre=rear;
		cout<<"\nIt has been added!";
	}
	else
	{
		for(;i<pos-1&&curr->next;i++) //Go till you are less than the position or the linked list comes to an end
		{
			curr=curr->next; //Go to the next one
		}
		if(i!=pos-1) // If there exists no such position, oops!
		{
			cout<<"Oops!";
		}
		else //Add the temp after the current by pointing the temp to where the current points to and where the current points to temp
		{
			temp->next=curr->next;
			curr->next=temp;
			temp->pre=curr; 
			if(curr==rear) rear=temp;
			rear->next=front;
			front->pre=rear;
			cout<<"\nIt has been added!";
		}
	}
	temp=NULL;
}
void LL::delatstart()
{
	if(front==NULL) cout<<"\nUnderflow!";
	else
	{
		node *temp=front;
		front=front->next;
		front->pre=NULL;
		temp=NULL;
		rear->next=front;
		front->pre=rear;
		cout<<"\nIt has been deleted!";
	}
}
void LL::del(int pos)
{
	node *temp; // Create a new node in the memory
	if(front==NULL)
	{
		cout<<"\nUnderflow!";
		return;
	} //If there is no Linked List, oops!
	if(pos==1)
	{
		temp=front;
		front=front->next;
		front->pre=NULL;
		rear->next=front;
		front->pre=rear;
		temp=NULL;
		cout<<"\nIt has been deleted!";
	}
	else
	{
		node *curr= front; //Start at front
		int i=1;
		for(;i<pos-1&&curr->next;i++) //Go till you are less than the position or the linked list comes to an end
		{
			curr=curr->next; //Go to the next one
		}
		if(i!=pos-1) // If there exists no such position, oops!
		{
			cout<<"Oops!";
		}
		else //Delete where the current points to
		{
			temp=curr->next;
			curr->next=temp->next;
			temp=curr->next;
			if(curr==rear) rear=curr;
			else temp->pre=curr;
			rear->next=front;
			front->pre=rear;
			cout<<"\nIt has been deleted!";
		}
	}
}
void LL::print() //Print the stuff out. Duh.
{
	if(front==NULL) cout<<"\nLinked List does not exist!";
	else 
	{
		node *temp=front;
		cout<<temp->data<<", ";
		temp=temp->next;
		while(temp->next!=front->next)
		{
			cout<<temp->data;
			temp=temp->next;
			if(temp!=front) cout<<", ";
			else cout<<".";
		}
	}
}
LL::~LL() //Destructor clears everything
{
	node *temp=front;
	while(front!=rear)
	{
		temp=front;
		front=front->next;
		temp=NULL;
	}
	delete rear;
}
int main()
{
	int ch=1;
	while(ch) //Menu
	{
		cout<<"\nEnter 1 to add at end, 2 to add at some position, 3 to delete at start, 4 to delete at some position, 5 to print and 0 to exit : ";
		cin>>ch;
		int data,pos;
		switch(ch)
		{
			case 1 : cout<<"\nEnter the data: ";cin>>data; ob.addatend(data); break;
			case 4 : cout<<"\nEnter the position: ";cin>>pos; ob.del(pos); break;
			case 2 : cout<<"\nEnter the data: ";cin>>data;cout<<"\nEnter the position: ";cin>>pos; ob.add(data,pos); break;
			case 3 : ob.delatstart();break;
			case 5 : ob.print(); break;
			case 0 : break;
			default : cout<<"\nIncorrect option!"; 
		}
	}
	return 0;
}
