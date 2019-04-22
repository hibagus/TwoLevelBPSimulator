/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "branch_history_register.hpp"
#include <bitset>
#include <string>


branch_history_register::branch_history_register()
{
	this->_value = 0;
	this->_length= 1;
}

branch_history_register::branch_history_register(unsigned int length)
{
	this->_value = 0;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
	
}

branch_history_register::branch_history_register(unsigned int initial, unsigned int length)
{
	this->_value = initial;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
	this->_truncateMSB();
}

branch_history_register::branch_history_register(unsigned long long initial, unsigned int length)
{
	this->_value = initial;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
	this->_truncateMSB();
}

void branch_history_register::updateTaken()
{
	this->_value = (this->_value << 1) | 0x01;
	this->_truncateMSB();
}

void branch_history_register::updateNotTaken()
{
	this->_value = (this->_value << 1) | 0x00;
	this->_truncateMSB();
}

void branch_history_register::reset()
{
	this->_value = 0;
	this->_length= 1;
}

void branch_history_register::reset(unsigned int length)
{
	this->_value = 0;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
}

void branch_history_register::reset(unsigned int initial, unsigned int length)
{
	this->_value = initial;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
	this->_truncateMSB();
}

void branch_history_register::reset(unsigned long long initial, unsigned int length)
{
	this->_value = initial;
	if(length==0)
	{
		this->_length= 1;
	}
	else
	{
		this->_length= length;
	}
	this->_truncateMSB();
}

unsigned long long branch_history_register::getLongValue()
{
	return this->_value;
}

unsigned int branch_history_register::getIntValue()
{
	unsigned int mask = 0;
	mask = ~mask;
	unsigned int truncatedvalue = this->_value & mask;
	return truncatedvalue;
}

unsigned int branch_history_register::getLength()
{
	return this->_length;
}

std::string branch_history_register::getBinaryString()
{
	std::string bitstring = std::bitset<64>(this->_value).to_string();
	return bitstring.substr(64-this->_length,63);
}

void branch_history_register::_truncateMSB()
{
	unsigned long long mask = 0;
	mask = ~((~mask)<<this->_length);
	this->_value = _value & mask;
}
