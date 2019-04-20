/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "trace_entry.hpp"

trace_entry::trace_entry(unsigned int branch_addr, bool branch_outcome)
{
    this->_branch_addr    = branch_addr;
    this->_branch_outcome = branch_outcome;
}

unsigned int trace_entry::getBranchAddr()
{
	return this->_branch_addr;
}

bool trace_entry::getBranchOutcome()
{
	return this->_branch_outcome;
}

void trace_entry::reset(unsigned int branch_addr, bool branch_outcome)
{
	this->_branch_addr    = branch_addr;
    this->_branch_outcome = branch_outcome;
}