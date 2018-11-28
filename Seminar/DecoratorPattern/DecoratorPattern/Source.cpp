#include <iostream>

using namespace std;

class Food {
    // This is the interface for the Decorator Pattern design
    private:

    public:
        virtual void print() = 0;
};

class IceCream :public Food {
    // This the core functionality class
    private:
        int size;

    public :
        IceCream(int creamSize) : size(creamSize) {}

        void print() {
            cout << "Ice Cream with size " << size << endl;
        }
};

class Ingredient : public Food {
    // This is the Wrapper for the optional functionality
    private:
        Food* things;

    public:
        Ingredient(Food *food)
        {
            things = food;
        }

        virtual void print()
        {
            things->print();
        }
};

class Apple :public Ingredient {
    // Concrete Optional Functionality
    private:

    public:
        Apple(Food* food) :Ingredient(food) {}

        void print()
        {
            Ingredient::print();
            cout << "\t Add On: Apple" << endl;
        }
};

class Pineapple :public Ingredient {
    // Concrete Optional Functionality
    private:

    public:
        Pineapple(Food* food) :Ingredient(food){}
        void print()
        {
            Ingredient::print();
            cout << "\t Add On: Pineapple" << endl;
        }
};

class Pudding :public Ingredient {
    // Concrete Optional Functionality
    private:

    public:
        Pudding(Food *food) :Ingredient(food){}
        void print()
        {
            Ingredient::print();
            cout << "\t Add On: Pudding" << endl;
        }
};


int main()
{	
    //Normal Icecream
    Food *Customer1 = new IceCream(10);
    //Icecream with pudding
    Food *Customer2 = new Pudding(new IceCream(20));
    //Icecream with ingredients:apple,pineapple,pudding
    Food *Customer3 = new Pudding(new Pineapple(new Apple(new IceCream(30))));
    //Icecream with pineapple and appple
    Food *Customer4 = new Pineapple(new Apple(new IceCream(40)));

    Customer1->print();
    Customer2->print();
    Customer3->print();
    Customer4->print();
    // Uncomment only when working on Visual Studio
    //system("pause");

}
