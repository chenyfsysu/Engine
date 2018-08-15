#include "Mesh.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>


Mesh::Mesh(float vertices[], int vertexSize, unsigned int indices[], int indiceSize)
{
	int offset = sizeof(Vertex) / sizeof(float);
	int vertexLen = vertexSize / sizeof(Vertex);
	int indiceLen = indiceSize / sizeof(unsigned int);

	for(int i = 0; i < vertexLen; i++)
	{
		mVertices.push_back(Vertex(vertices + i * offset));
	}

	for(int i = 0; i < indiceLen; i++)
	{
		mIndices.push_back(indices[i]);
	}

	setup();
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	mVertices = vertices;
	mIndices = indices;

	setup();
}

void Mesh::setup()
{
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mEBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), &mVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), &mIndices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void Mesh::render()
{
	glBindVertexArray(mVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
