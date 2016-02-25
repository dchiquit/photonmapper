/*
 * Ray.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#include "Ray.h"
#include "Vector3D.h"

namespace graphics {

	Ray::Ray(Vector3D start, Vector3D direction) :
			start(start), direction(direction), normalized(
					direction.normalized()) {
	}

	Ray::Ray(const Ray &ray) :
			start( { ray.start }), direction( { ray.direction }), normalized( {
					ray.normalized }) {
	}

	Ray::~Ray() {
	}

	Vector3D Ray::getStart() const {
		return start;
	}

	Vector3D Ray::getDirection() const {
		return direction;
	}

	Vector3D Ray::getNormalized() const {
		return normalized;
	}

	Vector3D Ray::evaluateAtT(double t) const {
		auto offset = normalized * t;
		return start + offset;
	}

	std::ostream& operator<<(std::ostream &outs, const Ray &ray) {
		return outs << "Ray [" << ray.start << ", " << ray.direction << "]";
	}
}
