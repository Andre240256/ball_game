# Use a standard Ubuntu image as the base. 22.04 is a good modern choice.
FROM ubuntu:22.04

# Avoid interactive prompts during package installation, which can hang the build.
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists and install all necessary dependencies for your project.
# - build-essential: Contains g++, make, and other core build tools.
# - cmake & pkg-config: Your build system tools.
# - libgl1-mesa-dev, libglew-dev, freeglut3-dev, libglfw3-dev: The graphics libraries you need.
# - libeigen3-dev: The Eigen3 library for linear algebra.
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    libgl1-mesa-dev \
    libglew-dev \
    freeglut3-dev \
    libglfw3-dev \
    libeigen3-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container for subsequent commands.
WORKDIR /usr/src/app

# Copy all your source code from your local machine into the container.
COPY . .

# Create a build directory to keep the build artifacts separate from the source.
RUN mkdir build
WORKDIR /usr/src/app/build

# Run CMake to configure the project. The ".." points to the parent directory
# where the main CMakeLists.txt is located.
RUN cmake ..

# Run make to compile the code and create the executable.
RUN make

# Set the default command to run when the container starts.
# This will execute your compiled program.
CMD ["/usr/src/app/build/src/exec"]

