#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Neuron.hpp"


class Network {
	
	public:

		Network();
		virtual ~Network();


		void addNeuron(Neuron* n); 							///add a neuron to the network
		
		
		
		bool update(double current);						/// update the neurons
	
	private:
		
		std::vector<Neuron*> neurons;						///represents all the neurons in the network
		std::vector< std::vector<int> > connexions;			///all connections between the neurons
};

#endif
