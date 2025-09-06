
# C++ Physics Engine

A simple 2D physics engine built with **C++** and **modern OpenGL**.

---

## 🚀 Build and Run Options

You can run the project in two ways:

1. **Using Docker (Recommended):** Clean, self-contained, works on any machine without manual library setup.  
2. **Natively:** Using a bash script with your own compiler and libraries.

---

## 🌿 Branches

- **`main`** → Clean code base (basic windowing and rendering, no ball simulation).  
- **`Add/Delete-balls`** → Development branch with full interactive simulation (add and delete balls).  

👉 For the full experience, use the **`Add/Delete-balls`** branch.

---

## 📥 Getting Started

Clone the repository:

```bash
git clone https://github.com/your-username/physics-engine.git
cd physics-engine
git switch Add/Delete-balls
```

# Method 1: Running with Docker


## Prerequisites: Docker installed and running
```bash
sudo systemctl start docker
sudo systemctl enable docker   # optional
sudo docker run hello-world    # test installation
```
## Allow display access (Linux only)
```bash
xhost +local:
```
## Build Docker image
```bash
docker build -t physics-engine .
```
## Run application
```bash 
docker run --rm -it \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  physics-engine
```

# Method 2: Running Natively


## Prerequisites: Ubuntu/Debian packages
```bash 
sudo apt-get update
sudo apt-get install build-essential cmake pkg-config \
  libgl1-mesa-dev libglew-dev freeglut3-dev libglfw3-dev libeigen3-dev
``` 
## Configure project (first time only)
```bash 
mkdir build
cd build
cmake ..
cd ..
``` 
## Make script executable
```bash 
chmod +x go.sh
```
## Run the script
```bash
./go.sh
``` 
