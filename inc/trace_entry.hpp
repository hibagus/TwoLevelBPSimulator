/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef TRACE_ENTRY_H
#define TRACE_ENTRY_H

class trace_entry
{
public:
	trace_entry(unsigned int branch_addr, bool branch_outcome);
    unsigned int getBranchAddr();
    bool getBranchOutcome();
private:
    unsigned int branch_addr ;
    bool         branch_outcome;	
};
#endif