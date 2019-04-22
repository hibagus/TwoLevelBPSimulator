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
#include "two_level_predictor.hpp"

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
	
	cout <<"GAg BP Test" <<endl;
	two_level_predictor BPred_GAg(0,0,4,0);
	//BPred_GAg.printBranchPredictorContents();
	BPred_GAg.updateTaken(2);
	BPred_GAg.updateTaken(3);
	BPred_GAg.updateTaken(130);
	BPred_GAg.updateTaken(258);
	BPred_GAg.updateTaken(514);
	BPred_GAg.printBranchPredictorContents();
	
	cout <<"GAs BP Test" <<endl;
	two_level_predictor BPred_GAs(0,2,4,1);
	//BPred_GAs.printBranchPredictorContents();
	BPred_GAs.updateTaken(2);
	BPred_GAs.updateTaken(3);
	BPred_GAs.updateTaken(130);
	BPred_GAs.updateTaken(258);
    BPred_GAs.updateTaken(514);
	BPred_GAs.printBranchPredictorContents();
	
	cout <<"GAp BP Test" <<endl;
	two_level_predictor BPred_GAp(0,2,4,0);
	//BPred_GAp.printBranchPredictorContents();
	BPred_GAp.updateTaken(2);
	BPred_GAp.updateTaken(3);
	BPred_GAp.updateTaken(130);
	BPred_GAp.updateTaken(258);
	BPred_GAp.updateTaken(514);
	BPred_GAp.printBranchPredictorContents();
	
	cout <<"SAg BP Test" <<endl;
	two_level_predictor BPred_SAg(2,0,4,1);
	//BPred_SAg.printBranchPredictorContents();
	BPred_SAg.updateTaken(2);
	BPred_SAg.updateTaken(3);
	BPred_SAg.updateTaken(130);
	BPred_SAg.updateTaken(258);
	BPred_SAg.updateTaken(514);
	BPred_SAg.printBranchPredictorContents();
	
	cout <<"SAs BP Test" <<endl;
	two_level_predictor BPred_SAs(2,1,4,1);
	//BPred_SAs.printBranchPredictorContents();
	BPred_SAs.updateTaken(2);
	BPred_SAs.updateTaken(3);
	BPred_SAs.updateTaken(130);
	BPred_SAs.updateTaken(258);
	BPred_SAs.updateTaken(514);
	BPred_SAs.printBranchPredictorContents();
	
	cout <<"SAp BP Test" <<endl;
	two_level_predictor BPred_SAp(2,2,4,1);
	//BPred_SAp.printBranchPredictorContents();
	BPred_SAp.updateTaken(2);
	BPred_SAp.updateTaken(3);
	BPred_SAp.updateTaken(130);
	BPred_SAp.updateTaken(258);
	BPred_SAp.updateTaken(514);
	BPred_SAp.printBranchPredictorContents();
	
	cout <<"PAg BP Test" <<endl;
	two_level_predictor BPred_PAg(2,0,4,0);
	//BPred_PAg.printBranchPredictorContents();
	BPred_PAg.updateTaken(2);
	BPred_PAg.updateTaken(3);
	BPred_PAg.updateTaken(130);
	BPred_PAg.updateTaken(258);
	BPred_PAg.updateTaken(514);
	BPred_PAg.printBranchPredictorContents();
	
	cout <<"PAs BP Test" <<endl;
	two_level_predictor BPred_PAs(2,1,4,0);
	//BPred_PAs.printBranchPredictorContents();
	BPred_PAs.updateTaken(2);
	BPred_PAs.updateTaken(3);
	BPred_PAs.updateTaken(130);
	BPred_PAs.updateTaken(258);
	BPred_PAs.updateTaken(514);
	BPred_PAs.printBranchPredictorContents();
	
	cout <<"PAp BP Test" <<endl;
	two_level_predictor BPred_PAp(2,2,4,0);
	//BPred_PAp.printBranchPredictorContents();
	BPred_PAp.updateTaken(4);
	BPred_PAp.updateTaken(5);
	BPred_PAp.updateTaken(132);
	BPred_PAp.updateTaken(260);
	BPred_PAp.updateTaken(516);
	BPred_PAp.printBranchPredictorContents();
	
	//cout << "Something is " << newsomething.getSum();
    return 0;
}