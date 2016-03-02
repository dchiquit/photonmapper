
#ifndef SRC_KDTREE_H_
#define SRC_KDTREE_H_

#include "geometry/Geometry.h"
#include "scene/Object.h"

namespace graphics {

    class KDTree : public Object {
    private:
        KDTree* left;
        KDTree* right;
        bool isLeaf;
        Object objects[];
        Vector3D lowerBound;
        Vector3D upperBound;
    public:
        //KDTree(Object objects[], int count, Vector3D lowerBound, Vector3D upperBound);
        KDTree(KDTree parent, Object objects[], int count, Vector3D lowerBound, Vector3D upperBound, int depth);
        virtual ~KDTree();

        virtual bool intersects(Ray r) const;
        virtual Surface intersection(Ray r) const;
        virtual Vector3D getLowerBound() const;
        virtual Vector3D getUpperBound() const;
    };
}


#endif /* SRC_KDTREE_H_ */
