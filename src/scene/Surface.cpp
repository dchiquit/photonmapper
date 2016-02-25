
#include "Surface.h"
#include "Material.h"

#include <cmath>

namespace graphics {
	Surface::Surface(Object* obj, Ray ray, double distance, Vector3D normal) :
		obj(obj), src_ray(ray), pos(ray.evaluateAtT(distance)), normal(normal.normalized()) {};
	Ray Surface::reflect() const {
		return Ray(pos, src_ray.getDirection() + (normal * -2 * (normal*src_ray.getDirection())));
	}
	Ray Surface::refract(Material a, Material b) const {
		double dot = -(normal*src_ray.getDirection());
		double n = a.n / b.n;
		double c2 = sqrt(1 - n*n*(1-dot*dot));
		return Ray(pos, (src_ray.getDirection()*n) + (normal*(n*dot - c2)));
	}
}