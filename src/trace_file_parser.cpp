/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "trace_file_parser.hpp"
#include "trace_entry.hpp"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

trace_file_parser::trace_file_parser(std::string filename)
: _currenttraceentry(0,0)
{
  this->_filename = filename;
  this->_tracefile.open(filename.c_str(),std::ifstream::in);
  this->_linenumber = 0;
}

void trace_file_parser::reset(std::string filename)
{
	this->_tracefile.close();
	this->_filename = filename;
	this->_tracefile.open(filename.c_str(), std::ifstream::in);
	this->_linenumber = 0;
}

trace_entry trace_file_parser::getCurrentEntry()
{
	return _currenttraceentry;
}

trace_entry trace_file_parser::getNextEntry()
{
	unsigned int branchaddress;
	bool branchoutcome;
	
	if(this->_tracefile >> branchaddress >> branchoutcome)
	{
		_currenttraceentry.reset(branchaddress, branchoutcome);
		this->_linenumber++;
	}
	else
	{
		_currenttraceentry.reset(0,0);
	}
	return _currenttraceentry;
}

std::string trace_file_parser::getCurrentFileName()
{
	return this->_filename;
}

std::string trace_file_parser::getCurrentTraceEntryString()
{
	std::stringstream ss;
	ss << this->_currenttraceentry.getBranchAddr() << " " << this->_currenttraceentry.getBranchOutcome();
	return ss.str();
}

unsigned long long trace_file_parser::getCurrentLineNumber()
{
	return this->_linenumber;
}

bool trace_file_parser::isTraceFileEnded()
{
	return this->_tracefile.eof();
}

bool trace_file_parser::isTraceFileGood()
{
	return this->_tracefile.good();
}