/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/



#ifndef TRACE_FILE_PARSER_H
#define TRACE_FILE_PARSER_H

#include<string>
#include<fstream>
#include "trace_entry.hpp"

class trace_file_parser
{
public:
    trace_file_parser();
	trace_file_parser(std::string filename);
	void reset(std::string filename);
	trace_entry getCurrentEntry();
	trace_entry getNextEntry();
	std::string getCurrentFileName();
	std::string getCurrentTraceEntryString();
	unsigned long long getCurrentLineNumber();
	bool isTraceFileEnded();
	bool isTraceFileGood();
private:
    std::ifstream _tracefile;
	trace_entry _currenttraceentry;
	std::string _filename;
	unsigned long long _linenumber;
	
};
#endif