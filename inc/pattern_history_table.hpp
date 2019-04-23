/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef PATTERN_HISTORY_TABLE_H
#define PATTERN_HISTORY_TABLE_H

#include <string>
#include "saturating_counter.hpp"

class pattern_history_table
{
public:
    pattern_history_table();
    pattern_history_table(unsigned int numofEntryinLogTwo);
    pattern_history_table(unsigned int numofEntryinLogTwo, counter_status counterInitial);
    
    void updateTaken(unsigned int tableIndex);
    void updateNotTaken(unsigned int tableIndex);
    
    void reset(unsigned int numofEntryinLogTwo);
    void reset(unsigned int numofEntryinLogTwo, counter_status counterInitial);
    
    saturating_counter getEntrybyIndex(unsigned int tableIndex);
    unsigned int getNumofEntry();
    unsigned int getnumofEntryinLogTwo();
    void printTable();

private:   
    unsigned int               _numofEntryinLogTwo;
    unsigned int               _numofEntry;
    saturating_counter*        _pht;
};
#endif