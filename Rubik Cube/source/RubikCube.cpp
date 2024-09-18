#include "RubikCube.h"

RubikCube::RubikCube():angle(0.f), isMoving(false), activeReverse(false), activeMove(None)
{
    cubes[0][0][1] = std::make_shared<Cube>(glm::vec3(-1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][0][1] = std::make_shared<Cube>(glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][0][1] = std::make_shared<Cube>(glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[0][1][1] = std::make_shared<Cube>(glm::vec3(-1.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][1][1] = std::make_shared<Cube>(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][1][1] = std::make_shared<Cube>(glm::vec3(1.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[0][2][1] = std::make_shared<Cube>(glm::vec3(-1.f, -1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][2][1] = std::make_shared<Cube>(glm::vec3(0.f, -1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][2][1] = std::make_shared<Cube>(glm::vec3(1.f, -1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    
    cubes[0][0][0] = std::make_shared<Cube>(glm::vec3(-1.f, 1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[1][0][0] = std::make_shared<Cube>(glm::vec3(0.f, 1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[2][0][0] = std::make_shared<Cube>(glm::vec3(1.f, 1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[0][1][0] = std::make_shared<Cube>(glm::vec3(-1.f, 0.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[1][1][0] = std::make_shared<Cube>(glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[2][1][0] = std::make_shared<Cube>(glm::vec3(1.f, 0.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[0][2][0] = std::make_shared<Cube>(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[1][2][0] = std::make_shared<Cube>(glm::vec3(0.f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    cubes[2][2][0] = std::make_shared<Cube>(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
    
    cubes[0][0][2] = std::make_shared<Cube>(glm::vec3(-1.f, 1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][0][2] = std::make_shared<Cube>(glm::vec3(0.f, 1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][0][2] = std::make_shared<Cube>(glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f, 1.f, 1.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[0][1][2] = std::make_shared<Cube>(glm::vec3(-1.f, 0.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][1][2] = std::make_shared<Cube>(glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][1][2] = std::make_shared<Cube>(glm::vec3(1.f, 0.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[0][2][2] = std::make_shared<Cube>(glm::vec3(-1.f, -1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(1.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[1][2][2] = std::make_shared<Cube>(glm::vec3(0.f, -1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
    cubes[2][2][2] = std::make_shared<Cube>(glm::vec3(1.f, -1.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f));
}

void RubikCube::update(optionMove move, bool reverse,float deltaTime)
{
    float speedRotate = 200.f * deltaTime;
    if (!isMoving)
    {
        if (move != None)
        {
            angle = 0.f;
            activeMove = move;
            isMoving = true;
            activeReverse = reverse;
        }
    }
    else
    {
        angle += speedRotate;
        if (angle > 90.f)
        {
            speedRotate = speedRotate + 90.f - angle;
            isMoving = false;
        }

        std::shared_ptr<Cube>temp[3][3];
        switch (activeMove)
        {
        case F:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {

                    if (!activeReverse)
                    {
                        cubes[x][y][2]->rotate(-speedRotate, glm::vec3(0.f, 0.f, 1.f));
                        temp[2 - y][x] = cubes[x][y][2];
                    }
                    else
                    {
                        cubes[x][y][2]->rotate(speedRotate, glm::vec3(0.f, 0.f, 1.f));
                        temp[y][2 - x] = cubes[x][y][2];
                    }
                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[x][y][2] = temp[x][y];
                    }
                }
            }   
            break;
        case B:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {
                    if (!activeReverse)
                    {
                        cubes[x][y][0]->rotate(speedRotate, glm::vec3(0.f, 0.f, 1.f));
                        temp[y][2 - x] = cubes[x][y][0];
                    }
                    else
                    {
                        cubes[x][y][0]->rotate(-speedRotate, glm::vec3(0.f, 0.f, 1.f));
                        temp[2 - y][x] = cubes[x][y][0];
                    }

                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[x][y][0] = temp[x][y];
                    }
                }
            }
            
            break;
        case R:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {
                    if (!activeReverse)
                    {
                        cubes[2][x][y]->rotate(-speedRotate, glm::vec3(1.f, 0.f, 0.f));
                        temp[2 - y][x] = cubes[2][x][y];
                    }
                    else
                    {
                        cubes[2][x][y]->rotate(speedRotate, glm::vec3(1.f, 0.f, 0.f));
                        temp[y][2 - x] = cubes[2][x][y];
                    }
                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[2][x][y] = temp[x][y];
                    }
                }
            }
            
            break;
        case L:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {
                    if (!activeReverse)
                    {
                        cubes[0][x][y]->rotate(speedRotate, glm::vec3(1.f, 0.f, 0.f));
                        temp[y][2 - x] = cubes[0][x][y];
                    }
                    else
                    {
                        cubes[0][x][y]->rotate(-speedRotate, glm::vec3(1.f, 0.f, 0.f));
                        temp[2 - y][x] = cubes[0][x][y];
                    }

                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[0][x][y] = temp[x][y];
                    }
                }
            }
            
            break;
        case U:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {
                    if (!activeReverse)
                    {
                        cubes[x][0][y]->rotate(-speedRotate, glm::vec3(0.f, 1.f, 0.f));
                        temp[2 - y][x] = cubes[x][0][y];
                        
                    }
                    else
                    {
                        cubes[x][0][y]->rotate(speedRotate, glm::vec3(0.f, 1.f, 0.f));
                        temp[y][2 - x] = cubes[x][0][y];
                    }

                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[x][0][y] = temp[x][y];
                    }
                }
            }
            
            break;
        case D:
            for (size_t x = 0; x < 3; x++)
            {
                for (size_t y = 0; y < 3; y++)
                {
                    if (!activeReverse)
                    {
                        cubes[x][2][y]->rotate(speedRotate, glm::vec3(0.f, 1.f, 0.f));
                        temp[y][2 - x] = cubes[x][2][y];
                    }
                    else
                    {
                        cubes[x][2][y]->rotate(-speedRotate, glm::vec3(0.f, 1.f, 0.f));
                        temp[2 - y][x] = cubes[x][2][y];
                    }
                }
            }

            if (!isMoving)
            {
                for (size_t x = 0; x < 3; x++)
                {
                    for (size_t y = 0; y < 3; y++)
                    {
                        cubes[x][2][y] = temp[x][y];
                    }
                }
            }
            break;
        default:
            activeMove = None;
            isMoving = false;
            std::cout << "Error!" << std::endl;
            break;
        }
    }
}

void RubikCube::render(Shader* shaderProgram)
{
    for (auto& x : cubes)
    {
        for (auto& y : x)
        {
            for (auto& z : y)
            {
                z->render(*shaderProgram);
            }
        }
    }
}
