#include <iostream>
#include <string>
using namespace std;

class Timer {
private:
    string name;
public:
    Timer(string n) : name(n) {
        cout << "[CONSTRUCTOR] Timer object '" << name << "' created." << endl;
    }

    ~Timer() {
        cout << "[DESTRUCTOR] Timer object '" << name << "' destroyed." << endl;
    }
};

int main() {
    cout << "Main scope started" << endl;
    Timer t1("t1 - Main");

    {
        cout << "\n-> Entering Block 1 (nested scope)" << endl;
        Timer t2("t2 - Block1");
        Timer t3("t3 - Block1");
        
        {
            cout << "\n--> Entering Block 2 (inner scope)" << endl;
            Timer t4("t4 - Block2");
            cout << "--> Exiting Block 2" << endl;
        } // yaha t4 destroy hoga
        
        cout << "\n-> Exiting Block 1" << endl;
    } // yaha t2, t3 destroy honge - LIFO order me

    cout << "\nMain scope ending, t1 will be destroyed now." << endl;
    return 0;
}