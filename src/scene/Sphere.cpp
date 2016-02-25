
#include <iostream>
#include <cmath>
#include "Sphere.h"

namespace graphics {

	Sphere::Sphere(Vector3D pos, double radius) : pos(pos), radius(radius) {}
	
	bool Sphere::intersects(Ray r) const {
		Vector3D oc = r.getStart() - pos;
		double tmp = (r.getDirection()*oc);
		tmp *= tmp;
		tmp -= oc*oc;
		tmp += radius*radius;
		return tmp >= 0;
	}
	
	Surface Sphere::intersection(Ray r) const {
		return Surface(this, r, 1, Vector3D(1,1,1));
	}
	
	Vector3D Sphere::getLowerBound() const {
		return pos - Vector3D(radius, radius, radius);
	}
	
	Vector3D Sphere::getUpperBound() const {
		return pos + Vector3D(radius, radius, radius);
	}
	
}