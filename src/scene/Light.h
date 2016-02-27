

#ifndef SRC_LIGHT_H_
#define SRC_LIGHT_H_

#include "Geometry.h"
#include "scene\Surface.h"
#include "scene\Object.h"
#include "scene\Scene.h"

namespace graphics {

	class Light {
		public:
			virtual bool canSee(Scene scene, Vector3D point) const;
			virtual Ray towardsLight(Vector3D point) const;
	};
}


#endif /* SRC_LIGHT_H_ */