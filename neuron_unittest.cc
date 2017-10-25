#include "gtest/gtest.h"
#include "neuron.hpp"
#include <cmath>


TEST(NeuronTest, Membrane) {
	
	Neuron neuron;
	neuron.setExtCurrent(1.0);
	neuron.update();
	
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getMembranePotential());
}


TEST(NeuronTest, RightTime) {
	
	Neuron neuron;
	neuron.setExtCurrent(1.01);
	while ( !neuron.isSpiking() ) {
		neuron.update();
	}
	
	EXPECT_EQ( 1923 ,neuron.getLastTimeSpike());
}


TEST(NeuronTest, IsRefractory) {
	
	Neuron neuron;
	
	ASSERT_FALSE (neuron.isRefractory(1.0));
}

int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

