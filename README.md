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

### Cloning the code and compile them.
You can follow these commands to clone and compile the code on your local machine.
```
git clone https://github.com/hibagus/TwoLevelBPSimulator.git
cd TwoLevelBPSimulator
make
```



```
Give examples
```

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
