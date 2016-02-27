

#ifndef SRC_POINTLIGHT_H_
#define SRC_POINTLIGHT_H_

#include "Light.h"

namespace graphics {
	class PointLight : public Light {
		private:
			Vector3D pos;
		public:
			PointLight(Vector3D pos);
			bool canSee(Scene scene, Vector3D point) const;
			Ray towardsLight(Vector3D point) const;
	};
}


#endif /* SRC_LIGHT_H_ */