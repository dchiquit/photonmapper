
#include "scene/BlackBodyPointLight.h"

#include <cmath>

namespace graphics {

    BlackBodyPointLight::BlackBodyPointLight(const Vector3D& pos, double temp) : PointLight(pos) {
        long double h = 6.626070040E-34;
        double c = 299792458;
        long double k = 1.38064852E-23;
        for(int i = 0; i < 81; i++) {
            int nm = 380+i*5;
            double L = 0.000000001*nm;
            spd[i] = ((long double)2)*h*c/(L*L*L*std::expm1(h*c/(k*L*temp)));
        }
    }

    BlackBodyPointLight::~BlackBodyPointLight() {
    }

}