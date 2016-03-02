

#include "scene/Scene.h"

namespace graphics {

    Scene::Scene() {

    }

    Scene::~Scene() {

    }

    void Scene::addLight(Light* light) {
        lights.insert(lights.end(), light);
    }

    Light* Scene::getLight(int index) const {
        return lights[index];
    }

    int Scene::numLights() const {
        return lights.size();
    }
}