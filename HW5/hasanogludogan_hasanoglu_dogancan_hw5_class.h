#ifndef hasanogludogan_hasanoglu_dogancan_hw5_class
#define hasanogludogan_hasanoglu_dogancan_hw5_class
#include<iostream>
using namespace std;
class IntegerSet
{
public:
	IntegerSet();
	IntegerSet(int arraysize);
	IntegerSet(const IntegerSet &);
	~IntegerSet();

	IntegerSet operator + (int integer);
	const IntegerSet operator + (const IntegerSet & set) const;
	const IntegerSet operator * (const IntegerSet & set);
	const IntegerSet& operator = (const IntegerSet & set);
	const IntegerSet& operator += (const IntegerSet & set);
	bool operator <= (const IntegerSet & set);

	int findsize () const ;                                    //accessors& read
	bool elementcheck (const IntegerSet & set) const;
	bool elementcheck2 (int integer) const;
	string accesselement(int integer) const;           // mutator
private:
	int size;
	int *darray;
};

ostream & operator << (ostream & out , const IntegerSet & set);
bool operator <= (int integer, const IntegerSet & set);
bool operator != (const IntegerSet & set1 , const IntegerSet & set2);


#endif