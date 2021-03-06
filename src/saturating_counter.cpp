/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "saturating_counter.hpp"
#include <string>

saturating_counter::saturating_counter()
{
	this->_status = weak_nottaken;
}

saturating_counter::saturating_counter(counter_status initial)
{
	this->_status = initial;
}

void saturating_counter::updateTaken()
{
	switch(this->_status)
	{
		case strong_taken :
		{
			this->_status = strong_taken;
			break;
		}
		case weak_taken :
		{
			this->_status = strong_taken;
			break;
		}
		case weak_nottaken :
		{
			this->_status = weak_taken;
			break;
		}
		case strong_nottaken :
		{
			this->_status = weak_nottaken;
			break;
		}
	}
}

void saturating_counter::updateNotTaken()
{
	switch(this->_status)
	{
		case strong_taken :
		{
			this->_status = weak_taken;
			break;
		}
		case weak_taken :
		{
			this->_status = weak_nottaken;
			break;
		}
		case weak_nottaken :
		{
			this->_status = strong_nottaken;
			break;
		}
		case strong_nottaken :
		{
			this->_status = strong_nottaken;
			break;
		}
	}
}

void saturating_counter::reset()
{
	this->_status = weak_nottaken;
}

void saturating_counter::reset(counter_status initial)
{
	this->_status = initial;
}

bool saturating_counter::isTaken()
{
	if((this->_status==strong_taken)||(this->_status==weak_taken))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool saturating_counter::isNotTaken()
{
	if((this->_status==strong_nottaken)||(this->_status==weak_nottaken))
	{
		return true;
	}
	else
	{
		return false;
	}
}

counter_status saturating_counter::getCounterStatus()
{
	return this->_status;
}

std::string saturating_counter::getCounterStatusString()
{
	std::string output;
	switch(this->_status)
	{
		case strong_taken :
		{
			output = "T";
			break;
		}
		case weak_taken :
		{
			output = "t";
			break;
		}
		case weak_nottaken :
		{
			output = "n";
			break;
		}
		case strong_nottaken :
		{
			output = "N";
			break;
		}
	}
	return output;
}