#include<iostream>
#include<string>
using namespace std;

const int n= 5;

class Shop{
	public:
	int age;
	float price;
	string name;
	
	void input(){
		cout << "Enter age, price, name" << endl;
		cin >> age >> price >> name;		
	}		
	
	void print(){
		cout << "Age : " << age << endl
		<< "Price : " << price << endl <<
		 "Name : " << name << endl;
	}
	
	
};
void sort(Shop obj){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(obj[j].age > obj[j+1].age)
				swap(obj[j].age,obj[j+1].age);
				else if(obj[j].age == obj[j+1].age){
					swap(obj[j].age,obj[j+1].age);
				}
			}
		}
	}



int main(){
	Shop obj[n];
	obj.input();
	obj.print();
	sort(obj);
	obj.print();	
	
	
	return 0;
}