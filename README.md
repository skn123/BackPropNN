# Back Propagation Neural Network

- The goal of any **supervised learning algorithm** is to find a function that best maps a set of inputs to their correct output. The motivation for backpropagation is to train a multi-layered neural network such that it can learn the appropriate internal representations to allow it to learn any arbitrary mapping of input to output. See [Wikipedia](https://en.wikipedia.org/wiki/Backpropagation) and [Neural network concepts](https://missinglink.ai/guides/neural-network-concepts/complete-guide-artificial-neural-networks/).
  
- **Neuron/perceptron**: the basic unit of the neural network. Accepts an input and generates a prediction. Neural networks generate their predictions in the form of a set of real values or boolean decisions. Each output value is generated by one of the neurons in the output layer.

- **Activation function** example: non-linear **Hyperbolic Tangent**, zero centered making it easier to model inputs that have strongly negative, neutral, and strongly positive values. See [Seven types of activation functions](https://missinglink.ai/guides/neural-network-concepts/7-types-neural-network-activation-functions-right/).
  
## Simulation   
Training sets: XOR, OR , AND and NAND. See [Simulation training backprop NN](http://www.emergentmind.com/neural-network).


## Refactoring to Modern C++

Source: [David Miller, C++ code example](https://inkdrop.net/dave/docs/neural-net-tutorial.cpp)
Video: [David Miller, Neural Net in C++ Tutorial](https://vimeo.com/19569529)
Goal of this project: refactoring the David Miller example code to Modern C++. Still under construction ...

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2cd688b1e3984f63b00fdee04e7dac4b)](https://www.codacy.com/project/josokw/BackPropNN/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=josokw/BackPropNN&amp;utm_campaign=Badge_Grade_Dashboard)
[![CodeFactor](https://www.codefactor.io/repository/github/josokw/backpropnn/badge)](https://www.codefactor.io/repository/github/josokw/backpropnn)



## Compiling

The C++ code is compilable by **g++ v9.3.0**.

Install g++ on Ubuntu 18.04:

```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-9 g++-9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-9
```

Go to the *src* directory and type:

```bash
make
```

## Running: training a BackProp NN

A set of inputs for which the correct outputs are known, used to train the neural network.

Training **XOR**, topology:
- 2 input neurons
- 1 hidden layer 5 neurons
- 1 output neuron

Empty lines and single line comments after **#** are allowed.

```
# trainingXOR.txt
topology: 2 5 1

in: 0.0 0.0
out: 0.0

in: 1.0 0.0
out: 1.0

in: 0.0 1.0
out: 1.0

in: 1.0 1.0
out: 0.0
```

Run the code for training XOR:

```bash
./backpropnn ../data/trainingXOR.txt
```
