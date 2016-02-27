
#ifndef SRC_GROUP_H_
#define SRC_GROUP_H_

#include <vector>
#include "Geometry.h"
#include "Object.h"
#include "Surface.h"

namespace graphics {
	class Group : public Object {
		private:
			std::vector<Object*> objects;
		public:
			Group(Object* seed);
			void addObject(Object* o);
			bool intersects(Ray r) const;
			double intersectDistance(Ray r) const;
			Surface intersection(Ray r) const;
			Vector3D getLowerBound() const;
			Vector3D getUpperBound() const;
	};
}


#endif /* SRC_GROUP_H_ */