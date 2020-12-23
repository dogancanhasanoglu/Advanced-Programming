#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
struct mtrinfo           //creating a struct for a matrix
	{bool check;
	 char mchr;
	};
string entrance()       //entrance prompt function that returns matrix name
{   fstream mtr;string mtrname;
	while(1)
	{cout<<"Please enter file name: ";
	
	cin>>mtrname;
	mtr.open(mtrname.c_str());   // control conditions
	if (!mtr.is_open())
	{
		cout<<"Cannot find a file named matrix"<<endl;
	}
	else 
		break;
	}
	return mtrname;

}
bool coorcheck(int x, int y,int size,int size1)    // for range check
{   bool ch=true;
	
	if(x<0||x>=size)
		ch=false;
	if(y<0||y>=size1)
		ch=false;
	
return ch;
}

void comp (vector<vector<mtrinfo>> matrix,int x,int y)                     // our main search algorithm
{int ri=x,ci=y;matrix[x][y].check=true;                              // stating that initial point is visited to prevent any infinite loop
struct path{                                            // creating a struct for storing both row and column coordinates
	int x;int y;
};vector<path>mypath;                                // vector to store all the visited coordinates
int sizer=matrix.size();int i=0;
int sizec=matrix[0].size();
	while(1)
			{
				path p;
				p.x=ri;
				p.y=ci;
				mypath.push_back(p);       // storing every visited coordinate here
				if(ci!=sizec-1&&matrix[ri][ci+1].mchr=='x' && matrix[ri][ci+1].check==false)      // precedence matters first right
				{matrix[ri][ci+1].check=true;ci=ci+1;
					if(ri==x&&ci==y)
					{cout<<"Found an enclosed area. The coordinates of the followed path:"<<endl;break;}    // then down
				}
				else if(ri!=sizer-1&&matrix[ri+1][ci].mchr=='x' && matrix[ri+1][ci].check==false)
				{matrix[ri+1][ci].check=true;ri=ri+1;
					if(ri==x&&ci==y)
					{cout<<"Found an enclosed area. The coordinates of the followed path:"<<endl;break;}    // then left 
				}
				else if(ci!=0&&matrix[ri][ci-1].mchr=='x' && matrix[ri][ci-1].check==false)
				{matrix[ri][ci-1].check=true;ci=ci-1;
					if(ri==x&&ci==y)
					{cout<<"Found an enclosed area. The coordinates of the followed path:"<<endl;break;}     // and finally up
				}
				else if(ri!=0&&matrix[ri-1][ci].mchr=='x' && matrix[ri-1][ci].check==false)            // check for 
				{matrix[ri-1][ci].check=true;ri=ri-1;                                                  // finishing point
					if(ri==x&&ci==y)                                                                   // to see if it is the initial coordinates
					{cout<<"Found an enclosed area. The coordinates of the followed path:"<<endl;break;}
				}
				
								else       // vice versa
					{
						cout<<"Cannot found an enclosed area starting with given coordinate. The coordinates of the followed path:"<<endl;break; 
					}
				i++;
				if (i==2)                 // this is primitive algorithm in purpose of precaution leads to the final step, after 2 moves
					matrix[x][y].check=false;        // initial coordinate now is freed and ready to be visited again to enclose the area

			}
	for (int i=0;i<mypath.size();i++)
	{cout<<mypath[i].x<<"   "<<mypath[i].y<<endl;         // printing out the visited coordinates from the vector created above
	}

}

int main()
{   
	
	vector<vector<mtrinfo>> mymatrix;       // declaring matrix which holding the struct storing bool and char type

	string matrixname=entrance(),str;bool check=true,check1=true;static int size; // declaring variables
	ifstream matrix;
	matrix.open(matrixname);string line;
	
	while(!matrix.eof())   //opening and reading our matrix
	{
		getline(matrix,line);    
		istringstream ss(line);
		char c;
		vector<mtrinfo> temp;    // creating a temporary vector to push back our data
		while(ss>>c)        
		{mtrinfo temps;
		temps.mchr=c;
		temps.check=false;
		temp.push_back(temps);
		}
		
		mymatrix.push_back(temp);
	}
	size=mymatrix[0].size();
	for(int i=0;i<mymatrix.size();i++)       // checking for element by each row
	{   if(mymatrix[i].size()!=size)
		check1=false;
		
		for(int j=0;j<mymatrix[i].size();j++)
		{
		if(mymatrix[i][j].mchr!='x'&&mymatrix[i][j].mchr!='o')        // checking for invalid chars
			check=false;
		}

		
	}
	if(!check)
	{cout<<matrixname<<" includes invalid char(s)"<<endl;exit(EXIT_FAILURE);}       // displaying error
	if(!check1)
	{cout<<matrixname<<" is invalid matrix, does not contain same amount of char each row!"<<endl;exit(EXIT_FAILURE);}      // displaying error
	for(int i=0;i<mymatrix.size();i++)
	{   if(i==0)
		{
			cout<<"Input Matrix:"<<endl;        // printing out the matrix
		}
		for(int j=0;j<mymatrix[i].size();j++)
		{
			cout<<mymatrix[i][j].mchr<<"  ";
		}
		cout<<endl;}
	while(1)
	{cout<<"Please enter starting coordinates, first row X then column Y:"<<endl;       //taking input coordinates
	int row,column;bool ch=true;
	cin>>row;
	if(cin.fail())                                                        // I
		{                                                                 // N
		cin.clear();                                                      // P 
		cin.ignore(numeric_limits<streamsize>::max(),'\n');               // U
		                                                                  // T
		ch=false;
		}                                                                 // C
	cin>>column;                                                          // H
	if(cin.fail())                                                        // E
		{                                                                 // C
		cin.clear();                                                      // K
		cin.ignore(numeric_limits<streamsize>::max(),'\n');               // S
		
		ch=false;
		}
	if(!ch)
		{
			cout<<"Invalid Coordinates "<<endl<<endl;                      // displaying error for string or char problems
		}

	else if(row==-1&&column==-1)
		{   cout<<"Terminating..."<<endl;                    // exiting the program if -1 -1 is entered
			break;
		}
	else if(!coorcheck(row,column,mymatrix.size(),mymatrix[0].size()))
		{
			cout<<"Invalid Coordinates "<<endl<<endl;                      // displaying error for range problems
		}
	else if(mymatrix[row][column].mchr=='o')
		{
			cout<<"This cell is not occupied!"<<endl<<endl;                    // displaying error for cells with 'o'
		}	
	else
		{ 
			comp(mymatrix,row,column);        //  executing our search algorithm that mentioned above
			cout<<endl;
		}
	}
return 0;
}