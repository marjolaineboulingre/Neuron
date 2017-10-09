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
		
		
void Neuron::setMembranePotential(double mem_pot) {
	membrane_potential = mem_pot;
	
}		
	
void Neuron::update(double current, double time)
{
	if (isRefractory(time))
	{
		setMembranePotential(0);
	} else {
		setMembranePotential( exp(-h/tau)*membrane_potential + current*(tau/C)*(1-exp(-h/tau)) + J);
		potential_historical.push_back(membrane_potential);
		
		if (isSpiking()) 
		{
			times_historical.push_back(time);
		}
	}
}

bool Neuron::isSpiking() const {
	return getMembranePotential() >= Vth;
		 
}

bool Neuron::isRefractory(double time) const {
	return !times_historical.empty() && (time - times_historical.back()) < refractory_time;
}

double Neuron::getLastSpike() const {
	if ( !times_historical.empty())
	 {
		return times_historical.back();
	} else {
		return 0;
	}
}
