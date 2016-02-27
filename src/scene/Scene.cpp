

#include "Scene.h"

namespace graphics {
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