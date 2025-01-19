#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shader.h"

class Triangle
{
private:
    unsigned int VAO,VBO,EBO;
    
public:
    Triangle(/* args */);
    ~Triangle();

    void Draw(float x,float y,float z);

protected:    
    static const char* vertexs;
    static const char*fragments;

    ShaderFromSource* shader;

    static float vertices[];
    static unsigned int indices[];
    
};

#endif