#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>

class VBO
{
public:
	VBO();

	void Bind();
	void CopyData(GLfloat* vertices, GLsizeiptr size);
	void Unbind();
	void Delete();
private:
	GLuint ID;
};

#endif // !VBO_H
