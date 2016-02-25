/*
 * Ray.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#ifndef SRC_RAY_H_
#define SRC_RAY_H_

#include "geometry\Vector3D.h"

namespace graphics {
	class Ray {
		public:
			Ray(Vector3D start, Vector3D direction);
//			Ray(const Ray &ray);
			virtual ~Ray();

			Vector3D getStart() const;
			Vector3D getDirection() const;

			Vector3D evaluateAtT(double t) const;
			
			bool intersectsBox(Vector3D lowerBound, Vector3D upperBound);

		private:
			const Vector3D start, direction, inverse;
			friend std::ostream& operator<<(std::ostream& outs, const Ray& ray);
	};
}

#endif /* SRC_RAY_H_ */
