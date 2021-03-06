/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SphereLight.h
 * Author: Andrew
 *
 * Created on March 2, 2016, 3:39 PM
 */

#ifndef SPHERELIGHT_H
#define SPHERELIGHT_H

#include <random>
#include "Light.h"
#include "geometry/Vector3D.h"

namespace graphics {

    class SphereLight : public Light {
    public:
        SphereLight(const Vector3D pos, const float _radius);
        SphereLight(const SphereLight& orig);
        virtual ~SphereLight();
        
        const Vector3D pos;
    private:
        std::minstd_rand randEngine;
        std::uniform_real_distribution<float> dist;
        Vector3D pointInSphere();
    };
}

#endif /* SPHERELIGHT_H */

