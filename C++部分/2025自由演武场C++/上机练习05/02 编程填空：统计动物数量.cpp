#include <iostream>
using namespace std;

class Animal{
public:
	static int number;
	Animal(){
		Animal::number+=1;
	}
	virtual ~Animal(){
		Animal::number-=1;
	}
};

class Dog:public Animal{
public:
	static int number;
	Dog(){
		Dog::number+=1;
	}
	~Dog(){
		Dog::number-=1;
	}
};

class Cat:public Animal{
public:
	static int number;
	Cat(){
		Cat::number+=1;
	}
	~Cat(){
		Cat::number-=1;
	}
};

int Animal::number=0;
int Dog::number=0;
int Cat::number=0;

void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
