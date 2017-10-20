#include <iostream>
#include <cmath>
#include "neuron.hpp" 


	
Neuron::Neuron()
	:
	membrane_potential(0.0),
	Iext(0.0),
	delay(1.5),
	t_spike(0),
	n_spikes(0),
	clock(0),
	spike_buff()
{
	delay_steps = static_cast<unsigned long>(ceil(delay/h));
	spike_buff.resize(delay_steps+1, 0.0);
	c1 =exp(-h/tau);
	c2 =R*(1.0*c1);
}
	

///getters
	
double Neuron::getMembranePotential() const {
	return membrane_potential;
}

double Neuron::getExtCurrent() const {
	return Iext;
}


unsigned long Neuron::getClock() const {
	return clock;
}

unsigned long Neuron::getLastTimeSpike() const {
	if ( !times_historical.empty())
	 {
		return times_historical.back();
	} else {
		return 0;
	}
}


///setters
		
void Neuron::setMembranePotential(double mem_pot) {
	membrane_potential = mem_pot;
}	

void Neuron::setExtCurrent(double I) {
	Iext = I;
}	
	
	
///methods concerning the state of the neuron

bool Neuron::isSpiking() const {
	return getMembranePotential() >= Vth;
		 
}

bool Neuron::isRefractory(double time) const {
	return !times_historical.empty() && (clock - times_historical.back()) < refractory_time;
}


void Neuron::updatePotential(int steps) {
	for(int i = 0; i <= steps; ++i)  {
		setMembranePotential( c1*membrane_potential + Iext*c2 + J);
	}
}
	

void Neuron::update(int steps)
{	
	if (isRefractory(clock))
	{
		setMembranePotential(0);
	} else {
		updatePotential(steps);
		potential_historical.push_back(membrane_potential);
		
		if (isSpiking()) 
		{
			times_historical.push_back(getClock());
		}
	}
}


void Neuron::receive_spike(unsigned long arrival, double potential) {
	const size_t t_out = arrival%(delay_steps+ 1);
	spike_buff[t_out] += potential;
}



