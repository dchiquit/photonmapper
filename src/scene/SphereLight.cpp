/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SphereLight.cpp
 * Author: Andrew
 * 
 * Created on March 2, 2016, 3:39 PM
 */

#include <random>

#include "scene/SphereLight.h"

namespace graphics {

    SphereLight::SphereLight(const Vector3D pos, const float _radius) : Light(_radius), pos(pos), dist(std::uniform_real_distribution<float>{0, _radius}) {
        std::random_device r;
        std::seed_seq seed{r(), r(), r(), r(), r(), r()};
        randEngine = std::minstd_rand{seed};
    }

    SphereLight::SphereLight(const SphereLight & orig) : Light(orig.radius), pos(orig.pos), dist(orig.dist) {
    }

    SphereLight::~SphereLight() {
    }

    Vector3D SphereLight::pointInSphere() {
        return {1,1,1};
    }
}