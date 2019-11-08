#pragma once

#include "sampleGenerator.h"
#include "random.h"

class CSampleGeneratorRandom : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int i; 
		while (i < n) 
		{
			v[i] = DirectGraphicalModels::random::U<float>();
			u[i] = DirectGraphicalModels::random::U<float>();
			weight[i] = 1.0f / n;
			i++; 
		}
	}
};


