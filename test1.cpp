#include<wiringPi.h>
#include<thread>

using namespace std;

struct send
{
	int led,time;
};  

void fun_thread(send s)
{	
	pinMode(s.led,OUTPUT);
	digitalWrite(s.led,HIGH); 	
	delay(10000);
	digitalWrite(s.led,LOW);
	for (int i = 0; i<50; i++)
	
	{	
		digitalWrite(s.led,HIGH); 	delay(s.time);
		digitalWrite(s.led,LOW);	delay(s.time);
	}		
}

int main()
{
	wiringPiSetupGpio(); //set the gpio pin bcm mode
	
	//strture to send two parameter to thread
	send value1,value2;  
	
	//set the variables for thread1	
	value1.led=21;		
	value1.time=100;

	//set the variables for thread2
	value2.led=20;
	value2.time=500;
	
	
	thread th1(fun_thread,value1);
	thread th2(fun_thread,value2);

	th2.join();
	th1.join();
}

