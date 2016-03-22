
#include "scene/PointLight.h"

namespace graphics {

    PointLight::PointLight(const Vector3D& pos) : pos(pos), radius(0) {
    }

    PointLight::~PointLight() {
    }

    bool PointLight::canSee(const Scene& scene, const Vector3D& point) const override {
        return scene.intersects(towardsLight(point));
    }

    Ray PointLight::towardsLight(const Vector3D& point) const override {
        return Ray(point, pos - point);
    }

}