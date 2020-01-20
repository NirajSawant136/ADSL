#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
class set
{
	private:Node *h , *curr , *tr ;
		int n;
	
	public:	set()
		{
			n = 0;
			h = NULL;
		}
		void create()
		{	
			int data; 
			cout<<"\nENTER SET DETAILS -> ";
			cout<<"\nENTER NUMBER OF ELEMENTS -> ";
			cin>>n;
			cout<<"\nENTER ELEMENTS OF SET -> ";
			for(int i=0;i<n;i++)
			{
				cin>>data;
				append(data);
			}
		}
		void append(int data)
		{
			
			curr = new Node;
			curr->data = data;
			curr->next = NULL;
			if(h == NULL)
			{
				h = curr;
			}
			else
			{
				tr = h;
				while(tr->next != NULL)
				{
					tr = tr->next;
				}
				tr->next = curr;
			}
		}
		void Union(set s1 , set s2)
		{	
			int lo = 1;
			tr = h;
			Node *tr2 = s2.h;
			Node *tr1 = s1.h;
			while(tr1 != NULL)
			{
				append(tr1->data);
				tr1 = tr1->next;
			}
			while(tr2 != NULL)
			{
				lo = 1;
				tr1 = s1.h;
				while(tr1 != NULL)
				{
					if(tr1->data == tr2->data)
					{	
						lo = 0;
						break;
					}
					tr1 = tr1->next;
				}
				if(lo)
				{
					append(tr2->data);
				}
				tr2 = tr2->next;
			}
			
		}
		void Inter(set s1 , set s2)
		{
			int lo = 1;
			tr = h;
			Node *tr2 = s2.h;
			Node *tr1 = s1.h;
			while(tr2 != NULL)
			{
				lo = 1;
				tr1 = s1.h;
				while(tr1 != NULL)
				{
					if(tr1->data == tr2->data)
					{	
						lo = 0;
						break;
					}
					tr1 = tr1->next;
				}
				if(!lo)
				{
					append(tr2->data);
				}
				tr2 = tr2->next;
			}
		}
		void display()
		{
			tr = h;
			while(tr->next != NULL)
			{
				cout<<tr->data<<" ";
				tr = tr->next;
			}
			cout<<tr->data<<endl;
			
		}
};
int main()
{
	set s1,s2,s3 ,s4,s5,s6;
	s1.create();
	s2.create();
	cout<<"\n";
	s1.display();
	cout<<"\n";
	s2.display();
	cout<<"\n";
	s3.Union(s1 , s2);
	s3.display();
	cout<<"\n";
	s4.Inter(s1,s2);
	s4.display();
	return 0;
}
