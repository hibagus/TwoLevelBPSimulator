#include <iostream>
#include "something.hpp"
using namespace std;

int main() 
{
	something newsomething(0, 1);
    cout << "Hello, World!" << endl;
	cout << "Something is " << newsomething.getSum();
    return 0;
}