
#include "scene/Surface.h"
#include "scene/Material.h"

#include <cmath>

namespace graphics {

    Surface::Surface(const Object* obj, Ray ray, double distance, Vector3D normal) :
    obj(obj), src_ray(ray), distance(distance), pos(ray.evaluateAtT(distance)), normal(normal.normalized()) {
    };

    Surface::~Surface() {

    }

    Ray Surface::reflect() const {
        return Ray(pos, src_ray.getDirection() + (normal * -2 * (normal * src_ray.getDirection())));
    }

    Ray Surface::refract(Material a, Material b) const {
        double dot = -(normal * src_ray.getDirection());
        double n = a.n / b.n;
        double c2 = sqrt(1 - n * n * (1 - dot * dot));
        return Ray(pos, (src_ray.getDirection() * n) + (normal * (n * dot - c2)));
    }
}