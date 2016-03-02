/*
 * Ray.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Andrew
 */

#include "geometry/Ray.h"
#include "geometry/Vector3D.h"
#include <algorithm>


namespace graphics {

    Ray::Ray(Vector3D start, Vector3D direction) :
    start(start),
    direction(direction.normalized()),
    inverse(Vector3D(
    1 / direction.x,
    1 / direction.y,
    1 / direction.z)
    ) {
    }

    //	Ray::Ray(const Ray &ray) :
    //			start( { ray.start }), direction( { ray.direction.normalized() } ) {
    //	}

    Ray::~Ray() {
    }

    Vector3D Ray::getStart() const {
        return start;
    }

    Vector3D Ray::getDirection() const {
        return direction;
    }

    Vector3D Ray::evaluateAtT(double t) const {
        auto offset = direction * t;
        return start + offset;
    }

    bool Ray::intersectsBox(Vector3D lowerBound, Vector3D upperBound) {
        double tx1 = (lowerBound.x - start.x) * inverse.x;
        double tx2 = (upperBound.x - start.x) * inverse.x;
        double ty1 = (lowerBound.y - start.y) * inverse.y;
        double ty2 = (upperBound.y - start.y) * inverse.y;
        double tz1 = (lowerBound.z - start.z) * inverse.z;
        double tz2 = (upperBound.z - start.z) * inverse.z;
        double tmax = std::min(
                std::min(
                POS_INF,
                std::max(tx1, tx2)),
                std::min(
                std::max(ty1, ty2),
                std::max(tz1, tz2)
                )
                );
        double tmin = std::max(
                std::max(
                NEG_INF,
                std::min(tx1, tx2)),
                std::max(
                std::min(ty1, ty2),
                std::min(tz1, tz2)
                )
                );
        return tmax >= tmin;
    }

    std::ostream& operator<<(std::ostream &outs, const Ray &ray) {
        return outs << "Ray [" << ray.start << ", " << ray.direction << "]";
    }
}
