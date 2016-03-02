
#include "scene/Light.h"

namespace graphics {

    Light::Light() {

    }

    Light::~Light() {
    }

    bool Light::canSee(Scene scene, Vector3D point) const {
        return false;
    }

    Ray Light::towardsLight(Vector3D point) const {
        return Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 0));
    }

}