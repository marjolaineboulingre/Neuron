#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include "neuron.hpp" 

using namespace std;
	
Neuron::Neuron()
	:
	isExcitatory(false),
	membrane_potential(0.0),
	Iext(0.0),
	t_spike(0),
	n_spikes(0),
	clock(0),
	spike_buff(),
	times_historical(0)
{
	delay_steps = static_cast<unsigned long>(ceil(C::delay/h));
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

double Neuron::getDelay() const {
	return C::delay;
}

int Neuron::getNbrSpikes() const {
	return n_spikes;
}


bool Neuron::getIsExcitatory() const  {
	return isExcitatory;
}

double Neuron::getPotentialTransmitted() const {
	if (getIsExcitatory()) 
	{ 
		return C::Je;
	} else {
		return C::Ji;
	}
}

std::vector<int> Neuron::getTimesSpike() const {
	return times_historical;
}


///setters
		
void Neuron::setMembranePotential(double mem_pot) {
	membrane_potential = mem_pot;
}	

void Neuron::setExtCurrent(double I) {
	Iext = I;
}	

void Neuron::setIndex(size_t ind) {
	index = ind;
}

void Neuron::setExcitatory(bool c) {
	isExcitatory = c;
}
	
///methods concerning the state of the neuron

bool Neuron::isSpiking() const {
	return getMembranePotential() >= C::V
th;
		 
}

bool Neuron::isRefractory(long c) const {
	return !times_historical.empty() && (c - times_historical.back()) < C::refractory_time;
}


///Evolution of the neuron

void Neuron::updatePotential() {
	
		membrane_potential = C::c1 * membrane_potential + C::c2*Iext;
		membrane_potential += spike_buff[clock % delay_steps];
		
		///generate the background noise
		random_device rd;
		mt19937 gen(rd());
		poisson_distribution<> poisson(2);
		
		membrane_potential += poisson(gen) *C::Je;
}
	

void Neuron::update(unsigned long steps)
{	
	const auto t_stop = clock +steps;
	
	while(clock < t_stop)
	{
		if (isRefractory(clock))
		{
			setMembranePotential(0.0);
		} else {
			updatePotential();
			potential_historical.push_back(membrane_potential);
			
		
		if (isSpiking()) 
		{
			times_historical.push_back(clock);
			++ n_spikes;
		}
		}
		spike_buff[ clock % delay_steps] = 0.0;
		++clock;
	}
	
}


void Neuron::receive_spike(unsigned long arrival, double potential) {
	const size_t t_case = arrival%(delay_steps+ 1);
	assert(t_case < spike_buff.size());
	
	spike_buff[t_case] += potential;
}


double Neuron::convertMs(unsigned long c) {
	return c*C::h;
}

