# Define a versão mínima do CMake necessária para este projeto
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto e especifica que a linguagem é C++
project(Physics_Engine)

# Adiciona o padrão C++11 para garantir compatibilidade
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Procura as bibliotecas necessárias. O "REQUIRED" faz o CMake dar um erro se não as encontrar.
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# Cria o nosso programa executável a partir do ficheiro main.cpp
add_executable(exec main.cpp window/window.cpp object/ball.cpp object/vector_balls.cpp)

target_include_directories(exec PRIVATE window)
target_include_directories(exec PRIVATE object)
target_include_directories(exec PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(exec PRIVATE ${EIGEN3_INCLUDE_DIRS})

# Liga as bibliotecas que o CMake encontrou ao nosso programa
target_link_libraries(exec PUBLIC
    OpenGL::GL
    GLEW::GLEW
    GLUT::GLUT
    ${GLFW_LIBRARIES}
)