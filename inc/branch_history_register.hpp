/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef BRANCH_HISTORY_REGISTER_H
#define BRANCH_HISTORY_REGISTER_H

#include <string>

class branch_history_register
{
public:
    branch_history_register();
    branch_history_register(unsigned int length);
	branch_history_register(unsigned int initial, unsigned int length);
	branch_history_register(unsigned long long initial, unsigned int length);
    void updateTaken();
	void updateNotTaken();
	void reset();
	void reset(unsigned int initial);
	void reset(unsigned long long initial);
	unsigned long long getLongValue();
	unsigned int getIntValue();
	unsigned int getLength();
	std::string getBinaryString();
private:
    unsigned long long _value;
	unsigned int _length;
	void _truncateMSB();
};
#endif