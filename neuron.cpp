#include <iostream>
#include <cmath>
#include "neuron.hpp" 

Neuron::Neuron(double mp, int t) 
	: membrane_potential(mp), /*number_spikes(nbrs),*/ last_time_spikes(t)
	{}
	
Neuron::Neuron()
 : membrane_potential(0), last_time_spikes(0)
{}
		
double Neuron::getMembranePotential() const {
	return membrane_potential;
}
		
/*double Neuron::getNumberSpikes() const {
	return number_spikes;
}*/
		
/*double Neuron::getTimeSpikes() const {
	return times_spikes;
}*/
		
double Neuron::setMembranePotential(double mem_pot) {
	membrane_potential = mem_pot;
}		
	
void Neuron::update(double current, double time)
{
	if (isRefractory(time))
	{
		setMembranePotential(0);
	} else {
		setMembranePotential( exp(-h/tau)*membrane_potential + current*(tau/C)*(1-exp(-h/tau)));
		potential_historical.push_back(membrane_potential);
		
		if (isSpiking()) 
		{
			times_historical.push_back(time);
		}
	}
}

bool Neuron::isSpiking() const {
	if (getMembranePotential() >= Vth) 
		 return true; 
}

bool Neuron::isRefractory(double time) const {
	return (time - times_historical[times_historical.size()]) < refractory_time;
}


