#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/quaternion.hpp>

#include "VAO.h"
#include "Shader.h"
#include <iostream>


class Cube
{
public:
	Cube(glm::vec3 position,
		glm::vec3 colorFront, glm::vec3 colorTop,
		glm::vec3 colorRight, glm::vec3 colorDown,
		glm::vec3 colorLeft, glm::vec3 colorBack
		);
	virtual ~Cube();

	glm::vec3& getPosition();

	void rotate(float angle, glm::vec3 axis);

	void render(Shader& shadershaderProgram);
private:
	VAO vao;
	VBO vbo;
	glm::vec3 position;
	glm::quat rotation;
};

#endif // !CUBE_H