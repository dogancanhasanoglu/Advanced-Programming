#include<iostream>
#include<string>
#include <fstream>
#include<sstream>
#include "hasanogludogan_hasanoglu_dogancan_hw4_stack.h"

using namespace std;

bool isNumber(string s);
bool isNumber1(string s) ;
int main()
{bool statusrc=false;bool check=false;
string row,column;
while(!statusrc)
{   if(!check)
	{cout<<"Enter the number of rows: ";
	cin>>row;
	
		if(!isNumber(row))                     
		{
			cout<<row<<" is not valid!"<<endl;                  // prompts and errors here
			cin.clear();cin.ignore(10000, '\n');
		}
		else
		  check=true;
	}
	else
	{   
		cout<<"Enter the number of columns: "; 
		cin>>column;
		
		if(!isNumber(column))
		{cout<<column<<" is not valid!"<<endl;
			cin.clear();cin.ignore(10000, '\n');
		}
		else
			statusrc=true;
	}
	
	
}
	int r=stoi(row);
	int c=stoi(column);

	char ** dmatrix = new char*[r];   // here creating our dynamic matrix 
	for(int i =0; i<r; i++)
	{
		dmatrix[i] = new char[c];
	}

	ifstream inputFile;
	string fileName;

	cout	<< "Please enter file name: ";    
	cin		>> fileName;

	                                                // prompts and errors here
	inputFile.open (fileName.c_str());
	while (inputFile.fail())			
	{
		cout	<< "Cannot open a file named " <<fileName<< endl
				<< "Please enter file name: " ;
		cin		>> fileName;

		inputFile.clear();
		inputFile.open(fileName.c_str());
	}

	string line;
	for (int i = 0; i < r; i++)                      // filling our matrix here
	{	getline(inputFile,line);int j=0;
		for (char ch : line)
		{   
			
			dmatrix[i][j] = ch;
			j++;		
		}
		
	}

	inputFile.close();
	bool statuscoor=false;
	string x,y;
	do{ 
		cout<<"Enter the starting point: ";                 // prompts and errors
		cin>>x>>y;
		if(!isNumber1(x)||!isNumber1(y))
			{cout<<"Invalid coordinate!"<<endl;			
			cin.clear();cin.ignore(10000, '\n');
			}
		else if (stoi(x)>r-1||stoi(y)>c-1)
			{cout<<"Invalid coordinate!"<<endl;
			cin.clear();cin.ignore(10000, '\n');
			}
		else
			statuscoor=true;
	

	
	
	}while(!statuscoor);
	int x1=stoi(x);int y1=stoi(y);                       // terminates program if given coordinate is occupied
	if(dmatrix[x1][y1]=='X')
		{
			cout<<"Starting point is already occupied."<<endl<<
				"Terminating..."<<endl; exit (EXIT_FAILURE);
		}
	char fillchar='x';
	while(fillchar=='x'||fillchar=='X')
	{
		cout<<"Enter the filling char: ";               //prompt to take filling char
		cin>>fillchar;
		if(fillchar=='x'||fillchar=='X')
			{cout<<"Filling char is not valid!"<<endl;
			cin.clear();cin.ignore(10000, '\n');
			}
	
	
	}
	DynamicStack mystack;				// creating a object here
	int xi=x1;int yi=y1;                      
	mystack.push(x1,y1);
	while(!mystack.isEmpty())
	{   bool filled=false;
		
		
		if(dmatrix[x1+1][y1]==' '&&!filled)
		{   
			x1++;mystack.push(x1,y1);                             // our main algorithm process here
			dmatrix[x1][y1]=fillchar;
			filled=true;
		}														// if there is a occupied cell then it rotates
		else if(dmatrix[x1][y1+1]==' '&&!filled)
		{
			y1++;mystack.push(x1,y1);
			dmatrix[x1][y1]=fillchar;
			filled=true;
		}
		else if(dmatrix[x1-1][y1]==' '&&!filled)
		{
			x1--;mystack.push(x1,y1);
			dmatrix[x1][y1]=fillchar;
			filled=true;
		}
		else if(dmatrix[x1][y1-1]==' '&&!filled)
		{
			y1--;mystack.push(x1,y1);
			dmatrix[x1][y1]=fillchar;
			filled=true;
		}
		else                                               // if there is no cell vacant it pops the last cell out of stack
		{	
			mystack.pop(x1,y1);
		}
	}dmatrix[xi][yi]=fillchar;
	
		for(int i=0; i<r; i++)  // displaying our matrix
	{
		
		for(int j=0; j<c; j++)
		{
			cout << dmatrix[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=0; i<r; i++)   // deleting our matrix
	{
		delete [] dmatrix[i];
	}
	delete [] dmatrix;
	int bob=34;
	int sponge= bob;
	int patrick=sponge;
	sponge=41;
	cout<<sponge<<bob<<patrick <<endl;
	return 0;

}

 bool isNumber(string s)     // function to check inputs
{ bool status=true;
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            status=false; 
	if(status)
	{
		int si=stoi(s);
		if(si<3)
			status=false;
	}
    return status; 
} 
  bool isNumber1(string s)  // function to check inputs
{ bool status=true;
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            status=false; 
	if(status)
	{
		int si=stoi(s);
		if(si<0)
			status=false;
	}
    return status; 
} 
 
 