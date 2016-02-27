
#include "PointLight.h"

namespace graphics {

	PointLight::PointLight(Vector3D pos) : pos(pos) {}

	bool PointLight::canSee(Scene scene, Vector3D point) const {
		return scene.intersects(towardsLight(point));
	}
	
	Ray PointLight::towardsLight(Vector3D point) const {
		return Ray(point, pos-point);
	}
	
}