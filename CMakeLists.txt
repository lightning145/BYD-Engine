cmake_minimum_required(VERSION 3.16)

project(Main)

add_executable(Main 
        ${CMAKE_CURRENT_SOURCE_DIR}/3rd/glad4.6/src/glad.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Direct3D9/Direct3D9.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL4.6/OGL.cpp
        Graphics.cpp
        Window.cpp
        Main.cpp)

target_include_directories(Main PUBLIC 
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/glad4.6/include
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw-3.4/include
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/glm1.0.1
)

target_link_libraries(Main 
                libopengl32.a

                libmingw32.a
                libkernel32.a 
                libmsvcrt.a 
                libuser32.a 
                libwldap32.a 
                libvfw32.a 
                libmingwex.a 
                libwldap32.a  
                libbfd.a 
                libiberty.a

                libsetupapi.a
                libwinmm.a
                libimm32.a
                libversion.a

                libd3d9.a
                libd3dx9.a

                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/glfw-3.4/lib/libglfw3.a

)