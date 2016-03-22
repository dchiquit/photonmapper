
#include "scene/Light.h"

namespace graphics {

    Light::Light(const float _radius) : radius(_radius) {

    }

    Light::~Light() {
    }

    bool Light::canSee(const Scene& scene, const Vector3D& point) const {
        return false;
    }

    Ray Light::towardsLight(const Vector3D& point) const {
        return Ray(Vector3D(0, 0, 0), Vector3D(0, 0, 0));
    }

    bool Light::isPoint() const {
        return radius == 0;
    }
}