#include "hasanogludogan_hasanoglu_dogancan_hw5_class.h"
#include <iostream>
#include<string>
using namespace std;

IntegerSet::IntegerSet()
{
	size=0;
	darray=NULL;
}

IntegerSet::IntegerSet(int arraysize)
{
	if (arraysize>0)
	{   
		size=arraysize;
		darray=new int [arraysize];
		for (int i=0; i<arraysize; i++)
		{
			darray[i]=i;
		}
	}
	else
	{	
		size=0;
		darray=new int;
	}
}

IntegerSet::IntegerSet (const IntegerSet & set)
{   size=set.size;
	darray = new int [set.size];
	for (int i=0; i<set.size; i++)
    {
		darray[i]=set.darray[i];
    }
}

IntegerSet::~IntegerSet()
{
	delete [] darray;
	size=0;
}

/*****************************************************/
//All of the operators based on for loop and searching&comparing elements inside the dynamic array
IntegerSet IntegerSet::operator+ (int integer)
{   
	bool check=true;
	if(elementcheck2(integer))
		check=false;

	if(check&&size!=0)
	{
		int * temp= new int [size+1];
		for(int i=0; i<size;i++)
		{
			temp[i]=darray[i];
		}
		temp[size]=integer;
		size++;
		delete [] darray;
		darray= new int[size];
		for(int i=0; i<size;i++)
		{
			darray[i]=temp[i];
		}
	}
	else if(check)
		{
			darray= new int [1];
			darray[0]=integer;
			size++;
		}
	return *this;
}


const IntegerSet IntegerSet::operator+ (const IntegerSet & set ) const
{   IntegerSet result(set);
	for(int i=0;i<size;i++)
	{   bool check=true;
		for(int j=0;j<set.size;j++)
		{
				if(darray[i]==set.darray[j])
				{
					check=false;break;
				}
		
		}
		if(check)
			{
				int * temp= new int [result.size+1];
				for(int k=0; k<result.size;k++)
				{
					temp[k]=result.darray[k];
				}
				temp[result.size]=darray[i];
				result.size++;
				delete [] result.darray;
				result.darray=temp;
	
			}
		

	}
	return result;
}

const IntegerSet IntegerSet::operator * (const IntegerSet & set)
{
	IntegerSet intersection;
	int count=0;
	for(int i=0;i<size;i++)
	{   bool check=true;
		for(int j=0;j<set.size;j++)
		{
				if(darray[i]==set.darray[j])
				{
					check=false;
					count++;
					break;
				}
		
		}
		if(!check&&intersection.size==0)
		{
			int * temp= new int [count];
			temp[0]=darray[i];
			intersection.size=1;
			delete [] intersection.darray;
			intersection.darray=temp;
		}
		else if(!check&&size!=0)
			{
				int * temp= new int [count];
				
				for(int k=0; k<count-1;k++)
				{
					temp[k]=intersection.darray[k];
				}
				temp[count-1]=darray[i];
				intersection.size++;
				delete [] intersection.darray;
				intersection.darray=temp;
	
			}
		

	}

	return intersection;
}


const IntegerSet& IntegerSet::operator = (const IntegerSet & set)
{
	if(this!= & set)
	{
		this->~IntegerSet();
		size=set.size;
		darray= new int [size];
		for(int i=0;i<size;i++)
		{
			darray[i]=set.darray[i];
		
		}
	
	
	}
	return *this;
}
const IntegerSet& IntegerSet::operator += (const IntegerSet & set)
{
	if(this!= & set)
	{	
		for(int i=0;i<set.size;i++)
		{   bool check=true;
			for(int j=0;j<size;j++)
			{
				if(set.darray[i]==darray[j])
				{
					check=false;break;
				}
			}
			if(check)
			{
				int * temp= new int [size+1];
				for(int k=0; k<size;k++)
				{
					temp[k]=darray[k];
				}
				temp[size]=set.darray[i];
				size++;
				delete [] darray;
				darray=temp;
				
			}
		}
	
	
	
	}
	return *this;
}

bool IntegerSet::operator <= (const IntegerSet & set)
{
	bool check=true;
	if(size>set.size)
		check=false;
	else
	{
		
		for (int i=0;i<size;i++)
		{   int count=0;
			for(int j=0;j<set.size;j++)
			{
				if(darray[i]!=set.darray[j])
					count++;
			}
			if(count==set.size)
			{
				check=false;
				break;
			}
		if(!check)
			break;
		
		}
	}
	return check;
}

/****************************************************************/
ostream & operator << (ostream & out , const IntegerSet & set)
{   int i;
	int mysize=set.findsize();
	out<< "{";
	if(set.findsize()==0)
		out<<" }";
	else
	{
	for(i=0;i<mysize-1;i++)
	{
		out<<set.accesselement(i)<<", ";
		
	}out<<set.accesselement(i)<<"}";
	}
	
	
	return out;
}
bool operator <= (int integer, const IntegerSet & set)
{
	if(set.elementcheck2(integer))
		return true;
	else 
		return false;

}

bool operator != (const IntegerSet & set1 , const IntegerSet & set2)
{  
	bool notequal=true;
	if( set1.findsize()!= set2.findsize())
	{
		return notequal;
	}
	else if(!set1.elementcheck(set2))
	{
		return notequal;
	}
	else
		return false;
	
}

/***********************************************************/


int IntegerSet::findsize() const
{   
	return size;

}

bool IntegerSet::elementcheck(const IntegerSet & set) const
{   bool check=true;
	for (int i=0;i<size;i++)
	{   int count=0;
		for(int j=0;j<set.size;j++)
		{
			if(darray[i]!=set.darray[j])
				count++;
		}
		if(count==set.size)
		{
			check=false;
			break;
		}
		
	}
	return check;
}

bool IntegerSet::elementcheck2(int integer) const
{   bool check=false;
	for(int i=0;i<size;i++)
	{
		if(darray[i]==integer)
		{check=true;break;}
	
	}
	return check;
}

string IntegerSet::accesselement(int integer) const
{
	string mystr= to_string(darray[integer]);
	return mystr;

}
