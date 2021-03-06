#include "Neuron.h"
#include "NNdef.h"
#include "NNconfig.h"

#include <cmath>

///< Overall net learning rate, [0.0..1.0]
double Neuron::eta = ETA;
///< Momentum, multiplier of last deltaWeight, [0.0..1.0]
double Neuron::alpha = ALFA;

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
   : outputVal_{0.0}
   , outputWeights_{}
   , myIndex_{myIndex}
   , gradient_{0.0}
{
   for (unsigned c = 0; c < numOutputs; ++c) {
      outputWeights_.push_back(nndef::connection_t());
      outputWeights_.back().weight = randomWeight();
   }
}

void Neuron::updateInputWeights(nndef::neurons_layer_t &prevLayer)
{
   // The weights to be updated are in the Connection container
   // in the neurons in the preceding layer
   for (auto &neuron : prevLayer) {
      double oldDeltaWeight = neuron.outputWeights_[myIndex_].deltaWeight;
      double newDeltaWeight =
         // Individual input, magnified by the gradient and train rate:
         eta * neuron.getOutputVal() * gradient_
         // Also add momentum = a fraction of the previous delta weight;
         + alpha * oldDeltaWeight;
      neuron.outputWeights_[myIndex_].deltaWeight = newDeltaWeight;
      neuron.outputWeights_[myIndex_].weight += newDeltaWeight;
   }
}

double Neuron::sumDOW(const nndef::neurons_layer_t &nextLayer) const
{
   double sum = 0.0;
   // Sum our contributions of the errors at the nodes we feed.
   for (size_t n = 0; auto &neuron : nextLayer) {
      sum += outputWeights_[n].weight * neuron.gradient_;
      ++n;
   }
   return sum;
}

void Neuron::calcHiddenGradients(const nndef::neurons_layer_t &nextLayer)
{
   double dow = sumDOW(nextLayer);
   gradient_ = dow * Neuron::transferFunctionDerivative(outputVal_);
}

void Neuron::calcOutputGradients(double targetVal)
{
   double delta = targetVal - outputVal_;
   gradient_ = delta * Neuron::transferFunctionDerivative(outputVal_);
}

double Neuron::transferFunction(double x)
{
   // tanh - output range [-1.0..1.0]
   return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
   // tanh derivative
   return 1.0 - tanh(x) * tanh(x);
}

void Neuron::feedForward(const nndef::neurons_layer_t &prevLayer)
{
   double sum = 0.0;

   for (auto &neuron : prevLayer) {
      sum += neuron.getOutputVal() * neuron.outputWeights_[myIndex_].weight;
   }
   outputVal_ = Neuron::transferFunction(sum);
}
