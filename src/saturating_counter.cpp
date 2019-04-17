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

saturating_counter::saturating_counter(counter_status initial)
{
	status = initial;
}

void saturating_counter::incrementCounter()
{
	switch(status)
	{
		case strong_taken :
		{
			status = strong_taken;
			break;
		}
		case weak_taken :
		{
			status = strong_taken;
			break;
		}
		case weak_nottaken :
		{
			status = weak_taken;
			break;
		}
		case strong_nottaken :
		{
			status = weak_nottaken;
			break;
		}
	}
}

void saturating_counter::decrementCounter()
{
	switch(status)
	{
		case strong_taken :
		{
			status = weak_taken;
			break;
		}
		case weak_taken :
		{
			status = weak_nottaken;
			break;
		}
		case weak_nottaken :
		{
			status = strong_nottaken;
			break;
		}
		case strong_nottaken :
		{
			status = strong_nottaken;
			break;
		}
	}
}
bool saturating_counter::isTaken()
{
	if((status==strong_taken)||(status==weak_taken))
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
	if((status==strong_nottaken)||(status==weak_nottaken))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool saturating_counter::getCounterStatus()
{
	return status;
}
