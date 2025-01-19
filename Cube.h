#ifndef CUBE_H
#define CUBE_H

#include "Shader.h"

class Cube
{
public:
    Cube();
    ~Cube();

    void Draw(float x,float y,float z);

private:

protected:
    unsigned int VAO,VBO,EBO;

    ShaderFromSource* shader;

    static const char* vertexs;
    static const char* fragments;
    static float cvertices[];
    static unsigned int cindices[];

};


#endif