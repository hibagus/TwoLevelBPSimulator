/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "branch_history_table_entry.hpp"
#include "saturating_counter.hpp"
#include <string>
#include <sstream>
#include <iomanip>

branch_history_table_entry::branch_history_table_entry()
: _counter()
{
	this->_address = 0;
}

branch_history_table_entry::branch_history_table_entry(counter_status initState)
: _counter(initState)
{
	this->_address = 0;
}

branch_history_table_entry::branch_history_table_entry(unsigned int initAddress)
: _counter()
{
	this->_address = initAddress;
}

branch_history_table_entry::branch_history_table_entry(unsigned int initAddress, counter_status initialState)
: _counter(initialState)
{
	this->_address = initAddress;
}

void branch_history_table_entry::updateTaken()
{
	this->_counter.updateTaken();
}
void branch_history_table_entry::updateNotTaken()
{
	this->_counter.updateNotTaken();
}

bool branch_history_table_entry::isTaken(unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isTaken();
	}
	else
	{
		return false;
	}
}

bool branch_history_table_entry::isNotTaken(unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isNotTaken();
	}
	else
	{
		return true;
	}
}

bool branch_history_table_entry::isTakenAutoReplace(unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isTaken();
	}
	else
	{
		this->reset(address);
		return false;
	}
}

bool branch_history_table_entry::isTakenAutoReplace(counter_status initState, unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isTaken();
	}
	else
	{
		this->reset(address, initState);
		return false;
	}
}

bool branch_history_table_entry::isNotTakenAutoReplace(unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isNotTaken();
	}
	else
	{
		this->reset(address);
		return true;
	}
}

bool branch_history_table_entry::isNotTakenAutoReplace(counter_status initState, unsigned int address)
{
	if(this->_address==address)
	{
		return this->_counter.isNotTaken();
	}
	else
	{
		this->reset(address, initState);
		return true;
	}
}

void branch_history_table_entry::reset()
{
	this->_counter.reset();
	this->_address = 0;	
}

void branch_history_table_entry::reset(counter_status initState)
{
	this->_counter.reset(initState);
	this->_address = 0;	
}

void branch_history_table_entry::reset(unsigned int initAddress)
{
	this->_counter.reset();
	this->_address = initAddress;	
}

void branch_history_table_entry::reset(unsigned int initAddress, counter_status initialState)
{
	this->_counter.reset(initialState);
	this->_address = initAddress;
}

saturating_counter branch_history_table_entry::getCounter()
{
	return this->_counter;
}

unsigned int branch_history_table_entry::getCurrentAddress()
{
	return this->_address;
}

std::string branch_history_table_entry::getEntryStringDecimal()
{
	std::stringstream stream;
    stream << std::setw(10) << std::setfill('0') << std::dec << this->_address;
    std::string temp( stream.str() );	
	std::string result = temp + " | " + this->_counter.getCounterStatusString(); 
	return result;
}

std::string branch_history_table_entry::getEntryStringHex()
{
	std::stringstream stream;
    stream << std::setw(8) << std::setfill('0') << "0x" << std::hex << this->_address;
    std::string temp( stream.str() );	
	std::string result = temp + " | " + this->_counter.getCounterStatusString(); 
	return result;
}


