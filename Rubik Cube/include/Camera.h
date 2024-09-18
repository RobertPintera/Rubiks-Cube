#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>

enum Camera_Movement {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class Camera
{
public:
	Camera(float posX = 0.f, float posY = 0.f, float posZ = 0.f,
        float upX = 0.f, float upY = 1.f, float upZ = 0.f,
        float yaw = 0.f, float pitch = 0.f);

    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

	glm::mat4 GetViewMatrix();
private:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;

	void updateCamera();
};
#endif