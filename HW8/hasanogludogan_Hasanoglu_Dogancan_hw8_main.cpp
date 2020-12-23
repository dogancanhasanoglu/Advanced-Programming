#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "HW8DynIntQueue.h"
#include <random> 
#include <time.h> 

 using namespace std;

/************************
*Doðan Can Hasanoðlu    *
*26809 CS204 HW8        *
*************************/
 // declaring global variables
HW8DynIntQueue myqueue;
mutex Mcout, Mqueue;
int random_range(const int & min, const int & max); 
int total;
int counter1 = 0;
int counter=1;


void arrival (HW8DynIntQueue & myqueue,int min,int max) // arrival function
{   
	while (counter <= total)	
	{   
		Mqueue.lock();
		myqueue.enqueue(counter);   //enqueues while mutex islocked
		int id=myqueue.getCurrentSize();
		Mqueue.unlock();

		Mcout.lock();
		time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
		struct tm *ptm = new struct tm; 
		localtime_s(ptm, &tt);                                                       // prints arrival time when mutex is locked
		cout << "New customer with ID " << counter << " has arrived (queue size is " << id  << "): " << put_time(ptm,"%X") << endl;
		Mcout.unlock();

		counter++;

		int sleepTime = random_range(min ,max);   // sleeps the thread
		this_thread::sleep_for(chrono::seconds(sleepTime));
		
	}
}

void checkout(int cashierno, HW8DynIntQueue & myqueue,int min,int max,int threshold) // checkout function
{
	int sleepTime = random_range(min ,max);   // sleeps the thread initially for once 
	this_thread::sleep_for(chrono::seconds(sleepTime));
	int customer;
	while(counter1 < total)  // termination if reaches the total number of customers
	{	
		
		Mqueue.lock();
		if (!myqueue.isEmpty())  
		{  
			
			if(cashierno==1&&myqueue.getCurrentSize()!=0)  // cashier 1 is the prime cashier so checks whether 
			{	                                           // it is eligible to work as stated or not
				counter1++;
				myqueue.dequeue(customer);   // dequeues while mutex is locked
				
				int size=myqueue.getCurrentSize();
				Mqueue.unlock();
				
				Mcout.lock();
				time_t tt1 = chrono::system_clock::to_time_t(chrono::system_clock::now());    // prints the transaction beginning time
				struct tm *ptm1 = new struct tm; 
				localtime_s(ptm1, &tt1);
				cout<< "Cashier 1 started transaction with customer "<< customer <<" (queue size is " << size  << "): " <<" "<<put_time(ptm1,"%X") <<endl;
				Mcout.unlock();
			
				int sleepTime = random_range(min ,max);   // sleeps the thread according to given max&min
				this_thread::sleep_for(chrono::seconds(sleepTime));

				Mcout.lock();
				time_t tt2 = chrono::system_clock::to_time_t(chrono::system_clock::now());   // prints the transaction ending time
				struct tm *ptm2 = new struct tm; 
				localtime_s(ptm2, &tt2); 	
				cout<< "Cashier 1 finished transaction with customer "<< customer <<" "<< put_time(ptm2,"%X") <<endl;
				Mcout.unlock();
				
			}
			else if(myqueue.getCurrentSize()!=0&&myqueue.getCurrentSize()>=threshold&&cashierno==2)  // cashier 2 is a substitute so checks 
			{                                                                                        // if it is necessity to work 
				
				counter1++;
				myqueue.dequeue(customer);
				
				int size=myqueue.getCurrentSize();
				Mqueue.unlock();
				
				Mcout.lock();
				time_t tt1 = chrono::system_clock::to_time_t(chrono::system_clock::now());  // prints the transaction beginning time
				struct tm *ptm1 = new struct tm; 
				localtime_s(ptm1, &tt1);
				cout<< "Cashier 2 started transaction with customer "<< customer <<" (queue size is " << size  << "): " <<" "<<put_time(ptm1,"%X") <<endl;
				Mcout.unlock();

				
				
				int sleepTime = random_range(min ,max);   // sleeps the thread according to given max&min
				this_thread::sleep_for(chrono::seconds(sleepTime));

				Mcout.lock();
				time_t tt2 = chrono::system_clock::to_time_t(chrono::system_clock::now());         // prints the transaction ending time
				struct tm *ptm2 = new struct tm; 
				localtime_s(ptm2, &tt2); 	
				cout<< "Cashier 2 finished transaction with customer "<< customer <<" "<< put_time(ptm2,"%X") <<endl;
				Mcout.unlock();
				
			}
			else
				Mqueue.unlock(); 
		
		}
		else
			Mqueue.unlock();
	
		
	}
}


int main()
{   // classic main entry and prompt to user
	int total_customer,threshold,arrival_min,arrival_max,checkout_min,checkout_max;
	cout<<"Please enter the total number of customers: ";
	cin>>total_customer;
	cout<<"Please enter the number of customers waiting in the queue to open the second cashier: ";
	cin>>threshold;
	cout<<"Please enter the inter-arrival time range between two customers: "<<endl;
	cout<<"Min: ";
	cin>>arrival_min;
	cout<<"Max: ";
	cin>>arrival_max;
	cout<<"Please enter the checkout time range of cashiers: "<<endl;
	cout<<"Min: ";
	cin>>checkout_min;
	cout<<"Max: ";
	cin>>checkout_max;
	total=total_customer;

	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());  // prints the simulation starting time
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	cout << "Simulation starts " << put_time(ptm,"%X") <<endl;

	thread arrival(&arrival,ref(myqueue),arrival_min,arrival_max);
	thread cashier1(&checkout,1,ref(myqueue),checkout_min,checkout_max,threshold);
	thread cashier2(&checkout,2,ref(myqueue),checkout_min,checkout_max,threshold);             //thread
																							   //operations
	arrival.join();
	cashier1.join();
	cashier2.join();

	tt = chrono::system_clock::to_time_t(chrono::system_clock::now());   // prints the simulation ending time
	localtime_s(ptm, &tt); 
	cout<<"End of the simulation ends: "<<put_time(ptm,"%X")<<endl;
	return 0;
}




int random_range(const int & min, const int & max)        // given random time generator 
{
	static mt19937 generator(time(0));    
	uniform_int_distribution<int> distribution(min, max); 
	return distribution(generator); 
}