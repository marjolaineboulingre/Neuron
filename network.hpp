#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Neuron.hpp"
#include "Constants.hpp"


class Network {
	
	private:
		
		std::vector<Neuron> neurons_network;					///represents all the neurons aof the network
		std::vector<std::vector<size_t>> connections;			///represents all the connections between the neurons in the network		
	
		///to generate the connections between differents neurons
		std::random_device rd;
		std::mt19937 listRandomNumbers;
		std::uniform_int_distribution <> excitatories(0, C::c_excitatory+1);
		std::uniform_int_distribution <> inhibitories(C::c_excitatory+1, C::c_inhibitory+1);
		
	public:

		Network();
		virtual ~Network();
		
		void createNetwork(Neuron n);								///add a neuron to the network
	
		void createConnections(); 								///create the connections between the neurons
		void update();
};



#endif
