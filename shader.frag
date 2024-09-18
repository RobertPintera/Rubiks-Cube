#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 texCoord;

void main()
{
	if (texCoord.x < 0.9f && texCoord.x > 0.1f &&
       texCoord.y < 0.9f && texCoord.y > 0.1f)
    {
        FragColor = vec4(ourColor, 1.0f);
    } 
    else 
    {
        FragColor = vec4(0.f,0.f,0.f,0.f);
    } 
	
}