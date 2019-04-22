/*
Hanin Two-Level Branch Predictor Simulator
EE382N - Superscalar Microprocessor Architecture
Spring 2019 - Assignment 4
================================================
Copyright (C)2019 Bagus Hanindhito (bh29293)
hanindhito[at]bagus[dot]my[dot]id 
http://www.bagus.my.id
*/

#include "two_level_predictor.hpp"
#include "pattern_history_table.hpp"
#include "branch_history_register_table.hpp"
#include <string>
#include <math.h>
#include <iostream>


bool two_level_predictor::isParameterValid(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
{
	bool verification = false;
	if(k>=0)
	{
		if(i==0)
		{
			// GAx scheme
			if(j==0)
			{
				// GAg
				if(s==0)
				{
					// Valid GAg
					verification = true;
				}
				else
				{
					// Not valid GAg
					verification = false;
				}
				
			}
			else if (j>i)
			{
				// GAs or GAp
				if(s==0)
				{
					// Valid GAp
					verification = true;
				}
				else if ((s>0) && (s<j))
				{
					// Valid GAs
					verification = true;
				}
				else
				{
					// Not valid GAp or GAs
					// Negative s or s larger than j
					verification = false;
				}
			}
			else
			{
				// negative j
				verification=false;
			}
		}
		else if(i>0)
		{
			// SAx or PAx scheme
			if(s==0)
			{
				// PAx
				if (j==0)
				{
					// PAg
					verification=true;
				}
				else if ((j>0) && (j<i))
				{
					// PAs
					verification=true;
				}
				else if (j>=i)
				{
					// PAp
					verification=true;
				}
				else
				{
					// negative j
					verification=false;
				}
			}
			else if ((s>0) && (s<i))
			{
				// SAx
				if (j==0)
				{
					// SAg
					verification=true;
				}
				else if ((j>0) && (j<i))
				{
					// SAs
					verification=true;
				}
				else if (j>=i)
				{
					// SAp
					verification=true;
				}
				else
				{
					// negative j
					verification=false;
				}
			}
			else
			{
				// Not valid PAx or SAx
				// Negative s or s larger than i
				verification=false;
			}
		}
		else
		{
			// negative i
			verification = false;
		}
	}
	else
	{
		//negative k
		verification = false;
	}
	return verification;
}
std::string two_level_predictor::getParameterErrorInfo(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
{
	std::string errorText;
	if(k>=0)
	{
		if(i==0)
		{
			// GAx scheme
			if(j==0)
			{
				// GAg
				if(s==0)
				{
					// Valid GAg
					errorText = "Valid GAg configuration.";
				}
				else
				{
					// Not valid GAg
					errorText = "NOT valid GAg configuration, s must be zero.";
				}
				
			}
			else if (j>i)
			{
				// GAs or GAp
				if(s==0)
				{
					// Valid GAp
					errorText = "Valid GAp configuration.";
				}
				else if ((s>0) && (s<j))
				{
					// Valid GAs
					errorText = "Valid GAs configuration.";
				}
				else
				{
					// Not valid GAp or GAs
					// Negative s or s larger than j
					errorText = "NOT valid GAp or GAs configuration, s must be positive but smaller than j.";
				}
			}
			else
			{
				// negative j
				errorText = "NOT valid GAx configuration, j must be positive.";
			}
		}
		else if(i>0)
		{
			// SAx or PAx scheme
			if(s==0)
			{
				// PAx
				if (j==0)
				{
					// PAg
					errorText = "Valid PAg configuration.";
				}
				else if ((j>0) && (j<i))
				{
					// PAs
					errorText = "Valid PAs configuration.";
				}
				else if (j>=i)
				{
					// PAp
					errorText = "Valid PAp configuration.";
				}
				else
				{
					// negative j
					errorText = "NOT valid PAx configuration, j must be positive.";
				}
			}
			else if ((s>0) && (s<i))
			{
				// SAx
				if (j==0)
				{
					// SAg
					errorText = "Valid SAg configuration.";
				}
				else if ((j>0) && (j<i))
				{
					// SAs
					errorText = "Valid SAs configuration.";
				}
				else if (j>=i)
				{
					// SAp
					errorText = "Valid SAp configuration.";
				}
				else
				{
					// negative j
					errorText = "NOT valid SAx configuration, j must be positive.";
				}
			}
			else
			{
				// Not valid PAx or SAx
				// Negative s or s larger than i
				errorText = "NOT valid PAx or SAx configuration, j must be positive but smaller than i.";
			}
		}
		else
		{
			// negative i
			errorText = "NOT valid configuration, i must be positive.";
		}
	}
	else
	{
		//negative k
		errorText = "NOT valid configuration, k must be positive.";
	}
	return errorText;
}
std::string two_level_predictor::getPredictorTypeString(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
{
	std::string predictorType;
	if(k>=0)
	{
		if(i==0)
		{
			// GAx scheme
			if(j==0)
			{
				// GAg
				if(s==0)
				{
					// Valid GAg
					predictorType = "GAg";
				}
				else
				{
					// Not valid GAg
					predictorType = "NAn";
				}
				
			}
			else if (j>i)
			{
				// GAs or GAp
				if(s==0)
				{
					// Valid GAp
					predictorType = "GAp";
				}
				else if ((s>0) && (s<j))
				{
					// Valid GAs
					predictorType = "GAs";
				}
				else
				{
					// Not valid GAp or GAs
					// Negative s or s larger than j
					predictorType = "NAn";
				}
			}
			else
			{
				// negative j
				predictorType = "NAn";
			}
		}
		else if(i>0)
		{
			// SAx or PAx scheme
			if(s==0)
			{
				// PAx
				if (j==0)
				{
					// PAg
					predictorType = "PAg";
				}
				else if ((j>0) && (j<i))
				{
					// PAs
					predictorType = "PAs";
				}
				else if (j>=i)
				{
					// PAp
					predictorType = "PAp";
				}
				else
				{
					// negative j
					predictorType = "NAn";
				}
			}
			else if ((s>0) && (s<i))
			{
				// SAx
				if (j==0)
				{
					// SAg
					predictorType = "SAg";
				}
				else if ((j>0) && (j<i))
				{
					// SAs
					predictorType = "SAs";
				}
				else if (j>=i)
				{
					// SAp
					predictorType = "SAp";
				}
				else
				{
					// negative j
					predictorType = "NAn";
				}
			}
			else
			{
				// Not valid PAx or SAx
				// Negative s or s larger than i
				predictorType = "NAn";
			}
		}
		else
		{
			// negative i
			predictorType = "NAn";
		}
	}
	else
	{
		//negative k
		predictorType = "NAn";
	}
	return predictorType;
}
two_level_predictor_type two_level_predictor::getPredictorType(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
{
	two_level_predictor_type predictorType;
	if(k>=0)
	{
		if(i==0)
		{
			// GAx scheme
			if(j==0)
			{
				// GAg
				if(s==0)
				{
					// Valid GAg
					predictorType = GAg;
				}
				else
				{
					// Not valid GAg
					predictorType = NAn;
				}
				
			}
			else if (j>i)
			{
				// GAs or GAp
				if(s==0)
				{
					// Valid GAp
					predictorType = GAp;
				}
				else if ((s>0) && (s<j))
				{
					// Valid GAs
					predictorType = GAs;
				}
				else
				{
					// Not valid GAp or GAs
					// Negative s or s larger than j
					predictorType = NAn;
				}
			}
			else
			{
				// negative j
				predictorType = NAn;
			}
		}
		else if(i>0)
		{
			// SAx or PAx scheme
			if(s==0)
			{
				// PAx
				if (j==0)
				{
					// PAg
					predictorType = PAg;
				}
				else if ((j>0) && (j<i))
				{
					// PAs
					predictorType = PAs;
				}
				else if (j>=i)
				{
					// PAp
					predictorType = PAp;
				}
				else
				{
					// negative j
					predictorType = NAn;
				}
			}
			else if ((s>0) && (s<i))
			{
				// SAx
				if (j==0)
				{
					// SAg
					predictorType = SAg;
				}
				else if ((j>0) && (j<i))
				{
					// SAs
					predictorType = SAs;
				}
				else if (j>=i)
				{
					// SAp
					predictorType = SAp;
				}
				else
				{
					// negative j
					predictorType = NAn;
				}
			}
			else
			{
				// Not valid PAx or SAx
				// Negative s or s larger than i
				predictorType = NAn;
			}
		}
		else
		{
			// negative i
			predictorType = NAn;
		}
	}
	else
	{
		//negative k
		predictorType = NAn;
	}
	return predictorType;
}

two_level_predictor::two_level_predictor(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
: _bhrt(0)
{
	if (this->isParameterValid(i, j, k, s))
	{
		this->_i = i;
		this->_j = j;
		this->_k = k;
		this->_s = s;
		this->_predictorType = this->getPredictorType(i,j,k,s);
		switch(this->_predictorType)
		{
			case GAg :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = j; // should be zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case GAs :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = s; // GAs has PHT table determined by s bit
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case GAp :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s; // should be zero
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAg :
			{
				this->_numofBHSREntryinLogTwo = s; // SAg has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s since j is zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAs :
			{
				this->_numofBHSREntryinLogTwo = s; // SAs has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s+j
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAp :
			{
				this->_numofBHSREntryinLogTwo = s; // SAs has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s+j
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAg :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAs :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAp :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			default :
			{
				this->_numofBHSREntryinLogTwo = 0;
		        this->_numofPHTinLogTwo       = 0;
		        this->_lengthofBHSR           = 1;
		        this->_numofSetinLogTwo       = 0;
		        this->_numofBHSREntry         = 1;
		        this->_numofPHT               = 1;
		        this->_numofPHTEntry          = 1;
		        this->_numofSet               = 1;
		        this->_predictorType          = NAn;
		        for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(0);
				break;
			}			
		}
	}
	else
	{
		this->_numofBHSREntryinLogTwo = 0;
		this->_numofPHTinLogTwo       = 0;
		this->_lengthofBHSR           = 1;
		this->_numofSetinLogTwo       = 0;
		this->_numofBHSREntry         = 1;
		this->_numofPHT               = 1;
		this->_numofPHTEntry          = 1;
		this->_numofSet               = 1;
		this->_predictorType          = NAn;
		this->_phts                   = new pattern_history_table[this->_numofPHT];
		for(unsigned int i=0; i<this->_numofPHT;i++)
	    {
	    	this->_phts[i].reset(this->_lengthofBHSR);		
	    }
		this->_bhrt.reset(0);
	}
}


void two_level_predictor::reset(unsigned int i, unsigned int j, unsigned int k, unsigned int s)
{
	delete this->_phts;
	if (this->isParameterValid(i, j, k, s))
	{
		this->_i = i;
		this->_j = j;
		this->_k = k;
		this->_s = s;
		this->_predictorType = this->getPredictorType(i,j,k,s);
		switch(this->_predictorType)
		{
			case GAg :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = j; // should be zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case GAs :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = s; // GAs has PHT table determined by s bit
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case GAp :
			{
				this->_numofBHSREntryinLogTwo = i;
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s; // should be zero
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAg :
			{
				this->_numofBHSREntryinLogTwo = s; // SAg has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s since j is zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAs :
			{
				this->_numofBHSREntryinLogTwo = s; // SAs has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s+j
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case SAp :
			{
				this->_numofBHSREntryinLogTwo = s; // SAs has the entry number of BHT defined by s
		        this->_numofPHTinLogTwo       = s+j; // should be s+j
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAg :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAs :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			case PAp :
			{
				this->_numofBHSREntryinLogTwo = i; // should be more than zero 
		        this->_numofPHTinLogTwo       = j; // should be more than zero
		        this->_lengthofBHSR           = k;
		        this->_numofSetinLogTwo       = s;
		        this->_numofBHSREntry         = pow(2,_numofBHSREntryinLogTwo);
		        this->_numofPHT               = pow(2,_numofPHTinLogTwo);
		        this->_numofPHTEntry          = pow(2,_lengthofBHSR);
		        this->_numofSet               = pow(2,_numofSet);
		        this->_phts                   = new pattern_history_table[this->_numofPHT];
				for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(this->_numofBHSREntryinLogTwo, this->_lengthofBHSR);
				break;
			}
			default :
			{
				this->_numofBHSREntryinLogTwo = 0;
		        this->_numofPHTinLogTwo       = 0;
		        this->_lengthofBHSR           = 1;
		        this->_numofSetinLogTwo       = 0;
		        this->_numofBHSREntry         = 1;
		        this->_numofPHT               = 1;
		        this->_numofPHTEntry          = 1;
		        this->_numofSet               = 1;
		        this->_predictorType          = NAn;
		        for(unsigned int i=0; i<this->_numofPHT;i++)
	            {
	            	this->_phts[i].reset(this->_lengthofBHSR);		
	            }
		        this->_bhrt.reset(0);
				break;
			}			
		}
	}
	else
	{
		this->_numofBHSREntryinLogTwo = 0;
		this->_numofPHTinLogTwo       = 0;
		this->_lengthofBHSR           = 1;
		this->_numofSetinLogTwo       = 0;
		this->_numofBHSREntry         = 1;
		this->_numofPHT               = 1;
		this->_numofPHTEntry          = 1;
		this->_numofSet               = 1;
		this->_predictorType          = NAn;
		this->_phts                   = new pattern_history_table[this->_numofPHT];
		for(unsigned int i=0; i<this->_numofPHT;i++)
	    {
	    	this->_phts[i].reset(this->_lengthofBHSR);		
	    }
		this->_bhrt.reset(0);
	}
}

void two_level_predictor::updateTaken(unsigned int address)
{
	unsigned int bhrtindex = this->_calculateBHRTIndex(address);
	unsigned int phtsindex = this->_calculatePHTSIndex(address);
	
	unsigned int phtindex  = this->_bhrt.getEntrybyIndex(bhrtindex).getIntValue();
	
	//Update PHT Entry
	this->_phts[phtsindex].updateTaken(phtindex);
	
	//Update PHTS Entry
	this->_bhrt.updateTaken(bhrtindex);
	
}
void two_level_predictor::updateNotTaken(unsigned int address)
{
	unsigned int bhrtindex = this->_calculateBHRTIndex(address);
	unsigned int phtsindex = this->_calculatePHTSIndex(address);
	
	unsigned int phtindex  = this->_bhrt.getEntrybyIndex(bhrtindex).getIntValue();
	
	//Update PHT Entry
	this->_phts[phtsindex].updateNotTaken(phtindex);
	
	//Update PHTS Entry
	this->_bhrt.updateNotTaken(bhrtindex);
}

bool two_level_predictor::isPredictTaken(unsigned int address)
{
	unsigned int bhrtindex = this->_calculateBHRTIndex(address);
	unsigned int phtsindex = this->_calculatePHTSIndex(address);
	
	unsigned int phtindex  = this->_bhrt.getEntrybyIndex(bhrtindex).getIntValue();
	
	return this->_phts[phtsindex].getEntrybyIndex(phtindex).isTaken();
}

bool two_level_predictor::isPredictNotTaken(unsigned int address)
{
	unsigned int bhrtindex = this->_calculateBHRTIndex(address);
	unsigned int phtsindex = this->_calculatePHTSIndex(address);
	
	unsigned int phtindex  = this->_bhrt.getEntrybyIndex(bhrtindex).getIntValue();
	
	return this->_phts[phtsindex].getEntrybyIndex(phtindex).isNotTaken();
}

unsigned int two_level_predictor::getNumofBHSREntryinLogTwo()
{
	return this->_numofBHSREntryinLogTwo;
}
unsigned int two_level_predictor::getNumofPHTinLogTwo()
{
	return this->_numofPHTinLogTwo;
}

unsigned int two_level_predictor::getLengthofBHSR()
{
	return this->_lengthofBHSR;
}

unsigned int two_level_predictor::getNumofSetinLogTwo()
{
	return this->_numofSetinLogTwo;
}
unsigned int two_level_predictor::getNumofPHTEntryinLogTwo()
{
	return this->_lengthofBHSR;
}

unsigned int two_level_predictor::getNumofBHSREntry()
{
	return this->_numofBHSREntry;
}
unsigned int two_level_predictor::getNumofPHT()
{
	return this->_numofPHT;
}
unsigned int two_level_predictor::getNumofPHTEntry()
{
	return this->_numofPHTEntry;
}
unsigned int two_level_predictor::getNumofSet()
{
	return this->_numofSet;
}

two_level_predictor_type       two_level_predictor::getPredictorType()
{
	return this->_predictorType;
}
pattern_history_table          two_level_predictor::getPatternHistoryTable(unsigned int phtindex)
{
	return this->_phts[phtindex];
}
branch_history_register_table  two_level_predictor::getBranchHistoryRegisterTable()
{
	return this->_bhrt;
}
unsigned int two_level_predictor::calculateHardwareCostinBit()
{
	unsigned int firstlevelcost = this->_numofBHSREntry * this->_lengthofBHSR;
	unsigned int secondlevelcost= this->_numofPHT * this->_numofPHTEntry * 2;
	return firstlevelcost + secondlevelcost;
}

void two_level_predictor::printBranchPredictorContents()
{
	std::cout << "Branch History Shift Register Table" << std::endl;
	this->_bhrt.printTableBinary();
	
	for(unsigned int i = 0; i<this->_numofPHT;i++)
	{
		std::cout << "Pattern History Table " << i << " of " << this->_numofPHT-1 << std::endl;
		this->_phts[i].printTable();
	}
}






















unsigned int two_level_predictor::_calculateBHRTIndex(unsigned int address)
{
	unsigned int BHRT_Index;
	switch(this->_predictorType)
	{
		case GAg :
		{
			BHRT_Index = 0;
			break;
		}
		case GAs :
		{
			BHRT_Index = 0;
			break;
		}
		case GAp :
		{
			BHRT_Index = 0;
			break;
		}
		case SAg :
		{
			unsigned int offset = this->_i - this->_s;
			BHRT_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_s);
	        BHRT_Index = BHRT_Index & mask; // remove MSB
			break;
		}
		case SAs :
		{
			unsigned int offset = this->_i - this->_s;
			BHRT_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_s);
	        BHRT_Index = BHRT_Index & mask; // remove MSB
			break;
		}
		case SAp :
		{
			unsigned int offset = this->_i - this->_s;
			BHRT_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_s);
	        BHRT_Index = BHRT_Index & mask; // remove MSB
			break;
		}
		case PAg :
		{
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_i);
	        BHRT_Index = address & mask; // remove MSB
			break;
		}
		case PAs :
		{
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_i);
	        BHRT_Index = address & mask; // remove MSB
			break;
		}
		case PAp :
		{
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_i);
	        BHRT_Index = address & mask; // remove MSB
			break;
		}
		default :
		{
			BHRT_Index = 0;
			break;
		}			
	}
	return BHRT_Index;
}

unsigned int two_level_predictor::_calculatePHTSIndex(unsigned int address)
{
	unsigned int PHTS_Index;
	switch(this->_predictorType)
	{
		case GAg :
		{
			PHTS_Index = 0;
			break;
		}
		case GAs :
		{
			unsigned int offset = this->_j - this->_s;
			PHTS_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_s);
	        PHTS_Index = PHTS_Index & mask; // remove MSB			
			break;
		}
		case GAp :
		{			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_j);
	        PHTS_Index = address & mask; // remove MSB
			break;
		}
		case SAg :
		{
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_s);
	        PHTS_Index = address & mask; // remove MSB
			break;
		}
		case SAs :
		{
			unsigned int newBit = this->_s + this->_j;	// combine s and j for indexing		
			unsigned int offset = this->_i - this->_j;			
			PHTS_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<newBit);
	        PHTS_Index = PHTS_Index & mask; // remove MSB
			break;
		}
		case SAp :
		{
			unsigned int newBit = this->_s + this->_j; // combine s and j for indexing
			unsigned int mask = 0;
	        mask = ~((~mask)<<newBit);
	        PHTS_Index = address & mask; // remove MSB
			break;
		}
		case PAg :
		{
			PHTS_Index = 0;
			break;
		}
		case PAs :
		{
			unsigned int offset = this->_i - this->_j;			
			PHTS_Index = (address>>offset); // remove LSB			
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_j);
	        PHTS_Index = PHTS_Index & mask; // remove MSB
			break;
		}
		case PAp :
		{
			unsigned int mask = 0;
	        mask = ~((~mask)<<this->_j);
	        PHTS_Index = address & mask; // remove MSB
			break;
		}
		default :
		{
			PHTS_Index = 0;
			break;
		}			
	}
	return PHTS_Index;
}

