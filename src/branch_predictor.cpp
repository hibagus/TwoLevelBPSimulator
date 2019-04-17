#include <iostream>
#include "saturating_counter.hpp"
using namespace std;

int main() 
{
	saturating_counter counter(strong_nottaken);
    cout << "Hello, World!" << endl;
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.decrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.decrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.incrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.decrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.decrementCounter();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	//cout << "Something is " << newsomething.getSum();
    return 0;
}