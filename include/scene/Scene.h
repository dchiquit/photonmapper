#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

#include <vector>

#include "geometry/Geometry.h"
#include "scene/Object.h"
#include "scene/Group.h"

namespace graphics {

    class Light;

    class Scene : public Group {
        using Group::Group;
    private:
        std::vector<Light*> lights;

    public:
        Scene();
        virtual ~Scene();

        void addLight(Light* light);
        Light* getLight(int index) const;
        int numLights() const;
    };
}

#endif /* SRC_SCENE_H_ */
