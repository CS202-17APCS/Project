#include <iostream>

using namespace std;

class IceCream {
    private:
        int size;
    public:
        IceCream(int creamSize) : size(creamSize) {}
        void print() {
            cout << "Ice Cream with size " << size << endl;
        }
};
class IceCreamWithPudding :public IceCream {
    private:

    public:
        IceCreamWithPudding(int size) : IceCream(size){}
        void print(){
            IceCream::print();
            cout << "\t Addon: Pudding" << endl;
        }
};
class IceCreamWithApple :public IceCream{
    private:

    public:
        IceCreamWithApple(int size) : IceCream(size) {}
        void print() {
            IceCream::print();
            cout << "\t Addon: Apple" << endl;
        }
};
class IceCreamWithPuddingAndApple :public IceCream{
    private:

    public:
        IceCreamWithPuddingAndApple(int size) : IceCream(size) {}
        void print() {
            IceCream::print();
            cout << "\t Addon: Apple" << endl;
            cout << "\t Addon: Pudding" << endl;
        }
};
int main()
{
    // Normal Ice Cream
    IceCream customer1(10);
    // Ice Cream with Pudding add on
    IceCreamWithPudding customer2(20);
    // Ice Cream with Apple add on
    IceCreamWithApple customer3(30);
    // Ice Cream with Apple and Pudding add on
    IceCreamWithPuddingAndApple customer4(40);

    // Print information of each cream
    customer1.print();
    customer2.print();
    customer3.print();
    customer4.print();
    // Uncomment if runs on Visual Studio
    //system("pause");
    return 0;
}
