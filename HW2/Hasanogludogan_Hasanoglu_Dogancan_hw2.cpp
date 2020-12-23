#include <iostream>
#include <fstream> 
#include <sstream>
#include<vector>
#include<string>
using namespace std;

string entrance ()
{string cfn;
fstream cf;

while(1)
{
	cout<<"Please enter file name: ";
	cin>>cfn;
	cf.open(cfn);
	if(!cf.is_open())
		cout<<"Cannot find a file named "<<cfn<<endl;
	else
		break;
}
return cfn;
}

bool inputcheck( string input)
{bool check=true;
	if(input.length()!=16)
		check=false;
	else
	{for(int i=0;i<16;i++)
		{
			if(input[i]<'0'||input[i]>'10')
				check=false;
		}
	
	}
	return check;
}

struct node 
{ int month, year; 
vector<string> creditc;
node* next; 
};

bool search(node *  & head, string cn, int m,int y)
{bool ch1=false;

while(head!=NULL)
{	if(m==head->month&&y==head->year)
		{
			head->creditc.push_back(cn);
			ch1=true;break;
		}
head=head->next;

}
return ch1;
}
void searchlist(node * & head,string xx)
{bool che1=false;
while(head!=NULL)

{for(int i=0;i<head->creditc.size();)
	{   
		if(xx==head->creditc[i])
		{cout<<"There exists a credit card given number  "<<head->creditc[i]<<" with expiration date: "<<head->month<<"  "<<head->year<<endl;che1=true;break;}

	i++;}
head=head->next;

}
if(!che1)
	cout<<"There is no credit card with given credit card number: "<<xx<<endl;
}

void display(node * & head)
{	node*temp=head;while(temp!=NULL)
		 
		 {  cout<<"Expiration Date: "<<temp->month<<"  "<<temp->year<<endl;
			for(int i=0;i<temp->creditc.size();i++)
				{cout<<i+1<<")  "<<temp->creditc[i]<<endl;
			
				}
			cout<<"-------------------"<<endl<<endl;
			temp=(*temp).next;}
}

void deletenode(node *  & head, int m, int y)
{   node*ptr=head;node * temp;bool dlch=false;

	if(head->month==m && head->year==y)
		{   cout<<"Node with expiration date "<<m<<"  "<<y<<" and the following credit cards have been deleted! "<<endl;
			for(int i=0;i<ptr->creditc.size();i++)
				{
					cout<<i+1<<") "<<ptr->creditc[i]<<endl;
				}
			
			temp=head->next;
			delete head;
			head=temp;
			
			dlch=true;
			
			
		}
	else
	{	node* ptr2=head;
		while(ptr->next!=NULL)
    {   ptr=ptr->next;
		if(ptr->month==m&&ptr->year==y)
		{cout<<"Node with expiration date "<<m<<"  "<<y<<" and the following credit cards have been deleted! "<<endl;
			for(int i=0;i<ptr->creditc.size();i++)
				{
					cout<<i+1<<") "<<ptr->creditc[i]<<endl;
				}ptr2->next=ptr->next;
		delete ptr;
		
		dlch=true;break;
		}
		ptr2=ptr;
	
		
	}if(!dlch)
		cout<<"There is no node with expiration date "<<m<<"  "<<y<<", nothing deleted!"<<endl;

	}


}
bool comp (node *  ptr,int m,int y)
{
	   bool che3=false;
	
	if(ptr->next!=NULL&&ptr->next->year<y)
		che3=true;
	else if(ptr->next!=NULL&&ptr->next->year==y&&ptr->next->month<m)
		che3=true;

	return che3;
}
void addlist(node *  head, int m,int y,node *&temp) 
{   bool che4=false;
	node* ptr=head;
	node *ptr2=head;

	if(temp->year<ptr->year)
		che4=true;
	else if(temp->year==ptr->year&&temp->month<ptr->year)
		che4=true;

	if(head==NULL||che4==true)
		{
			temp->next=ptr;
			head=temp;
			
		}
	
	while (ptr2->next != NULL&&comp(ptr2,m,y)==true)
	{   ptr2 = ptr2->next;
		
		
	}
	
	temp->next=ptr2->next;ptr2->next=temp;

}

node* adjust(node*  & head,int m,int y,vector<string> vec,int x)	
{node *ptr=head;
node *ptr2= new node;
if(x==2)
{node *pt=new node;
pt->month=m;
pt->year=y;
pt->creditc=vec;
pt->next=NULL;

head=head->next;

head->next=pt;
}
else{
while(ptr!=NULL)
	{if(head->year<ptr->next->year)
		{
			ptr2->next=ptr->next;
			ptr->next=ptr2;
			ptr2->month=m;
			ptr2->year=y;
			ptr2->creditc=vec;
			head=head->next;
		
			break;
		}
	else if(head->year==ptr->next->year&&head->month<ptr->next->month)
		{
			ptr2->next=ptr->next;
			ptr->next=ptr2;
			ptr2->month=m;
			ptr2->year=y;
			ptr2->creditc=vec;
			head=head->next;
		
			break;
		}
	ptr=ptr->next;
}}

return head;

}


int main()
{ifstream cfile;string cfilename=entrance();int i=1;
string line,ccnumber, month, year;


node *head=NULL;


cfile.open(cfilename);


while(!cfile.eof())   
	{   bool check1=false;
		node *temp= new node;

		getline(cfile,line);    
		istringstream ss(line);
		ss>>ccnumber>>month>>year;
		if(ccnumber=="")
			break;
		
		int m=stoi(month);int y=stoi(year);
		vector<string> myvec;
		myvec.push_back(ccnumber);

		temp->creditc=myvec;
		temp->month=m;
		temp->year=y;
		temp->next=NULL;
	
		if(head==NULL)
			{
				head=temp;
				/*tail=temp;*/
				
				cout<<"New node is created with expiration date: "<<m<<" "<<y<<endl;
				cout<<"Credit card "<< ccnumber<<" added to node " <<m<<" "<<y<<endl;
				cout<<"***************"<<endl;
				
			}
		else

		{   node * ind=head;
			if(search(ind,ccnumber,m,y))
				{cout<<"Node with expiration date "<<m<<" "<<y<<" already exists"<<endl;
				cout<<"Credit card "<< ccnumber<<" added to node " <<m<<" "<<y<<endl;
				cout<<"***************"<<endl;
				delete temp;
				
			}
			else
		  {	addlist(head,m,y,temp);
			
			  /*tail->next = temp;
            tail = tail->next;*/
			cout<<"New node is created with expiration date: "<<m<<" "<<y<<endl;
			cout<<"Credit card "<< ccnumber<<" added to node " <<m<<" "<<y<<endl;
			cout<<"***************"<<endl;i++;
		}
		
		
		
}
		
}		
		
		
	cout<<endl;
	if(head!=NULL)
		adjust(head,head->month,head->year,head->creditc,i);
	string option;
	while(1)
	{
		cout<<endl<<"1)Display List\n"<<
			"2)Card Search via Credit Number\n"<<
			"3)Delete Card with respect to Expiration Date \n"<<
			"4)Exit"<<endl<<endl;
		cout<<"Please choose option from the menu: ";
		
		cin>>option;
		cout<<endl;
		while(option<"1"||option>"4")
		{cout<< "Invalid! Your option must be between 1 and 4." << endl;
		cout<<"Please choose option from the menu: ";
		cin.clear();
		cin.ignore();
		cin>>option;
		}

			

		
		
		
		if		(option == "1")
		{	display(head);
		if(head==NULL)
			cout<<"List is empty!"<<endl;
		}
		else if (option == "2")	
		{string inp;
	while(1)
	{ bool ch=true;
	cout<<"Please enter the credit card number:";	
	cin>>inp;

	{for(int i=0;i<16;i++)
		if(inp[i]<'0'||inp[i]>'9')
			{i=16;
		cin.clear();
		cin.ignore();
		ch=false;}
	}
	if(inp.length()!=16)
		ch=false;
	if(!ch)
		cout<<"Invalid format!"<<endl;
	else if(ch)
		break;
	}
	if(head==NULL)
		cout<<"There is no credit card with given credit card number: "<<inp<<endl;
	else
	{node* ind1=head;
	searchlist(ind1,inp);}
		}
		else if (option == "3")
		{int mon,yr;
		while(1)
		{cout<<"Please enter month and year: "<<endl;bool che1=true,che2=true;
		
		cin>>mon;
		if(cin.fail())
			{che1=false;
			cin.clear();
			cin.ignore();}
		cin>>yr;
		if( cin.fail())
			{cin.clear();
			che2=false;}
		
		if(che1==false||che2==false)
			{cout<<"Invalid Date!"<<endl;
				cin.sync();}
		else if(mon<1||mon>12)
			{cout<<"Invalid Date!"<<endl;
				cin.sync();}
		else if(che1!=false&&che2!=false)
			break;
		
		}
		cout<<endl;
		if(head==NULL)
			cout<<"There is no node with expiration date "<<mon<<"  "<<yr<<", nothing deleted!"<<endl;
		else{
		
		//node *ptr2=head;
		deletenode(head,mon,yr);}

		
		}
		else if (option == "4")
		{cout<<"Terminating"<<endl;
		break;
		
		}
			
			
} 
	


return 0;
}

