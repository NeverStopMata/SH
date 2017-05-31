#pragma once
#include <vector>
#include <stack>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Triangle.h"
#include "SampleSet.h"
using namespace glm;
using namespace std;
class Scene
{
public:
	vector<vec3> volume_vertices;
	vector<vec3> vertices;
	vector<vec2> uvs;
	vector<vec3> normals;
	vector<float *> coeffsList;
	vector<unsigned short> indices;
	vector<vec3> indexed_vertices;
	vector<vec2> indexed_uvs;
	vector<vec3> indexed_normals;
	
	vector<float *> indexed_coeffsList;
	
public:
	Scene(const char * filePath, SampleSet Ss);
	~Scene();
	void Scene::SubFacesGenerate(stack<Triangle> stack_triangles);
	void Scene::AddTiangle(Triangle newTriangle);
	void Scene::GenerateDirectCoeffs(SampleSet sampleset);
};

