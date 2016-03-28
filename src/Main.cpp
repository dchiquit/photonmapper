

#include <iostream>
#include <memory>

#include "geometry/Geometry.h"
#include "scene/Scene.h"
#include "scene/Sphere.h"
#include "scene/PointLight.h"
#include "render/Render.h"
#include "render/OpenGLDisplay.h"

using namespace graphics;

int main(int argc, char** argv) {
    std::cout << "TESSSST" << std::endl;

    const int width = 500;
    const int height = width;
    std::cout << "test" << std::endl;
    auto bufPtr = std::make_shared<float*>(new float[width*height*3]);
    float* buffer = *bufPtr;
    std::cout << "test2" << std::endl;
    for (int i = 0; i < height * width * 3; i++) {
        buffer[i] = 0.0f;
    }
    
    auto sphere = std::make_shared<Sphere>(Vector3D{0, 0, -7}, 2);
    Scene scene{sphere};
    scene.addObject(std::make_shared<Sphere>(Vector3D{4, 0, -7}, 1));
    scene.addObject(std::make_shared<Sphere>(Vector3D{0, 4, -7}, 2));
    scene.addLight(std::make_shared<PointLight>(Vector3D{-4, 4, 3}));

    render(scene, buffer, width, height);

    OpenGL_display(&argc, argv, buffer, width, height);
};
