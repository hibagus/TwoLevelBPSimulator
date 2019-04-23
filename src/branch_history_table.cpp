/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "branch_history_table.hpp"
#include "branch_history_table_entry.hpp"
#include <math.h> 
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

branch_history_table::branch_history_table(unsigned int numofEntryinLogTwo)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
}

branch_history_table::branch_history_table(unsigned int numofEntryinLogTwo, counter_status initState)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initState);		
	}
}

branch_history_table::branch_history_table(unsigned int numofEntryinLogTwo, unsigned int initAddress)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initAddress);		
	}
}

branch_history_table::branch_history_table(unsigned int numofEntryinLogTwo, unsigned int initAddress, counter_status initState)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initAddress,initState);		
	}
}

void branch_history_table::updateTaken(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	this->_bht[index].updateTaken();
}

void branch_history_table::updateNotTaken(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	this->_bht[index].updateNotTaken();
}

bool branch_history_table::isTaken(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isTaken(address);
}

bool branch_history_table::isNotTaken(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isNotTaken(address);
}

bool branch_history_table::isTakenAutoReplace(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isTakenAutoReplace(address);
}

bool branch_history_table::isTakenAutoReplace(counter_status initState, unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isTakenAutoReplace(initState,address);
}

bool branch_history_table::isNotTakenAutoReplace(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isNotTakenAutoReplace(address);
}	

bool branch_history_table::isNotTakenAutoReplace(counter_status initState, unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index].isNotTakenAutoReplace(initState,address);
}

void branch_history_table::reset(unsigned int numofEntryinLogTwo)
{
	delete this->_bht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
}

void branch_history_table::reset(unsigned int numofEntryinLogTwo, counter_status initState)
{
	delete this->_bht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initState);		
	}
}

void branch_history_table::reset(unsigned int numofEntryinLogTwo, unsigned int initAddress)
{
	delete this->_bht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initAddress);		
	}
}

void branch_history_table::reset(unsigned int numofEntryinLogTwo, unsigned int initAddress, counter_status initState)
{
	delete this->_bht;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bht = new branch_history_table_entry[this->_numofEntry];
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bht[i].reset(initAddress,initState);		
	}
}

branch_history_table_entry branch_history_table::getEntrybyAddress(unsigned int address)
{
	unsigned int index = this->calculateIndex(address);
	return this->_bht[index];
}

branch_history_table_entry branch_history_table::getEntrybyIndex(unsigned int index)
{
	return this->_bht[index];
}

unsigned int branch_history_table::getNumofEntry()
{
	return _numofEntry;
}

unsigned int branch_history_table::getnumofEntryinLogTwo()
{
	return _numofEntryinLogTwo;
}

void branch_history_table::printTableDecimal()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream;
        stream << std::setw(10) << std::setfill('0') << std::dec << i;
		std::cout << "| " << stream.str() << " | " << this->_bht[i].getEntryStringDecimal() << " |" <<std::endl;
	}
}

void branch_history_table::printTableHex()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream;
        stream << std::setw(10) << std::setfill('0') << std::dec << i;
		std::cout << "| " << stream.str() << " | " << this->_bht[i].getEntryStringHex() << " |"  << std::endl;
	}
}

unsigned int branch_history_table::calculateIndex(unsigned int address)
{
	unsigned int mask = 0;
	mask = ~((~mask)<<this->_numofEntryinLogTwo);
	return address & mask;
}

unsigned int branch_history_table::calculateHardwareCost()
{
	return this->_numofEntry * 2;
}