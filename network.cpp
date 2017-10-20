#include <iostream>
#include <cassert>
#include "Constants.hpp"
#include "Network.hpp"


Network::Network() {
	neurons = std::vector<Neuron*>();
	
	// Add two neurons
	neurons.push_back(new Neuron());
	neurons.push_back(new Neuron());
	
	
	connexions = std::vector< std::vector<int> >();
	
	// Add a connection from 0 to 1
	connexions.push_back({ 1 });
	connexions.push_back({ });
	
	// Check for enough connections
	assert(connexions.size() >= neurons.size());
}

Network::~Network() {
	for (auto& neuron : neurons) {
		delete neuron;
		neuron = nullptr;
	}
}

bool Network::update(double current) {
	for (size_t i = 0; i < neurons.size(); ++i) {
		Neuron* neuron = neurons.at(i);

		// update the neuron
		bool spiked = neuron->update(1, current);
		
		if (spiked) {
			std::cout << i << ": spike at " << C::STEP_DURATION * neuron->getClock() << "ms, " << neuron->getPotential() << "mV" << std::endl;
			
			// transmit spike to targets immediately
			for (auto target : connexions.at(i)) {
				neurons.at(target)->receive(C::J);
			}
		}
		
	}
	
	/*
	if (neurons.at(1)->getClock() > 1200 && neurons.at(1)->getClock() < 1400) {
		std::cout << neurons.at(1)->getPotential() << std::endl;
	}
	*/
	
	return true;
}
