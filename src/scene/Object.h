

#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include "Geometry.h"
#include "scene\Surface.h"

namespace graphics {
	class Object {
		public:
			virtual bool intersects(Ray r) const;
			virtual double intersectDistance(Ray r) const;
			virtual Surface intersection(Ray r) const;
			virtual Vector3D getLowerBound() const;
			virtual Vector3D getUpperBound() const;
	};
}


#endif /* SRC_OBJECT_H_ */