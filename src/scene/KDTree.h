
#ifndef SRC_KDTREE_H_
#define SRC_KDTREE_H_

#include "Geometry.h"
#include "scene\Object.h"

namespace graphics {
	class KDTree : public Object {
		private:
			const KDTree* left;
			const KDTree* right;
			const bool isLeaf;
			const Object objects[];
			const Vector3D lowerBound;
			const Vector3D upperBound;
		public:
			//KDTree(Object objects[], int count, Vector3D lowerBound, Vector3D upperBound);
			KDTree(KDTree parent, Object objects[], int count, Vector3D lowerBound, Vector3D upperBound, int depth);
			bool intersects(Ray r) const;
			Surface intersection(Ray r) const;
			Vector3D getLowerBound() const;
			Vector3D getUpperBound() const;
	};
}


#endif /* SRC_KDTREE_H_ */