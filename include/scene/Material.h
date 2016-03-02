#ifndef SRC_MATERIAL_H_
#define SRC_MATERIAL_H_

#include "geometry/Geometry.h"

namespace graphics {

    class Material {
    public:
        Material(double n);
        virtual ~Material();

        const double n;
    };
}

#endif /* SRC_MATERIAL_H_ */
