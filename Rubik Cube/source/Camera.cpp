#include "Camera.h"


Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCamera();
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = 100.f * deltaTime;
    if (direction == UP)
    {
        if (Pitch < 90.f-velocity)
            Pitch += velocity;
    }
    else if (direction == DOWN)
    {
        if(Pitch > - 90.f + velocity)
            Pitch -= velocity;
    }
    else if (direction == LEFT)
    {
        Yaw -= velocity;
    }
    else if (direction == RIGHT)
    {
        Yaw += velocity;
    }
    updateCamera();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position,glm::vec3(0.f,0.f,0.f), WorldUp);
}

void Camera::updateCamera()
{
    Position.x = 5.f * cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));
    Position.y = 5.f * sin(glm::radians(Pitch));
    Position.z = 5.f * cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
}
