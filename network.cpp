#include <iostream>
#include <cassert>
#include "Constants.hpp"
#include "Network.hpp"


Network::Network() 
	: 
	listRandomNumbers(rd),
	excitatories(0, C::n_excitatory-1),
	inhibitories(C::n_excitatory-1, C::n_total-1)
{
		neurons_network.resize(C::n_total);
		connections.resize(C::n_total);
		
		for(auto i=0; neurons < C::n_total; ++i)
		{
			connections[i].resize(C::n_total);
		}
}




void Network::createNetwork(Neuron n)
{
	for(auto i=0; i < C::n_excitatory; ++i)
	{ 
		neurons_network.push_bakc(Neuron n);
		n.setIndex(neurons_network.size());
		n.setExcitatory(true);
	}
	
	for(auto i= C::n_excitatory + 1 ; i < C::n_total; ++i)
	{ 
		neurons_network.push_back(Neuron n);
		n.setIndex(neurons_network.size());
		n.setExcitatory(false);	
	}
}



void Network::createConnections() {
	
	for(target=0; target < C::n_total; ++target)
	{
		for(size_t i=0; i<C::c_excitatory; ++i)
			{
				auto source excitatories(listRandomNumbers);
				connections[source][target] += 1;
			}
			
			for(size_t i = C::c_excitatory; i <C::c_inhibitory; ++i)
			{
				auto source inhibitories(listRandomNumbers);
				connections[source][target] += 1;
			}
}


void Network::update() {

	for(auto n=0; n < neurons_network.size(); ++n) 
	{
		neurons_network[n].update;
		
		if ( neurons_network[n].isSpiking())
		{
			for(auto i=0; i < C::n_total; ++i)
			{
				
				 
	
	
	
	
}
