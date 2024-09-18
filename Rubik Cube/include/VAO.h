#ifndef VAO_H
#define VAO_H

#include "VBO.h"

class VAO
{
public:
	VAO();

	void LinkAttrib(GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
private:
	GLuint ID;
};

#endif // !VAO_H