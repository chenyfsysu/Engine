#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "FileUtils.h"

std::string FileUtils::readFile(const char* path)
{
	std::string src;
	std::ifstream file;
	file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(path);
		std::stringstream srcstream;
		srcstream << file.rdbuf();
		file.close();
		src = srcstream.str();

		return src;
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR LOADDING FILE " << path << std::endl;
	}

	return "";
}