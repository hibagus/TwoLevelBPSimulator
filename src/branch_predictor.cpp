#include <iostream>
#include "saturating_counter.hpp"
#include "branch_history_register.hpp"
using namespace std;

int main() 
{
	saturating_counter counter(strong_nottaken);
    cout << "Hello, World!" << endl;
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	counter.updateNotTaken();
	cout << "Current counter prediction is: " << counter.isTaken() << " which is " << counter.getCounterStatusString()<< endl;
	
	branch_history_register bhr(7);
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	cout << "Binary: " << bhr.getBinaryString() << " | Value: " << bhr.getLongValue() << endl;
	bhr.updateNotTaken();
	
	
	//cout << "Something is " << newsomething.getSum();
    return 0;
}