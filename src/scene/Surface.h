
#ifndef SRC_SURFACE_H_
#define SRC_SURFACE_H_

#include "geometry\Vector3D.h"
#include "geometry\Ray.h"
#include "scene\Material.h"

namespace graphics {

	class Object;

	class Surface {
		private:
			const Object* obj;
			const Ray src_ray;
			const Vector3D pos;
			const Vector3D normal;
		public:
			Surface(const Object* obj, Ray ray, double distance, Vector3D normal);
			Ray reflect() const;
			Ray refract(Material a, Material b) const;
	};
}


#endif /* SRC_SURFACE_H_ */