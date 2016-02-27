

#ifndef SRC_SPHERE_H_
#define SRC_SPHERE_H_

#include "Geometry.h"
#include "scene\Surface.h"
#include "scene\Object.h"

namespace graphics {
	class Sphere : public Object {
		private:
			const Vector3D pos;
			const double radius;
		public:
		
			Sphere(Vector3D pos, double r);
		
			bool intersects(Ray r) const;
			double intersectDistance(Ray r) const;
			Surface intersection(Ray r) const;
			Vector3D getLowerBound() const;
			Vector3D getUpperBound() const;
	};
}


#endif /* SRC_SPHERE_H_ */