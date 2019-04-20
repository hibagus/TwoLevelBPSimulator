/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef SATURATING_COUNTER_H
#define SATURATING_COUNTER_H

#include <string>

enum counter_status
{
	strong_taken,
	weak_taken,
	weak_nottaken,
	strong_nottaken,
};


class saturating_counter
{
public:
    saturating_counter();
	saturating_counter(counter_status initial);
    void updateTaken();
	void updateNotTaken();
	void reset();
	void reset(counter_status initial);
	bool isTaken();
	bool isNotTaken();
	bool getCounterStatus();
	std::string getCounterStatusString();
private:
    counter_status _status;
};
#endif