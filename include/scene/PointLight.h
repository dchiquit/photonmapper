

#ifndef SRC_POINTLIGHT_H_
#define SRC_POINTLIGHT_H_

#include "scene/Light.h"

namespace graphics {

    class PointLight : public Light {
    private:
        const Vector3D pos;
    public:
        PointLight(Vector3D pos);
        virtual ~PointLight();

        virtual bool canSee(Scene scene, Vector3D point) const;
        virtual Ray towardsLight(Vector3D point) const;
    };
}


#endif /* SRC_LIGHT_H_ */
