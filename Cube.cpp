#include "Cube.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const char* Cube::vertexs=
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "uniform mat4 trans;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = trans * vec4(aPos, 1.0);\n"
    "}\0";

const char* Cube::fragments =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0" ;

float Cube::cvertices[] = {
    -0.5f, -0.5f,  0.0f, // 0
     0.5f, -0.5f,  0.0f, // 1
     -0.5f,  0.5f,  0.0f, // 2
      0.5f,  0.5f,  0.0f  // 3
};

unsigned int Cube::cindices[] = {
        0,2,3,
        3,1,0
};

Cube::Cube()
{
    shader = new ShaderFromSource(vertexs,fragments);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cindices), cindices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cvertices), cvertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);   
}

Cube::~Cube()
{
    delete shader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1,&EBO);
}

void Cube::Draw(float x,float y,float z)
{

    shader->Use();
    GLuint gtrans = shader->GetShaderSourceUniform("trans");

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(x,y,z));
    glUniformMatrix4fv(gtrans, 1, GL_FALSE, glm::value_ptr(trans));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}