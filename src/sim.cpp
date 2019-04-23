/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include <iostream>
#include <sstream>
#include "trace_file_parser.hpp"
#include "branch_history_table.hpp"
#include "two_level_predictor.hpp"

using namespace std;
void printHelp(string exename);

int main(int argc, char *argv[]) 
{
	// Variables
	trace_file_parser tracefile("");
	int _r, _i, _j, _k, _s;
	unsigned int stats_numofBranchPredicted = 0;
	unsigned int stats_numofCorrectPrediction= 0;
	unsigned int stats_numofWrongPrediction = 0;
	
	// Algorithm
	cout<< "Hanin Two-Level Branch Predictor Simulator v0.1 (2019 April 01)" << endl;
	cout<< "(C) 2019 Bagus Hanindhito (hanindhito@bagus.my.id)" << endl;
	//cout<< endl;
	if(argc==3)
	{
		// One-Level Branch Predictor
		// Check Tracefile
		tracefile.reset(argv[1]);
		if(!tracefile.isTraceFileGood())
		{
			cout << "[ERROR] Cannot open trace file to simulate!" << endl;
			return -1;
		}
		
		// Check and convert arguments
		std::istringstream ss1(argv[2]); 
		if (!(ss1 >> _r))
		{
			cout << "[ERROR] Invalid r argument!" << endl;
			return -1;
		}
		
		// Check r requirement
		if(_r<0)
		{
			cout << "[ERROR] Invalid r argument. The r value must be positive." << endl;
			return -1;
		}
		
		//Constructing BHT
		branch_history_table _bht(_r);
		cout << "=====================================================" << endl;
		cout << "One Level Branch Predictor Simulation                " << endl;
		cout << "Model                                    : BHT       " << endl;
		cout << "Number of Entry                          : " << _bht.getNumofEntry() << endl;
		cout << "Hardware Cost (excluding tag fields)     : " << _bht.calculateHardwareCost() << endl;
		cout << "=====================================================" << endl;
		
		while(!tracefile.isTraceFileEnded())
		{
			tracefile.getNextEntry();
			// get prediction
			bool prediction = _bht.isTakenAutoReplace(tracefile.getCurrentEntry().getBranchAddr());
			bool outcome    = tracefile.getCurrentEntry().getBranchOutcome();
			if(prediction==outcome)
			{
				stats_numofCorrectPrediction++;
			}
			else
			{
				stats_numofWrongPrediction++;
			}					
			//update predictor
			if(outcome)
			{
				_bht.updateTaken(tracefile.getCurrentEntry().getBranchAddr());
			}
			else
			{
				_bht.updateNotTaken(tracefile.getCurrentEntry().getBranchAddr());
			}
			
			stats_numofBranchPredicted++;
		}
		
		// Print Stats
		double accuracy = (stats_numofCorrectPrediction/(double)stats_numofBranchPredicted) * 100;
		cout << "Simulation Statistics" << endl;
		cout << "Number of Predicted Branch               : " << stats_numofBranchPredicted << endl;
		cout << "Number of Correct Prediction             : " << stats_numofCorrectPrediction << endl;
		cout << "Number of Wrong Prediction               : " << stats_numofWrongPrediction   << endl;
		cout << "Branch Prediction Accuracy               : " << accuracy << "%" << endl;
		cout << "=====================================================" << endl;
		
	}
	else if (argc==6)
	{
		// Two-Level Branch Predictor
		// Check Tracefile
		tracefile.reset(argv[1]);
		if(!tracefile.isTraceFileGood())
		{
			cout << "[ERROR] Cannot open trace file to simulate!" << endl;
			return -1;
		}
		
		// Check and convert arguments
		std::istringstream ss1(argv[2]), ss2(argv[3]), ss3(argv[4]), ss4(argv[5]); 
		if (!(ss1 >> _i))
		{
			cout << "[ERROR] Invalid i argument!" << endl;
			return -1;
		}
		if (!(ss2 >> _j))
		{
			cout << "[ERROR] Invalid j argument!" << endl;
			return -1;
		}
		if (!(ss3 >> _k))
		{
			cout << "[ERROR] Invalid k argument!" << endl;
			return -1;
		}
		if (!(ss4 >> _s))
		{
			cout << "[ERROR] Invalid s argument!" << endl;
			return -1;
		}
		
		// check parameter requirements
		if(!two_level_predictor::isParameterValid(_i, _j, _k, _s))
		{
			cout << "[ERROR] " << two_level_predictor::getParameterErrorInfo(_i, _j, _k, _s) << endl;
			return -1;
		}
		
		
		//Constructing BP
		two_level_predictor _tlbp(_i, _j, _k, _s);
		cout << "=====================================================" << endl;
		cout << "Two Level Branch Predictor Simulation                " << endl;
		cout << "Model                                    : " << two_level_predictor::getPredictorTypeString(_i, _j, _k, _s) << endl;
		cout << "Number of Branch History Shift Registers : " << _tlbp.getNumofBHSREntry()          << endl;
		cout << "Length of Branch History Shift Registers : " << _tlbp.getLengthofBHSR()            << endl;
		cout << "Number of Pattern History Tables         : " << _tlbp.getNumofPHT()                << endl;
		cout << "Number of PHT Entries                    : " << _tlbp.getNumofPHTEntry()           << endl;
		cout << "Hardware Cost                            : " << _tlbp.calculateHardwareCostinBit() << endl;
		cout << "=====================================================" << endl;
		
		
		while(!tracefile.isTraceFileEnded())
		{
			tracefile.getNextEntry();
			// get prediction
			bool prediction = _tlbp.isPredictTaken(tracefile.getCurrentEntry().getBranchAddr());
			bool outcome    = tracefile.getCurrentEntry().getBranchOutcome();
			if(prediction==outcome)
			{
				stats_numofCorrectPrediction++;
			}
			else
			{
				stats_numofWrongPrediction++;
			}					
			//update predictor
			if(outcome)
			{
				_tlbp.updateTaken(tracefile.getCurrentEntry().getBranchAddr());
			}
			else
			{
				_tlbp.updateNotTaken(tracefile.getCurrentEntry().getBranchAddr());
			}
			
			stats_numofBranchPredicted++;
		}
		
		// Print Stats
		double accuracy = (stats_numofCorrectPrediction/(double)stats_numofBranchPredicted) * 100;
		cout << "Simulation Statistics" << endl;
		cout << "Number of Predicted Branch               : " << stats_numofBranchPredicted << endl;
		cout << "Number of Correct Prediction             : " << stats_numofCorrectPrediction << endl;
		cout << "Number of Wrong Prediction               : " << stats_numofWrongPrediction   << endl;
		cout << "Branch Prediction Accuracy               : " << accuracy << "%" << endl;
		cout << "=====================================================" << endl;
		
		
	}
	else
	{
		cout << "[ERROR] Invalid arguments for launching simulator!" << endl;
		printHelp(argv[0]);
		return -1;
	}
    return 0;
}

void printHelp(string exename)
{
	cout<< "usage:" << exename << " [tracefile] [r]              One-Level Branch Predictor with configurable number of BHT entrie(s)." << endl;
	cout<< "   or:" << exename << " [tracefile] [i] [j] [k] [s]  Two-Level Branch Predictor with custom BHSR size and PHT size." << endl;
	cout<< endl;
	cout<< "   r = log2(number of BHT entry)"  << endl;
	cout<< "   i = log2(number of BHSR entry)"  << endl;
	cout<< "   j = log2(number of PHT table)"  << endl;
	cout<< "   k = BHSR Length"  << endl;
	cout<< "   s = log2(number of Set)"  << endl;	
	cout<< endl;
	cout<< "One-Level Branch Predictor" << endl;
	cout<< "example:" << endl;
	cout<< "  " << exename << " trace.in 4                        One-Level Branch Predictor with 16-entries BHT" << endl;
	cout<< "  " << exename << " trace.in 10                       One-Level Branch Predictor with 1024-entries BHT" << endl;
	cout<< "note:" << endl;
	cout<< "*Parameter cannot be a negative number. " << endl;
	cout<< endl;
	cout<< "Two-Level Branch Predictor" << endl;
	cout<< "  " << exename << " trace.in 0 0 8 0                  Two-Level GAg Branch Predictor with 8-bit BHSR Length." << endl;
	cout<< "  " << exename << " trace.in 4 0 16 0                 Two-Level PAg Branch Predictor with 16-bit BHSR Length." << endl;
	cout<< "note:" << endl;
	cout<< "* All of parameters cannot be a negative number. " <<endl;
	cout<< "* The XAx configuration is derived from the combination of all parameters as follows: " << endl;
	cout<< "  XAx  | [log2(# BHSR)] | [log2(# PHT)] | [BHSR Length] | [log2(# Set)]" << endl;
	cout<< "  XAx  |        i       |       j       |     k         |      s       " << endl;
	cout<< "  -----|----------------|---------------|---------------|--------------" << endl;
	cout<< "  GAg  |       i=0      |      j=0      |    k>=0       |     s=0      " << endl;
	cout<< "  GAs  |       i=0      |      j>i      |    k>=0       |    0<s<j     " << endl;
	cout<< "  GAp  |       i=0      |      j>i      |    k>=0       |     s=0      " << endl;
	cout<< "  SAg  |       i>0      |      j=0      |    k>=0       |    0<s<i     " << endl;
	cout<< "  SAs  |       i>0      |     0<j<i     |    k>=0       |    0<s<i     " << endl;
	cout<< "  SAp  |       i>0      |      j>=i     |    k>=0       |    0<s<i     " << endl;
	cout<< "  PAg  |       i>0      |      j=0      |    k>=0       |     s=0      " << endl;
	cout<< "  PAs  |       i>0      |     0<j<i     |    k>=0       |     s=0      " << endl;
	cout<< "  PAp  |       i>0      |      j>=i     |    k>=0       |     s=0      " << endl;
	cout<< "* Another combinations of parameters will be treated as invalid. " << endl;
}