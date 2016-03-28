

#ifndef SRC_BLACKBODYPOINTLIGHT_H_
#define SRC_BLACKBODYPOINTLIGHT_H_

#include "scene/PointLight.h"

namespace graphics {

    class BlackBodyPointLight : public PointLight {
    public:
        BlackBodyPointLight(const Vector3D& pos, double temp);
        virtual ~BlackBodyPointLight();

//        virtual bool canSee(const Scene& scene, const Vector3D& point) const;
//        virtual Ray towardsLight(const Vector3D& point) const;
        
        std::array<float, 81> spd;
    };
}


#endif /* SRC_BLACKBODYPOINTLIGHT_H_ */
