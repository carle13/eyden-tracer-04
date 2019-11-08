#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRegular : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int sizeSquare = sqrt(n);
		int numSample = 0;
		for (int i = 0; i < sizeSquare; i++)
		{
			for (int b = 0; b < sizeSquare; b++)
			{
				u[numSample] = (i + 0.5f) / sizeSquare;
				u[numSample] = (b + 0.5f) / sizeSquare;
				weight[numSample] = 1.0f / n;
				numSample++;
			}
		}
	}
};