/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#ifndef TWO_LEVEL_PREDICTOR_H
#define TWO_LEVEL_PREDICTOR_H

#include <string>
#include "pattern_history_table.hpp"
#include "branch_history_register_table.hpp"

enum two_level_predictor_type
{
	GAg,
	GAs,
	GAp,
	SAg,
	SAs,
	SAp,
	PAg,
	PAs,
	PAp,
	NAn,
};

class two_level_predictor
{
public:
    static bool isParameterValid(int i, int j, int k, int s);
    static std::string getParameterErrorInfo(int i, int j, int k, int s);
    static std::string getPredictorTypeString(int i, int j, int k, int s);
    static two_level_predictor_type getPredictorType(unsigned int i, unsigned int j, unsigned int k, unsigned int s);
    
    two_level_predictor(unsigned int i, unsigned int j, unsigned int k, unsigned int s);
    void reset(unsigned int i, unsigned int j, unsigned int k, unsigned int s);
    void updateTaken(unsigned int address);
    void updateNotTaken(unsigned int address);
    bool isPredictTaken(unsigned int address);
    bool isPredictNotTaken(unsigned int address);
    unsigned int getNumofBHSREntryinLogTwo();
    unsigned int getNumofPHTinLogTwo();
    unsigned int getLengthofBHSR();
    unsigned int getNumofSetinLogTwo();
    unsigned int getNumofPHTEntryinLogTwo();
    
    unsigned int getNumofBHSREntry();
    unsigned int getNumofPHT();
    unsigned int getNumofPHTEntry();
    unsigned int getNumofSet();
    
    two_level_predictor_type       getPredictorType();
    pattern_history_table          getPatternHistoryTable(unsigned int phtindex);
    branch_history_register_table  getBranchHistoryRegisterTable();
    
    unsigned int calculateHardwareCostinBit();
    void printBranchPredictorContents();
	
   
private:
    unsigned int _numofBHSREntryinLogTwo; //i
    unsigned int _numofPHTinLogTwo; //j
    unsigned int _lengthofBHSR; //k
    unsigned int _numofSetinLogTwo; //s
    
    unsigned int _numofBHSREntry;
    unsigned int _numofPHT;
    unsigned int _numofPHTEntry;
    unsigned int _numofSet;
    
    unsigned int _i;
    unsigned int _j;
    unsigned int _k;
    unsigned int _s;
    
    two_level_predictor_type _predictorType;
    unsigned int _calculateBHRTIndex(unsigned int address);
    unsigned int _calculatePHTSIndex(unsigned int address);
    
    pattern_history_table*        _phts;
    branch_history_register_table _bhrt;	
};
#endif