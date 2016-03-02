

#include <iostream>
#include "render/Render.h"

namespace graphics {

    inline void setPixel(float* buffer, int width, int height, int x, int y, Color color) {
        buffer[y * width * 3 + x * 3 + 0] = color.r;
        buffer[y * width * 3 + x * 3 + 1] = color.g;
        buffer[y * width * 3 + x * 3 + 2] = color.b;
    }

    void render(const Scene& scene, float* buffer, int width, int height) {
        double x = L;
        double y = B;
        for (int px = 0; px < width; px++) {
            y = B;
            for (int py = 0; py < height; py++) {
                Ray r = Ray(EYE, (FORWARD * D)+(RIGHT * x)+(UP * y));
                if (scene.intersects(r)) {
                    Surface s = scene.intersection(r);
                    Color* c = new Color(0.1, 0.1, 0.1);
                    for (int l = 0; l < scene.numLights(); l++) {
                        if (scene.getLight(l)->canSee(scene, s.pos)) {
                            double dot = scene.getLight(l)->towardsLight(s.pos).getDirection() * s.normal;
                            c = new Color(*c + (Color(1.0, 0.5, 1.0) * dot));
                        }
                    }
                    setPixel(buffer, width, height, px, py, *c);
                }
                y += (T - B) / height;
            }
            x += (R - L) / width;
        }
    };

}