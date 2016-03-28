#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

#include <vector>
#include <memory>

#include "geometry/Geometry.h"
#include "scene/Object.h"
#include "scene/Group.h"

namespace graphics {

    class Light;

    class Scene : public Group {
        using Group::Group;
    private:
        std::vector<std::shared_ptr<Light>> lights;

    public:
        Scene();
        virtual ~Scene();

        void addLight(std::shared_ptr<Light> light);
        std::shared_ptr<Light> getLight(int index) const;
        int numLights() const;
    };
}

#endif /* SRC_SCENE_H_ */
