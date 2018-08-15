#include "ShaderProgram.h"
#include "common/FileUtils.h"

#include <GL/Glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


ShaderProgram::ShaderProgram()
{
	mShaderId = glCreateProgram();
}

bool ShaderProgram::assign(const char* vertPath, const char* fragPath)
{
	std::string vertCode = FileUtils::readFile(vertPath);
	if (vertCode == "")
	{
		return false;
	}

	std::string fragCode = FileUtils::readFile(fragPath);
	if (fragCode == "")
	{
		return false;
	}

	const char* _vertCode = vertCode.c_str();
	mVertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(mVertShader, 1, &_vertCode, nullptr);
	glCompileShader(mVertShader);
	checkShaderCompile(mVertShader, "VERTEX");

	const char* _fragCode = fragCode.c_str();
	mFragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(mFragShader, 1, &_fragCode, nullptr);
	glCompileShader(mFragShader);
	checkShaderCompile(mFragShader, "FRAGMENT");

	glAttachShader(mShaderId, mVertShader);
	glAttachShader(mShaderId, mFragShader);
	glLinkProgram(mShaderId);
	checkShaderCompile(mShaderId, "PROGRAM");

	return true;
}

void ShaderProgram::checkShaderCompile(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[512];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << std::endl << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type  << infoLog << std::endl;
        }
    }
}

bool ShaderProgram::use()
{
	glUseProgram(mShaderId);
	return true;
}

void ShaderProgram::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(mShaderId, name.c_str()), int(value));
}

void ShaderProgram::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(mShaderId, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, float value) const
{
	glUniform1i(glGetUniformLocation(mShaderId, name.c_str()), value);

}

