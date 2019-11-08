#pragma once

#include "sampleGenerator.h"
#include "random.h"

class CSampleGeneratorStratified : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int samp = 0;
		int sqn = sqrt(n);
		int i; 
		int j; 
		float randi; 
		float randj; 

		for (i = 0; i < sqn; i++)
		{
			for (j = 0; j < sqn; j++)
			{
				randi = DirectGraphicalModels::random::U<float>();
				randj = DirectGraphicalModels::random::U<float>();

				u[samp] = (i + randi) / sqn;
				v[samp] = (j + randj) / sqn;
				weight[samp] = 1.0f / n;
				samp++;
			}
		}
	}
};
