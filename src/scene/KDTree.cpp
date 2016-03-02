

#include "scene/KDTree.h"
#include "scene/Object.h"
#include "scene/Surface.h"
#include "geometry/Vector3D.h"
#include "geometry/Ray.h"

namespace graphics {

    KDTree::KDTree(KDTree parent, Object objects[], int count, Vector3D lowerBound, Vector3D upperBound, int depth) : isLeaf(true) {

    }

    KDTree::~KDTree() {

    }

    bool KDTree::intersects(Ray r) const {
        return false;
    }

    Surface KDTree::intersection(Ray r) const {
        return Surface(NULL, r, 0, Vector3D(0, 0, 0));
    }

    Vector3D KDTree::getLowerBound() const {
        return lowerBound;
    }

    Vector3D KDTree::getUpperBound() const {
        return lowerBound;
    }
}