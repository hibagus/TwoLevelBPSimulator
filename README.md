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
tracefile = a compatible plain text tracefile for simulation input.
r         = log2(number of BHT entry)
i         = log2(number of BHSR entry)
j         = log2(number of PHT table)
k         = BHSR Length
s         = log2(number of Set)

For one-level predictor, the r must not be a negative number.
For two-level predictor, the i, j, k, and s must satisfy the following requirements.
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
  
### Tracefile format

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* Bagus Hhttps://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

The code is provided as is without any kind of warranty. If you are interested to use or modify the code, please cite accordingly. I will be very grateful for any contribution on this code.

## Acknowledgments
* Lizy K. John (Lecturer)
* Jiajun Wang (TA)
