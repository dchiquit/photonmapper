/*
 * Ray.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#ifndef SRC_RAY_H_
#define SRC_RAY_H_

#include "Vector3D.h"

namespace graphics {
	class Ray {
		public:
			Ray(Vector3D start, Vector3D end);
			Ray(Vector3D start, Vector3D direction);
			Ray(const Ray &ray);
			virtual ~Ray();

			Vector3D getStart() const;
			Vector3D getDirection() const;
			Vector3D getNormalized() const;

			Vector3D evaluateAtT(double t) const;

		private:
			const Vector3D start, direction, normalized;
			friend std::ostream& operator<<(std::ostream& outs, const Ray& ray);
	};
}

#endif /* SRC_RAY_H_ */
