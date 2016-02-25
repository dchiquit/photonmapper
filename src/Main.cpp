

#include <iostream>
#include "scene\Group.h"
#include "geometry\Color.h"
#include "geometry\Ray.h"

using namespace graphics;

int main(int argc, char** argv) {
	Vector3D origin = Vector3D(0,0,0);
	Ray r = Ray(Vector3D(0,0,0),Vector3D(1,0,0));
	std::cout << "hi " << r << std::endl;
};