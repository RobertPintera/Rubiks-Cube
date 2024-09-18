#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "VAO.h"
#include "Shader.h"
#include "Camera.h"
#include "RubikCube.h"

//Window size
const int widthScreen = 800;
const int heightScreen = 600;

//Camera
Camera camera(0.0f,0.f,3.f);

//timing
float deltaTime = 0.f;
float lastFrame = 0.f;

//Choosing rotation
optionMove move = None;
bool reverse = false;

//Functions
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(widthScreen, heightScreen, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    {
        //Create Shader
        RubikCube rubikCube;
        Shader shaderProgram("shader.vert", "shader.frag");


        glm::mat4 projection = glm::perspective(glm::radians(90.f), static_cast<float>(widthScreen) / static_cast<float>(heightScreen), 0.1f, 100.f);

        //Main loop
        while (!glfwWindowShouldClose(window))
        {
            float currentFrame = static_cast<float>(glfwGetTime());
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            //Activate shader
            shaderProgram.Use();

            //Projection
            shaderProgram.setMat4("projection", projection);

            //View
            glm::mat4 view = camera.GetViewMatrix();
            shaderProgram.setMat4("view", view);

            //Render and update
            rubikCube.update(move, reverse,deltaTime);
            rubikCube.render(&shaderProgram);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        shaderProgram.Delete();
    }

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{   
    //Camera Movement
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);  
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);


	//Rubik's Cube controls
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS)
	{
		move = F;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS)
	{
		move = R;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_3) == GLFW_PRESS)
	{
		move = U;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
	{
		move = B;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_5) == GLFW_PRESS)
	{
		move = L;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
	{
		move = D;
		if (!(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
		{
			reverse = false;
		}
		else
		{
			reverse = true;
		}
	}
	else
	{
		move = None;
	}
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}