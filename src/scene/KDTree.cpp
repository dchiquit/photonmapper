

#include "KDTree.h"

namespace graphics {

	bool KDTree::intersects(Ray r) const {
		return false;
	}

	Surface KDTree::intersection(Ray r) const {
		return Surface(this, r, 1, Vector3D(1,1,1));
	}

	Vector3D KDTree::getLowerBound() const {
		return lowerBound;
	}
	
	Vector3D KDTree::getUpperBound() const {
		return lowerBound;
	}
}