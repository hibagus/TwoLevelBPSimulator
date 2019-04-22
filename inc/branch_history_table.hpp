/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef BRANCH_HISTORY_TABLE_H
#define BRANCH_HISTORY_TABLE_H

#include "branch_history_table_entry.hpp"
#include "saturating_counter.hpp"

class branch_history_table
{
public:
    branch_history_table(unsigned int numofEntryinLogTwo);
    branch_history_table(unsigned int numofEntryinLogTwo, counter_status initState);
    branch_history_table(unsigned int numofEntryinLogTwo, unsigned int initAddress);
    branch_history_table(unsigned int numofEntryinLogTwo, unsigned int initAddress, counter_status initState);
    
    void updateTaken(unsigned int address);
    void updateNotTaken(unsigned int address);
    
    bool isTaken(unsigned int address);
    bool isNotTaken(unsigned int address);
    bool isTakenAutoReplace(unsigned int address);
    bool isTakenAutoReplace(counter_status initState, unsigned int address);
    bool isNotTakenAutoReplace(unsigned int address);	
    bool isNotTakenAutoReplace(counter_status initState, unsigned int address);
    
    void reset(unsigned int numofEntryinLogTwo);
    void reset(unsigned int numofEntryinLogTwo, counter_status initState);
    void reset(unsigned int numofEntryinLogTwo, unsigned int initAddress);
    void reset(unsigned int numofEntryinLogTwo, unsigned int initAddress, counter_status initState);
    
    branch_history_table_entry getEntrybyAddress(unsigned int address);
    branch_history_table_entry getEntrybyIndex(unsigned int index);
    unsigned int getNumofEntry();
    unsigned int getnumofEntryinLogTwo();
    void printTableDecimal();
    void printTableHex();
	
private:
    unsigned int               _numofEntryinLogTwo;
    unsigned int               _numofEntry;
    branch_history_table_entry* _bht;
    unsigned int calculateIndex(unsigned int address);
};
#endif