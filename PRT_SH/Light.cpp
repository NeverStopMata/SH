#include "Light.h"



Light::Light()
{
}
Light::Light(float size, SampleSet Ss)
{
	int numFunctions = Ss.numBands * Ss.numBands;
	numBands = Ss.numBands;
	this->size = size;
	coeffs = new float[numFunctions];
	rotatedCoeffs = new float[numFunctions];
	for (int i = 0; i < numFunctions; i++)
	{
		coeffs[i] = 0.0f;
		for (int j = 0; j < Ss.numSamples; j++)
		{
			coeffs[i] += IsInLightArea(Ss.all[j].theta) * Ss.all[j].shValues[i];
			
		}
		coeffs[i] *= 4.0f * M_PI / Ss.numSamples;
	}
}


Light::~Light()
{
}

float Light::IsInLightArea(float theta)
{
	return (theta < size) ? 1.0f : 0.0f;
}

void  Light::RotateLight(float theta, float phi)
{
	SH_RotationManager SHRotManager;
	SHRotManager.RotateSHCoefficients(numBands, coeffs, rotatedCoeffs, theta, phi);
}

mat4 Light::getRotatedCoeffsMatrix()
{
	mat4 resultMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			resultMatrix[i][j] = this->rotatedCoeffs[i * 4 + j];
		}
	}
	return resultMatrix;
}