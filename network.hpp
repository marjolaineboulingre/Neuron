#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <random>
#include <algorithm>
#include "Neuron.hpp"
#include "Constants.hpp"


class Network {
	
	private:
		
		std::vector<Neuron> neurons_network;					///represents all the neurons aof the network
		std::vector<std::vector<int>> connections;			///represents all the connections between the neurons in the network		
	
		///to generate the connections between differents neurons
		std::random_device rd;
		std::mt19937 listRandomNumbers;
		std::uniform_int_distribution <> excitatories;
		std::uniform_int_distribution <> inhibitories;
		
	public:

		Network();
		~Network() = default;
		
		void createNetwork();								///add a neuron to the network
	
		void createConnections(); 								///create the connections between the neurons
		
		void update(unsigned long t);
		
		void saveTimeSpikes();
		
		void run2neurons(unsigned long time);
		void run(unsigned long time);
};



#endif
