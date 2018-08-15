#pragma once
#include "glm/glm.hpp"
#include <vector>
#include <string>

struct Vertex
{
	Vertex(float *arr)
	{
		Position.x = *(arr);
		Position.y = *(arr + 1);
		Position.z = *(arr + 2);
	}
	glm::vec3 Position;
	//glm::vec3 Normal;
	//glm::vec2 TexCoords;	
};

struct Texture
{
	unsigned int id;
	std::string type;
};

class Mesh
{

public:
	Mesh(float vertices[], int vertexSize, unsigned int indices[], int indiceSize);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	void setup();
	void render();

private:
	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mEBO;

	std::vector<Vertex> mVertices;
	std::vector<unsigned int> mIndices;
};