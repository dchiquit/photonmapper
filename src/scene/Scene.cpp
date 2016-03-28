

#include "scene/Scene.h"

namespace graphics {

    Scene::Scene() {

    }

    Scene::~Scene() {

    }

    void Scene::addLight(std::shared_ptr<Light> light) {
        lights.push_back(light);
    }

    std::shared_ptr<Light> Scene::getLight(int index) const {
        return lights[index];
    }

    int Scene::numLights() const {
        return lights.size();
    }
}