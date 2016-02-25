

#include "Object.h"

namespace graphics {
	bool Object::intersects(Ray r) {
		return false;
	}
	
	Surface Object::intersection(Ray r) {
		return Surface(this, r, 0, Vector3D(0,0,0));
	}
	
	Vector3D Object::getLowerBound() {
		return Vector3D(0,0,0);
	}
	
	
	Vector3D Object::getUpperBound() {
		return Vector3D(0,0,0);
	}
}