/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef BRANCH_HISTORY_TABLE_ENTRY_H
#define BRANCH_HISTORY_TABLE_ENTRY_H

#include "saturating_counter.hpp"

class branch_history_table_entry
{
public:
    branch_history_table_entry();
	branch_history_table_entry(counter_status initState);
	branch_history_table_entry(unsigned int initAddress);
	branch_history_table_entry(unsigned int initAddress, counter_status initialState);
    
	void updateTaken();
	void updateNotTaken();
	
	bool isTaken(unsigned int address);
	bool isNotTaken(unsigned int address);
	bool isTakenAutoReplace(unsigned int address);
	bool isTakenAutoReplace(counter_status initState, unsigned int address);
	bool isNotTakenAutoReplace(unsigned int address);	
	bool isNotTakenAutoReplace(counter_status initState, unsigned int address);

	void reset();
	void reset(counter_status initState);
	void reset(unsigned int initAddress);
	void reset(unsigned int initAddress, counter_status initialState);
	
	saturating_counter getCounter();
	unsigned int getCurrentAddress();
	std::string getEntryStringDecimal();
	std::string getEntryStringHex();
private:
	unsigned int       _address;
	saturating_counter _counter;
};
#endif