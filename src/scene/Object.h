

#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include "geometry\Ray.h"
#include "scene\Surface.h"

namespace graphics {
	class Object {
		public:
			virtual bool intersects(Ray r);
			virtual Surface intersection(Ray r);
			virtual Vector3D getLowerBound();
			virtual Vector3D getUpperBound();
	};
}


#endif /* SRC_OBJECT_H_ */