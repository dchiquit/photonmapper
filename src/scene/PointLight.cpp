
#include "scene/PointLight.h"

namespace graphics {

    PointLight::PointLight(const Vector3D& pos) : Light(0), pos(pos) {
    }

    PointLight::~PointLight() {
    }

    bool PointLight::canSee(const Scene& scene, const Vector3D& point) const {
        return scene.intersects(towardsLight(point));
    }

    Ray PointLight::towardsLight(const Vector3D& point) const {
        return Ray(point, pos - point);
    }

}