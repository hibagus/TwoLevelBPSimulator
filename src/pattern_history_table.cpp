/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "pattern_history_table.hpp"
#include "saturating_counter.hpp"

#include <math.h> 
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

pattern_history_table::pattern_history_table()
{
	this->_numofEntryinLogTwo = 0;
	this->_numofEntry = 1;
	this->_pht = new saturating_counter[this->_numofEntry];
}

pattern_history_table::pattern_history_table(unsigned int numofEntryinLogTwo)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_pht = new saturating_counter[this->_numofEntry];
}
pattern_history_table::pattern_history_table(unsigned int numofEntryinLogTwo, counter_status counterInitial)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_pht = new saturating_counter[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_pht[i].reset(counterInitial);		
	}
}

void pattern_history_table::updateTaken(unsigned int tableIndex)
{
	this->_pht[tableIndex].updateTaken();
}
void pattern_history_table::updateNotTaken(unsigned int tableIndex)
{
	this->_pht[tableIndex].updateNotTaken();
}

void pattern_history_table::reset(unsigned int numofEntryinLogTwo)
{
	delete this->_pht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_pht = new saturating_counter[this->_numofEntry];
}
void pattern_history_table::reset(unsigned int numofEntryinLogTwo, counter_status counterInitial)
{
	delete this->_pht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_pht = new saturating_counter[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_pht[i].reset(counterInitial);		
	}
}
   
saturating_counter pattern_history_table::getEntrybyIndex(unsigned int tableIndex)
{
	return this->_pht[tableIndex];
}

unsigned int pattern_history_table::getNumofEntry()
{
	return this->_numofEntry;
}
unsigned int pattern_history_table::getnumofEntryinLogTwo()
{
	return this->_numofEntryinLogTwo;
}
void pattern_history_table::printTable()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream1;
        stream1 << std::setw(10) << std::setfill('0') << std::dec << i;
		std::cout << "| " << stream1.str() << " | " << this->_pht[i].getCounterStatusString() << " |" <<std::endl;
	}
}