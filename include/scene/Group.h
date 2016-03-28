
#ifndef SRC_GROUP_H_
#define SRC_GROUP_H_

#include <vector>
#include <memory>

#include "geometry/Geometry.h"
#include "scene/Object.h"
#include "scene/Surface.h"

namespace graphics {

    class Group : public Object {
    private:
        std::vector<std::shared_ptr<Object>> objects;
    public:
        Group();
        Group(std::shared_ptr<Object> seed);
        virtual ~Group();

        void addObject(std::shared_ptr<Object> o);

        virtual bool intersects(Ray r) const;
        virtual double intersectDistance(Ray r) const;
        virtual Surface intersection(Ray r) const;
        virtual Vector3D getLowerBound() const;
        virtual Vector3D getUpperBound() const;
    };
}


#endif /* SRC_GROUP_H_ */
