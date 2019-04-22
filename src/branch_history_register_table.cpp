/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "branch_history_register_table.hpp"
#include "branch_history_register.hpp"
#include <math.h> 
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

branch_history_register_table::branch_history_register_table(unsigned int numofEntryinLogTwo)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];
}
branch_history_register_table::branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned int registerLength)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerLength);		
	}
}
branch_history_register_table::branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned int registerInitial, unsigned int registerLength)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerInitial, registerLength);		
	}
}
branch_history_register_table::branch_history_register_table(unsigned int numofEntryinLogTwo, unsigned long long registerInitial, unsigned int registerLength)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerInitial, registerLength);		
	}
}

void branch_history_register_table::updateTaken(unsigned int tableIndex)
{
	this->_bhsrt[tableIndex].updateTaken();
}

void branch_history_register_table::updateNotTaken(unsigned int tableIndex)
{
	this->_bhsrt[tableIndex].updateNotTaken();
}

void branch_history_register_table::reset(unsigned int numofEntryinLogTwo)
{
	delete this->_bhsrt;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];
}
void branch_history_register_table::reset(unsigned int numofEntryinLogTwo, unsigned int registerLength)
{
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerLength);		
	}
}
void branch_history_register_table::reset(unsigned int numofEntryinLogTwo, unsigned int registerInitial, unsigned int registerLength)
{
	delete this->_bhsrt;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerInitial, registerLength);		
	}
}
void branch_history_register_table::reset(unsigned int numofEntryinLogTwo, unsigned long long registerInitial, unsigned int registerLength)
{
	delete this->_bhsrt;
	this->_numofEntryinLogTwo = numofEntryinLogTwo;
	this->_numofEntry = pow(2,numofEntryinLogTwo);
	this->_bhsrt = new branch_history_register[this->_numofEntry];	
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		this->_bhsrt[i].reset(registerInitial, registerLength);		
	}
}

branch_history_register branch_history_register_table::getEntrybyIndex(unsigned int tableIndex)
{
	return this->_bhsrt[tableIndex];
}
unsigned int branch_history_register_table::getNumofEntry()
{
	return this->_numofEntry;
}
unsigned int branch_history_register_table::getnumofEntryinLogTwo()
{
	return this->_numofEntryinLogTwo;
}

void branch_history_register_table::printTableBinary()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream1;
        stream1 << std::setw(10) << std::setfill('0') << std::dec << i;
		std::cout << "| " << stream1.str() << " | " << this->_bhsrt[i].getBinaryString() << " |" <<std::endl;
	}
}
void branch_history_register_table::printTableDecimal()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream1;
		std::stringstream stream2;
        stream1 << std::setw(10) << std::setfill('0') << std::dec << i;
		stream2 << std::setw(10) << std::setfill('0') << std::dec << this->_bhsrt[i].getLongValue();
		std::cout << "| " << stream1.str() << " | " << stream2.str() << " |" <<std::endl;
	}
}
void branch_history_register_table::printTableHex()
{
	for(unsigned int i=0; i<this->_numofEntry;i++)
	{
		std::stringstream stream1;
		std::stringstream stream2;
        stream1 << std::setw(8) << std::setfill('0') << std::dec << i;
		stream2 << std::setw(8) << std::setfill('0') << "0x" << std::hex << this->_bhsrt[i].getLongValue();
		std::cout << "| " << stream1.str() << " | " << stream2.str() << " |" <<std::endl;
	}
}
