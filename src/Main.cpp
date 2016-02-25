

#include <iostream>
#include "geometry\Vector3D.h"
#include "scene\Group.h"
#include "scene\Surface.h"
#include "geometry\Color.h"
#include "geometry\Ray.h"

using namespace graphics;

int main(int argc, char** argv) {
	Vector3D origin = Vector3D(0,0,0);
	Ray r = Ray(Vector3D(0,0,0),Vector3D(1,0,0));
	Surface s = Surface(NULL, r, 1, Vector3D(-1, 1, 0));
	std::cout << "hi " << r << std::endl;
	Ray reflect = s.reflect();
	std::cout << "strt " << reflect.getStart() << std::endl;
	std::cout << "dir " << reflect.getDirection() << std::endl;
	Ray refract = s.refract(Material(1.000277), Material(1.5));
	std::cout << "strt " << refract.getStart() << std::endl;
	std::cout << "dir " << refract.getDirection() << std::endl;
};