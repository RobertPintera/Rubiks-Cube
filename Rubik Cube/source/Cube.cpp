#include "Cube.h"


Cube::Cube(glm::vec3 position, 
    glm::vec3 colorFront, glm::vec3 colorTop, 
    glm::vec3 colorRight, glm::vec3 colorDown,
    glm::vec3 colorLeft, glm::vec3 colorBack):position(position),rotation(glm::vec3(0.f,0.f,0.f))
{
    float vertices[] = {
    -0.5f, -0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 1.0f, 1.0f,
     0.5f,  0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, colorBack.r, colorBack.g, colorBack.b, 0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, colorFront.r, colorFront.g, colorFront.b, 0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, colorLeft.r, colorLeft.g, colorLeft.b, 1.0f, 0.0f,

     0.5f,  0.5f,  0.5f, colorRight.r, colorRight.g, colorRight.b, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, colorRight.r, colorRight.g, colorRight.b, 1.0f, 1.0f,
     0.5f, -0.5f, -0.5f, colorRight.r, colorRight.g, colorRight.b, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, colorRight.r, colorRight.g, colorRight.b, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f, colorRight.r, colorRight.g, colorRight.b, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f, colorRight.r, colorRight.g, colorRight.b, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, colorDown.r, colorDown.g, colorDown.b, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, colorDown.r, colorDown.g, colorDown.b, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, colorDown.r, colorDown.g, colorDown.b, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f, colorDown.r, colorDown.g, colorDown.b, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f, colorDown.r, colorDown.g, colorDown.b, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, colorDown.r, colorDown.g, colorDown.b, 0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f, colorTop.r, colorTop.g, colorTop.b, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f, colorTop.r, colorTop.g, colorTop.b, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, colorTop.r, colorTop.g, colorTop.b, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, colorTop.r, colorTop.g, colorTop.b, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, colorTop.r, colorTop.g, colorTop.b, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, colorTop.r, colorTop.g, colorTop.b, 0.0f, 1.0f
    };

    vao.Bind();
    vbo.Bind();

    vbo.CopyData(vertices, sizeof(vertices));

    vao.LinkAttrib(0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    vao.LinkAttrib(1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao.LinkAttrib(2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
}

Cube::~Cube()
{
    vao.Delete();
    vbo.Delete();
}

glm::vec3& Cube::getPosition()
{
    return position;
}

void Cube::rotate(float angle, glm::vec3 axis)
{
    angle = glm::radians(angle);

    position = glm::rotate(position, angle, axis);
    rotation = glm::quat(axis * angle) * rotation;

    /*glm::vec3 euler = glm::eulerAngles(rotation) * 180.f / 3.14159f;
    std::cout << euler.x << ";" << euler.y << ";" << euler.z  << ";" << std::endl;*/
    /*std::cout << rotation.w << ";" << rotation.x << ";" << rotation.y << ";" << rotation.z << ";"  << std::endl;*/
}

void Cube::render(Shader& shaderProgram)
{
    vao.Bind();
    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, position);
    model = model * glm::toMat4(rotation);
    shaderProgram.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
