#include<iostream>
#include<cassert>

using namespace std;

int cantDias(int,int);
int EsBisiesto (int);

int main(){
	
	int m, a;

	cout<<"Ingrese mes: "<<endl;
	cin>>m;
	m>0 && m<13;
	cout<<"Ingrese anio: "<<endl;
	cin>>a;
		a>1582;
	
	cout<<cantDias(m,a);
	assert(29==cantDias(2,2016));
	assert(30==cantDias(4,2021)); 
	assert(29==cantDias(2,1988));
	assert(31==cantDias(12,1950)); 
	assert(30==cantDias(6,2021));
}

int cantDias(int m, int a ){
	a>1582;
	m>0 && m<13;
return 
	(m== 4) ||(m==6)  || (m==9)|| (m==11) ? 30      :
	(m== 1 )|| (m==3) || (m==5)|| (m==7) || (m==8) || (m==10) || (m==12) ? 31 :
		EsBisiesto(a);
}

int EsBisiesto (int anio){
return anio%4==0||anio%100==0 && anio%400==0 ? 29:
	28;
}
