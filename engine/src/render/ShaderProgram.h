#pragma once

#include <iostream>
#include "../glm/glm.hpp"
using namespace std;

class ShaderProgram
{
public:
	ShaderProgram();

	bool assign(const char* vertPath, const char* fragPath);
	bool compile();
	bool link();
	bool use();

	void setBool(const string &name, bool value) const;
	void setInt(const string &name, int value) const;
	void setFloat(const string &name, int value) const;
	void setVec2(const string &name) const;


private:
	int shaderId;
};