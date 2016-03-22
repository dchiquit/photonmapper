

#ifndef SRC_POINTLIGHT_H_
#define SRC_POINTLIGHT_H_

#include "scene/Light.h"

namespace graphics {

    class PointLight : public Light {
    private:
        const Vector3D pos;
    public:
        PointLight(const Vector3D& pos);
        virtual ~PointLight();

        virtual bool canSee(const Scene& scene, const Vector3D& point) const;
        virtual Ray towardsLight(const Vector3D& point) const;
    };
}


#endif /* SRC_LIGHT_H_ */
