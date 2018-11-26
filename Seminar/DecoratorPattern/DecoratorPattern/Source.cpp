#include <iostream>
#include <string>
using namespace std;
class Object {
public:
	virtual void print() = 0;
private:
};
class NormalIceCream :public Object {
public :
	void print() {
		cout << "Normal Ice Cream with";
	}
private:
};
class AbsIngredient :public Object {
public:
	AbsIngredient(Object *tmpthings)
	{
		things = tmpthings;
	}
	virtual void print()
	{
		things->print();
	}
private:
	Object * things;
};
class Apple :public AbsIngredient {
public:
	Apple(Object*tmpthings) :AbsIngredient(tmpthings) {

	}
	void print()
	{
		AbsIngredient::print();
		cout << " apple,";
	}
private:
};
class Pineapple :public AbsIngredient {
public:
	Pineapple(Object*tmpthings) :AbsIngredient(tmpthings)
	{

	}
	void print()
	{
		AbsIngredient::print();
		cout << " pineapple,";
	}
private:
};
class Pudding :public AbsIngredient {
public:
	Pudding(Object *tmpthings) :AbsIngredient(tmpthings)
	{

	}
	void print()
	{
		AbsIngredient::print();
		cout << " pudding,";
	}
};
int main()
{
	Object *Customer1;
	Customer1 = new Pudding(new Pineapple(new Apple(new NormalIceCream)));//Icecream with ingredients:apple,pineapple,pudding
	Object *Customer2;
	Customer2 = new NormalIceCream;//Normal Icecream
	Object *Customer3;
	Customer3 = new Pudding(new NormalIceCream);//Icecream with pudding
	Customer1->print();
	cout << endl;
	Customer2->print();
	cout << endl;
	Customer3->print();
	cout << endl;
	Object *Customer4;
	Customer4 = new Pineapple(new Apple(new NormalIceCream));
	Customer4->print();
	system("pause");

}