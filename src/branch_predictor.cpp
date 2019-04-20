#include <iostream>
#include "saturating_counter.hpp"
using namespace std;

int main() 
{
	saturating_counter counter(strong_nottaken);
    cout << "Hello, World!" << endl;
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << endl;
	//cout << "Something is " << newsomething.getSum();
    return 0;
}