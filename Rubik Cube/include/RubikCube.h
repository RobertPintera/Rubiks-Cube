#ifndef RUBIKCUBE_H
#define RUBIKCUBE_H

#include "Cube.h"
#include <memory>

enum optionMove
{
	None, F, R, U, B, L, D, X, Y, Z
};

class RubikCube
{
public:
	RubikCube();

	void update(optionMove move, bool reverse, float deltaTime);
	void render(Shader* shaderProgram);
private:
	std::shared_ptr<Cube>cubes[3][3][3];
	
	float angle;
	bool isMoving;
	bool activeReverse;
	optionMove activeMove;
};

#endif // !RUBIKCUBE_H
