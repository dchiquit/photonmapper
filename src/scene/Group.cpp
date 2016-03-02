

#include "scene/Group.h"
#include <algorithm>

namespace graphics {

    Group::Group() {

    }

    Group::Group(Object* seed) {
        addObject(seed);
    }

    Group::~Group() {
    }

    void Group::addObject(Object* obj) {
        objects.insert(objects.end(), obj);
    }

    bool Group::intersects(Ray r) const {
        for (int i = 0; i < objects.size(); i++) {
            if (objects[i]->intersects(r)) {
                return true;
            }
        }
        return false;
    }

    double Group::intersectDistance(Ray r) const {
        double min_distance = POS_INF;
        for (int i = 0; i < objects.size(); i++) {
            double t = objects[i]->intersectDistance(r);
            if (t >= 0 && t < min_distance) {
                min_distance = t;
            }
        }
        if (min_distance == POS_INF) return -1;
        return min_distance;
    }

    Surface Group::intersection(Ray r) const {
        double min_distance = POS_INF;
        int index = 0;
        for (int i = 0; i < objects.size(); i++) {
            double t = objects[i]->intersectDistance(r);
            if (t >= 0 && t < min_distance) {
                min_distance = t;
                index = i;
            }
        }
        return objects[index]->intersection(r);
    }

    Vector3D Group::getLowerBound() const {
        double x = objects[0]->getLowerBound().x;
        double y = objects[0]->getLowerBound().y;
        double z = objects[0]->getLowerBound().z;
        for (int i = 1; i < objects.size(); i++) {
            Vector3D t = objects[i]->getLowerBound();
            x = std::min(x, t.x);
            y = std::min(y, t.y);
            z = std::min(z, t.z);
        }
        return Vector3D(x, y, z);
    }

    Vector3D Group::getUpperBound() const {
        double x = objects[0]->getLowerBound().x;
        double y = objects[0]->getLowerBound().y;
        double z = objects[0]->getLowerBound().z;
        for (int i = 1; i < objects.size(); i++) {
            Vector3D t = objects[i]->getLowerBound();
            x = std::min(x, t.x);
            y = std::min(y, t.y);
            z = std::min(z, t.z);
        }
        return Vector3D(x, y, z);
    }
}