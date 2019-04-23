# Two Level Branch Predictor Simulator  
EE382N Superscalar Microprocessor Architecture, Spring 2019, Assignment 4  
(C) 2019 Bagus Hanindhito (hanindhito[at]bagus[dot]my[dot]id)  

## Introduction
This is the implementation of two-level branch predictor with branch history shift register table and pattern history table based on the papers below.  
[1] T. Yeh, Y. Patt, "A comparison of dynamic branch predictors that use two levels of branch history", Proceedings of the 20th Annual International Symposium on Computer Architecture, pp. 257-266, 1993.  
[2] T-Y Yeh, Y.N. Patt, "Two-Level Adaptive Branch Prediction", Proceedings of the 24th Annual ACM/IEEE International Symposium and Workshop on Microarchitecture, pp. 51-61, 1991-Nov.  
[3] T-Y Yeh, Y.N. Patt, "Alternative Implementations of Two-Level Adaptive Branch Prediction", Proceedings of the 19th International Symposium on Computer Architecture, pp. 124-134, 1992-May.  

As an addition, this code can also simulate one-level branch predictor using the branch history table as a comparison to the two-level one. All of the code are implemented in C++11 and are written on Ubuntu on Windows Subsystem Linux with GCC 5.4.0.

## Getting Started
You can get the code, compile them, and run them very easily by following these steps.

### Clone and Compile
You can follow these commands to clone and compile the code on your local machine.
```bash
git clone https://github.com/hibagus/TwoLevelBPSimulator.git
cd TwoLevelBPSimulator
make
```

### Running the Simulator
If the compilation goes well, you can run the simulator by giving appropriate arguments to the program as follows.
```bash
./sim [tracefile] [r]              One-Level Branch Predictor with configurable number of BHT entrie(s).
./sim [tracefile] [i] [j] [k] [s]  Two-Level Branch Predictor with custom BHSR size and PHT size.
```

The arguments that the simulator needs are explained below.  
```
tracefile = a compatible plain text tracefile for simulation input.  
r         = log2(number of BHT entry)  
i         = log2(number of BHSR entry)  
j         = log2(number of PHT table)  
k         = BHSR Length  
s         = log2(number of Set)  
```
For one-level predictor, the r must not be a negative number.  
For two-level predictor, the i, j, k, and s must satisfy the following requirements.  
```
  XAx  | [log2(# BHSR)] | [log2(# PHT)] | [BHSR Length] | [log2(# Set)]  
  XAx  |        i       |       j       |     k         |      s         
  -----|----------------|---------------|---------------|--------------  
  GAg  |       i=0      |      j=0      |    k>=0       |     s=0        
  GAs  |       i=0      |      j>i      |    k>=0       |    0<s<j       
  GAp  |       i=0      |      j>i      |    k>=0       |     s=0        
  SAg  |       i>0      |      j=0      |    k>=0       |    0<s<i       
  SAs  |       i>0      |     0<j<i     |    k>=0       |    0<s<i       
  SAp  |       i>0      |      j>=i     |    k>=0       |    0<s<i       
  PAg  |       i>0      |      j=0      |    k>=0       |     s=0        
  PAs  |       i>0      |     0<j<i     |    k>=0       |     s=0        
  PAp  |       i>0      |      j>=i     |    k>=0       |     s=0        
```
  
### Tracefile format
This simulator requires simple tracefile in plain text format for simulation. Each line of the plain text should hold one entry of the trace. Each entry of the tracefile consists of address of branch instruction which is in the format of decimal and the actual outcome of this branch where 0 denotes the branch is not actually taken and 1 denotes the branch is actually taken. Here is the sample of the tracefile contents.
```
3253361352  1
3253361380  1
3253361375  0
3253361380  1
3253361375  0
```
### Test File
A simple test program to test the functionality of each module of the simulator is given on the test/test.cpp file.

## Basic Module
The simulator has two basic modules as a building block of the branch predictor. 

### Branch History Shift Register
![Branch History Shift Register](img/bhsr.png)
The BHSR is basically an k-bit shift register that stores the history of the outcome from the last k branches. If a new branch is encountered and the outcome is “taken”, then BHSR is shifted to the left and bit “1” is inserted as the new LSB. Likewise, if the new branch’s outcome is “not taken”, the BHSR is shifted to the left and bit “0” is inserted as the new LSB. The excess MSB is automatically truncated, keeping the length of BHSR constant.

### Two-Bit Saturating Counter
The Two-Bit Saturating Counter is a two-bit finite state machine that indicates the outcome pattern of the branches. There are four states indexed using two-bit: strong taken (T), weak taken (t), weak not taken (n), and strong not taken (N). 

## Contributing
If you are interested to use or modify the code for your next project, please cite accordingly. I will be very grateful for any contribution on this code.

## Authors
Bagus Hanindhito  
Graduate Student at Department of Electrical and Computer Engineering  
The University of Texas at Austin  

## License
The code is licensed under GNU Affero General Public License v3.0. Please see LICENSE file included in the source code.

## Acknowledgments
* Lizy K. John (Lecturer)
* Jiajun Wang (TA)
