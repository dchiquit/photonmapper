

#include "Object.h"

namespace graphics {
	bool Object::intersects(Ray r) const {
		return false;
	}
	
	double Object::intersectDistance(Ray r) const {
		return -1;
	}
	
	Surface Object::intersection(Ray r) const {
		return Surface(NULL, r, 0, Vector3D(0,0,0));
	}
	
	Vector3D Object::getLowerBound() const {
		return Vector3D(0,0,0);
	}
	
	
	Vector3D Object::getUpperBound() const {
		return Vector3D(0,0,0);
	}
}