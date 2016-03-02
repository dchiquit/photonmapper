
#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

namespace graphics {

    class Color {
    public:

        enum class ColorSpace {
            RGB, XYZ, HSL, HSV
        };

        Color(float r, float g, float b);
        Color(float a, float b, float c, ColorSpace cSpace);
        Color(const Color& c);
        
        virtual ~Color();

        const float r;
        const float g;
        const float b;

        const ColorSpace colorSpace;

        Color inColorSpace(ColorSpace targetSpace) const;

        Color operator+(const Color& c);
        Color operator*(const double d);
    private:
        // xy for red/green/blue/white in Rec709/sRGB
        const float xr = 0.6400, yr = 0.3300, zr = 1-xr-yr;
        const float xg = 0.3000, yg = 0.6000, zg = 1-xg-yg;
        const float xb = 0.1500, yb = 0.0600, zb = 1-xb-yb;
        const float xw = 0.3127, yw = 0.3290, zw = 1-xw-yw;

        Color xyz_to_rgb() const;
        Color rgb_to_xyz() const;
        Color hsl_to_rgb() const;
        Color rgb_to_hsl() const;
        Color hsv_to_rgb() const;
        Color rgb_to_hsv() const;
        Color hsv_to_hsl() const;
        Color hsl_to_hsv() const;
    };
}

#endif /* SRC_COLOR_H_ */
