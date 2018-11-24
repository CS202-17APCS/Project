#include <bits/stdc++.h>
#include <thread>
#include <chrono>

using namespace std;

void drawOnScreen() {
    for (int  i = 0; i < 20; i++) {
        cout << "____";
    }
    cout << endl;
}


int main(int argc, char const* argv[])
{
    thread t1(drawOnScreen);

    for (int  i = 0; i < 10; i++) {
        cout << i << endl;
        chrono::seconds duration(1);
        this_thread::sleep_for(duration);
    }
    t1.join();
    
    return 0;
}
