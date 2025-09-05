#!/bin/bash


set -e

echo "iniciando a compilação do projeto com CMake"

PROJECT_ROOT=$( cd -- "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

echo "Project root: $PROJECT_ROOT"

# Navega para a raiz do projeto (importante!)
cd "$PROJECT_ROOT"

# Compila o projeto que está configurado na pasta 'build'
echo "Compilando o projeto..."
cmake --build build

# Executa o programa
echo "Execução..."
./build/src/exec