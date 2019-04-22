/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include <iostream>
#include "saturating_counter.hpp"
#include "branch_history_table.hpp"
#include "branch_history_table_entry.hpp"
#include "branch_history_register.hpp"
#include "trace_file_parser.hpp"
#include "branch_history_register_table.hpp"
#include "pattern_history_table.hpp"

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
	
	trace_file_parser tracefile("tracetest.in");
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	tracefile.getNextEntry();
	cout << "Current Entry is: "<< tracefile.getCurrentTraceEntryString() << " | filestatus: " << tracefile.isTraceFileGood() << endl;
	
	branch_history_table_entry bht_entry_test;
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateNotTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateNotTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(0);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(1000);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(1000);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(1000);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	bht_entry_test.updateTaken();
	bht_entry_test.isTakenAutoReplace(20000);
	cout <<"0 | " << bht_entry_test.getEntryStringDecimal() << " |" << endl;
	
	branch_history_table bhttest(4);
	bhttest.printTableDecimal();
	cout << endl;
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(0) << endl;
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(1) << endl;
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(2) << endl;
	bhttest.printTableDecimal();
	cout << endl;
	bhttest.updateTaken(0);
	bhttest.updateTaken(0);
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(0) << endl;
	bhttest.updateTaken(1);
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(0) << endl;
	bhttest.updateTaken(2);
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(0) << endl;
	bhttest.printTableDecimal();
	cout << endl;
	cout<< "Current Status: " << bhttest.isTakenAutoReplace(16384) << endl;
	bhttest.printTableDecimal();
	cout << endl;
	
	
	branch_history_register_table bhsrttest(4,8);
	bhsrttest.printTableBinary();
	cout << endl;
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(1);
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(0);
	bhsrttest.updateTaken(2);
	bhsrttest.printTableBinary();
	cout << endl;
	bhsrttest.updateNotTaken(0);
	bhsrttest.updateNotTaken(0);
	bhsrttest.updateNotTaken(0);
	bhsrttest.printTableBinary();
	cout << endl;
	
	pattern_history_table phttest(4);
	phttest.printTable();
	cout << endl;
	phttest.updateTaken(0);
	phttest.updateTaken(0);
	phttest.updateTaken(1);
	phttest.updateTaken(2);
	phttest.updateTaken(2);
	phttest.printTable();
	cout << endl;
	phttest.updateNotTaken(0);
	phttest.updateNotTaken(0);
	phttest.printTable();
	cout << endl;
	
	
	//cout << "Something is " << newsomething.getSum();
    return 0;
}