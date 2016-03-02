
#ifndef RENDER_H
#define RENDER_H

#include <GL/glut.h>

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_

#include "geometry/Geometry.h"
#include "scene/Scene.h"
#include "scene/Light.h"


namespace graphics {

    const Vector3D EYE = Vector3D(0, 0, 0);
    const Vector3D FORWARD = Vector3D(0, 0, -1).normalized();
    const Vector3D UP = Vector3D(0, 1, 0).normalized();
    const Vector3D RIGHT = FORWARD.cross(UP);

    const double L = -0.1;
    const double R = 0.1;
    const double B = -0.1;
    const double T = 0.1;
    const double D = 0.1;

    void render(const Scene& scene, float* buffer, int width, int height);

}

#endif /* SRC_RENDER_H_ */

#endif // RENDER_H

