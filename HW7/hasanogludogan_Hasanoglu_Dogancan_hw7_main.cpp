#include <iostream>
#include <string>
using namespace std;

/*************************************/
/*     Doðan Can Hasanoðlu 26809     */
/*************************************/

unsigned char permutation (const char & );
void encryption (string, const string & );

int main ()       //nothing fancy here
{   string key,plaintext;
	cout<<"*** Welcome to the Simple Data Encryption Application ***"<<endl<<"Please enter the encryption key: ";  
    cin>>key;
	cout<<"Please enter the plaintext to be encrypted: ";
	cin.clear();cin.get();
	while(getline(cin,plaintext))
	{  
		cout<<"Ciphertext: ";encryption(plaintext,key);
		cout<<endl<<"\nPlease enter the plaintext to be encrypted: ";
	}
return 0;
}

unsigned char permutation (const char & ch)   //this function performs the permutation
{   unsigned char encr='\0';
	for(int i=0;i<8;i++)
	{
		unsigned char temp=ch;            //shifting the specific bit to rightmost is the logic behind it
		temp=temp <<(7-i);temp=temp>>7;
		if(i%4==0)                      //assign the new place for it then I add power of the specific bit
		{encr+=temp*int(pow(2,i+2));    // for instance if the replaced one is the 3rd bit and it is 1 then I add 8(2^3) 
		}                               //in order to get the character as binary representation
		else if(i%4==1)
		{encr+=temp*int(pow(2,i-1));
		}                               
		else if(i%4==2)
		{encr+=temp*int(pow(2,i+1));
		}
		else if(i%4==3)
		{encr+=temp*int(pow(2,i-2));     //all conditions hold for the given specific permutation algorithm
		}
	}
	return encr;
}

void encryption (string text, const string & key )  // this function performs just xor operation 
{
	for(unsigned int i=0;i<text.length();i++)
	{
		unsigned char crypt=permutation(text[i])^key[i%key.length()];
		cout<<hex<< (int) crypt;
	}
}
