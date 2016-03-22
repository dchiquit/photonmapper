

#ifndef SRC_LIGHT_H_
#define SRC_LIGHT_H_

#include "geometry/Geometry.h"
#include "scene/Surface.h"
#include "scene/Object.h"
#include "scene/Scene.h"

namespace graphics {

    class Light {
    public:
        Light(const float _radius);
        virtual ~Light();

        const float radius;

        virtual bool canSee(const Scene& scene, const Vector3D& point) const;
        virtual Ray towardsLight(const Vector3D& point) const;

        bool isPoint() const;
    };
}


#endif /* SRC_LIGHT_H_ */
