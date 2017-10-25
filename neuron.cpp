#include <iostream>
#include <cmath>
#include "neuron.hpp" 

using namespace std;
	
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
	assert(spike_buff.size() == delay_steps + 1);
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

bool Neuron::isRefractory(long c) const {
	return !times_historical.empty() && (c - times_historical.back()) < refractory_time;
}


void Neuron::updatePotential() {
		setMembranePotential( c1*getMembranePotential() + Iext*c2 +J);
}
	

void Neuron::update()
{	
	if (isRefractory(getClock()))
	{
		setMembranePotential(0);
	} else {
		updatePotential();
		potential_historical.push_back(membrane_potential);
		
		if (isSpiking()) 
		{
			times_historical.push_back(getClock());
		}
	}
	++clock;
}


void Neuron::receive_spike(unsigned long arrival, double potential) {
	const size_t t_case = arrival%(delay_steps+ 1);
	spike_buff[t_case] += potential;
}


double Neuron::convertMs(long c) {
	return c*h;
}


