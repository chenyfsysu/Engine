#pragma once

#include "glm/glm.hpp"
#include <string>
#include <GL/Glew.h>
#include <GLFW/glfw3.h>

class ShaderProgram
{
public:
	ShaderProgram();

	bool assign(const char* vertPath, const char* fragPath);
	bool use();

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void checkShaderCompile(GLuint shader, std::string type);


private:
	unsigned int mShaderId;
	unsigned int mVertShader;
	unsigned int mFragShader;
};