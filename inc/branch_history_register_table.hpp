/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef BRANCH_HISTORY_REGISTER_TABLE_H
#define BRANCH_HISTORY_REGISTER_TABLE_H

#include <string>
#include "branch_history_register.hpp"


class branch_history_register_table
{
public:
    branch_history_register_table(unsigned int numofEntryinLogTwo);
    branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned int registerLength);
    branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned int registerInitial, unsigned int registerLength);
    branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned long long registerInitial, unsigned int registerLength);
    
    void updateTaken(unsigned int tableIndex);
    void updateNotTaken(unsigned int tableIndex);
    
    void reset(unsigned int numofEntryinLogTwo);
    void reset(unsigned int numofEntryinLogTwo, unsigned int registerLength);
    void reset(unsigned int numofEntryinLogTwo, unsigned int registerInitial, unsigned int registerLength);
    void reset(unsigned int numofEntryinLogTwo, unsigned long long registerInitial, unsigned int registerLength);
    
    branch_history_register getEntrybyIndex(unsigned int tableIndex);
    unsigned int getNumofEntry();
    unsigned int getnumofEntryinLogTwo();
    void printTableBinary();
    void printTableDecimal();
    void printTableHex();

private:   
    unsigned int               _numofEntryinLogTwo;
    unsigned int               _numofEntry;
    branch_history_register* _bhsrt;
};
#endif