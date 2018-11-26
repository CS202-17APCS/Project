#include <iostream>
using namespace std;
class Object {
public:
	virtual void dosth() = 0;
};
class NormalIceCream :public Object {
public:
	void dosth()
	{
		cout << "This is normal Ice cream" << endl;
	}
};
class IceCreamwithpudding :public Object {
public:
	void dosth()
	{
		cout << "This is Ice cream with pudding" << endl;
	}
};
class IceCreamwithapple :public Object {
public:
	void dosth()
	{
		cout << "This is Ice cream with apple" << endl;
	}
};
class IceCreamwithPudandAp :public Object {
public:
	void dosth()
	{
		cout << "This is Ice cream with pudding and apple" << endl;
	}
};
int main()
{
	Object* cus1;
	cus1 = new NormalIceCream;
	Object* cus2;
	cus2 = new IceCreamwithpudding;
	Object* cus3;
	cus3 = new IceCreamwithapple;
	Object * cus4;
	cus4 = new IceCreamwithPudandAp;
	cus1->dosth();
	cus2->dosth();
	cus3->dosth();
	cus4->dosth();
	system("pause");
}