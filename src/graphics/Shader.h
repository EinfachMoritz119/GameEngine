#ifndef SHADER_H
#define SHADER_H


#include "glm/gtc/type_ptr.hpp"
#include "glm/glm.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


namespace graphics {

class Shader {
public:
	unsigned int ID;

	Shader(const char* vertex_source, const char* fragment_source);
	void use();

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec3(const std::string &name, const glm::vec3 &value) const;

	void setMat4(const std::string &name,const  glm::mat4 &value) const;
	
	


};
};

#endif // SHADER_H
