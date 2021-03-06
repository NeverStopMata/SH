#pragma once
#include <vector>
#include <map>
#include <tchar.h>
#include <CL\cl.hpp>
#include <iostream>
#include <fstream>
using namespace std;
class OpenCL_Math
{
public:
	OpenCL_Math();
	~OpenCL_Math();
	//void OpenCL_Math::AddKernel(char * proFileName);
	void OpenCL_Math::MatMultip(int M, int N, int K, float * Mat1, float * Mat2, float * res);
	void OpenCL_Math::GetSceneMatrix(int numSample, int numDot, int numVertices, float * sampleDircts, float * dotNormals, float * dotPos, float * vertPos, float * faceNormals, float * res);
	void OpenCL_Math::GetSpecTransferMat(int numSample, int numVertices, float * sampleDircts, float * normal, float * dotPos, float * vertPos, float * faceNormals, float * res);
	void OpenCL_Math::GetSpecBrightness(int numDots, float* lightCoeffs, float* brdfCoeffs, float* transferMats, float * res);
	void OpenCL_Math::GetTransLightCoes(int numDots, float* lightCoeffs, float* transferMats, float * res);
	void OpenCL_Math::GetDifInterRefCoeff(int numSample, int numVertices, int numFunc, float* h_SH_Mat_T, float * h_sampleDircts, float * h_normal, float * h_dotPos, float * h_vertPos, float * h_faceNormals, float * h_res);
public:
	std::vector<cl::Platform> all_platforms;
	cl::Platform default_platform;
	std::vector<cl::Device> all_devices;
	cl::Device default_device;
	cl::Context context;
	map<const char*, cl::Kernel> kernelList;
	cl::Program::Sources MatsMultiSrc;
	cl::Program Programs;
	cl::Program::Sources Sources;
};

