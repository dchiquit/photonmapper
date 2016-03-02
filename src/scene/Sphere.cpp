
#include <iostream>
#include <cmath>
#include "scene/Sphere.h"

namespace graphics {

    Sphere::Sphere(Vector3D pos, double radius) : pos(pos), radius(radius) {
    }

    Sphere::~Sphere() {
    }

    bool Sphere::intersects(Ray r) const {
        Vector3D oc = r.getStart() - pos;
        double tmp = (r.getDirection() * oc);
        tmp *= tmp;
        tmp -= oc*oc;
        tmp += radius*radius;
        return (tmp >= 0);
    }

    double Sphere::intersectDistance(Ray r) const {
        Vector3D oc = r.getStart() - pos;
        double tmp = (r.getDirection() * oc);
        tmp *= tmp;
        tmp -= oc*oc;
        tmp += radius*radius;
        if (tmp < 0) return -1;
        tmp = sqrt(tmp);
        double p = (r.getDirection() * oc) * -1;
        if (p - tmp > 0) return p - tmp;
        if (p + tmp > 0) return p + tmp;
        return -1;
    }

    Surface Sphere::intersection(Ray r) const {
        double dist = intersectDistance(r);
        if (dist < 0) return Surface(NULL, r, 0, Vector3D(0, 0, 0));

        return Surface(this, r, dist, (r.evaluateAtT(dist) - pos).normalized());
    }

    Vector3D Sphere::getLowerBound() const {
        return pos - Vector3D(radius, radius, radius);
    }

    Vector3D Sphere::getUpperBound() const {
        return pos + Vector3D(radius, radius, radius);
    }

}