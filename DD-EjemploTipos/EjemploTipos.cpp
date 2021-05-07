#include<iostream>
#include<cassert>
using namespace std;

int main(){
	
	//dato entero
	assert(-2-2==-4);
	assert(2<=4);
	assert(2!=3);
	assert(2*2==4);
	assert(4/2>=2);
	
	//dato string
	string txt="abc";
	assert("abc"=="abc");
	assert("abc"!="ab");
	assert(txt.length()<=25);
	assert(txt + "abc"=="abcabc");
	
	//dato double
	assert(3.54==3.54); 
	assert(2.10>=1.10);
	assert(2.50+2.50==5);
	assert(4.42!=1.50);
	assert(4.20*6.23!=7);
	assert(10.50/2.50<=5);
	
	
	//dato char
	assert("b"=="b");
	assert("a"<="b");
	//assert("a"+"a"=="aa");
	
	
	//dato bool
	assert(true==true);
	assert(2!=2==false);
	assert(2==2==true or false);
	
	//dato unsigned
	assert(3+1==4);  
	assert(3*3==9);
	assert(4!=5);
	assert(6/2<=5);
	
	return 0;
}
