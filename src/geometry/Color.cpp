#include "geometry/Color.h"
#include <array>
#include <cmath>
namespace graphics {

    Color::Color(float r, float g, float b) :
    r(r), g(g), b(b), colorSpace(ColorSpace::RGB) {
    }

    Color::Color(float r, float g, float b, ColorSpace cSpace) :
    r(r), g(g), b(b), colorSpace(cSpace) {
    }

    Color::Color(const Color& c) :
    r(c.r), g(c.g), b(c.b), colorSpace(c.colorSpace) {
    }
    
    Color::Color(std::function<float(int)> spd) : 
    r(0), g(0), b(0), colorSpace(ColorSpace::XYZ) {
        int wavelength = 380;
        for(int i = 0; i < colorMatchXYZ.size(); i ++, wavelength += 5) {
            auto intensity = spd(wavelength);
            r += intensity * colorMatchXYZ[i][0];
            g += intensity * colorMatchXYZ[i][1];
            b += intensity * colorMatchXYZ[i][2];
        }
    }
    
    Color::Color(std::array<float, 81> spd) : 
    r(0), g(0), b(0), colorSpace(ColorSpace::XYZ) {
        for(int i = 0; i < colorMatchXYZ.size(); i ++) {
            auto intensity = spd[i];
            r += intensity * colorMatchXYZ[i][0];
            g += intensity * colorMatchXYZ[i][1];
            b += intensity * colorMatchXYZ[i][2];
        }
    }

    Color::~Color() {
    }

    Color Color::gammaCorrected(double gamma) const {
        float cr, cg, cb;
        switch (colorSpace) {
            case ColorSpace::RGB:
                cr = r, cb = b, cg = g;
                break;
            case ColorSpace::XYZ: {
                auto xyz = xyz_to_rgb();
                cr = xyz.r, cb = xyz.g, cg = xyz.b;
                break;
            }
            case ColorSpace::HSL: {
                auto hsl = hsl_to_rgb();
                cr = hsl.r, cb = hsl.g, cg = hsl.b;
                break;
            }
            case ColorSpace::HSV: {
                auto hsv = hsv_to_rgb();
                cr = hsv.r, cb = hsv.g, cg = hsv.b;
                break;
            }
            default:
                break;
        }

        cr = pow(cr, gamma);
        cg = pow(cg, gamma);
        cb = pow(cb, gamma);

        Color rgb = Color{cr, cg, cb, ColorSpace::RGB};

        switch (colorSpace) {
            case ColorSpace::RGB:
            default:
                return rgb;
            case ColorSpace::XYZ:
                return rgb.rgb_to_xyz();
            case ColorSpace::HSL:
                return rgb.rgb_to_hsl();
            case ColorSpace::HSV:
                return rgb.rgb_to_hsv();
        }
    }

    Color Color::invGammeCorrected(double gamma) const {
        return gammaCorrected(1 / gamma);
    }

    Color Color::inColorSpace(ColorSpace targetSpace) const {
        if (colorSpace != targetSpace) {
            switch (colorSpace) {
                case ColorSpace::RGB:
                    switch (targetSpace) {
                        case ColorSpace::XYZ:
                            return rgb_to_xyz();
                        case ColorSpace::HSL:
                            return rgb_to_hsl();
                        case ColorSpace::HSV:
                            return rgb_to_hsv();
                        default:
                            break;
                    }
                    break;
                case ColorSpace::XYZ:
                    switch (targetSpace) {
                        case ColorSpace::RGB:
                            return xyz_to_rgb();
                        case ColorSpace::HSL:
                            return xyz_to_rgb().rgb_to_hsl();
                        case ColorSpace::HSV:
                            return xyz_to_rgb().rgb_to_hsv();
                        default:
                            break;
                    }
                    break;
                case ColorSpace::HSL:
                    switch (targetSpace) {
                        case ColorSpace::RGB:
                            return hsl_to_rgb();
                        case ColorSpace::XYZ:
                            return hsl_to_rgb().rgb_to_xyz();
                        case ColorSpace::HSV:
                            return hsl_to_hsv();
                        default:
                            break;
                    }
                    break;
                case ColorSpace::HSV:
                    switch (targetSpace) {
                        case ColorSpace::RGB:
                            return hsv_to_rgb();
                        case ColorSpace::XYZ:
                            return hsv_to_rgb().rgb_to_xyz();
                        case ColorSpace::HSL:
                            return hsv_to_hsl();
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        return Color{r, g, b, colorSpace};
    }

    Color Color::operator+(const Color& c) {
        return Color(r + c.r, g + c.g, b + c.b);
    }

    Color Color::operator*(const double d) {
        return Color(r * d, g * d, b * d);
    }

    /*
     * Adapted from https://www.fourmilab.ch/documents/specrend/specrend.c
     */
    Color Color::xyz_to_rgb() const {
        double rx, ry, rz, gx, gy, gz, bx, by, bz;
        double rw, gw, bw;
        double xc = r, yc = g, zc = b;

        /* xyz -> rgb matrix, before scaling to white. */

        rx = (yg * zb) - (yb * zg);
        ry = (xb * zg) - (xg * zb);
        rz = (xg * yb) - (xb * yg);
        gx = (yb * zr) - (yr * zb);
        gy = (xr * zb) - (xb * zr);
        gz = (xb * yr) - (xr * yb);
        bx = (yr * zg) - (yg * zr);
        by = (xg * zr) - (xr * zg);
        bz = (xr * yg) - (xg * yr);

        /* White scaling factors.
           Dividing by yw scales the white luminance to unity, as conventional. */

        rw = ((rx * xw) + (ry * yw) + (rz * zw)) / yw;
        gw = ((gx * xw) + (gy * yw) + (gz * zw)) / yw;
        bw = ((bx * xw) + (by * yw) + (bz * zw)) / yw;

        /* xyz -> rgb matrix, correctly scaled to white. */

        rx /= rw, ry /= rw, rz /= rw;
        gx /= gw, gy /= gw, gz /= gw;
        bx /= bw, by /= bw, bz /= bw;

        /* rgb of the desired point */

        float r = (rx * xc) + (ry * yc) + (rz * zc);
        float g = (gx * xc) + (gy * yc) + (gz * zc);
        float b = (bx * xc) + (by * yc) + (bz * zc);

        return Color{r, g, b, ColorSpace::RGB};
    }

    Color Color::rgb_to_xyz() const {
        float x = xw;
        float y = yw;

        x += r * (xr - xw);
        y += r * (yr - yw);

        x += b * (xb - xw);
        y += b * (yb - xw);

        x += g * (xg - xw);
        y += g * (yg - yw);

        return Color{x, y, 1 - x - y, ColorSpace::XYZ};
    }

    /*
     * Adapted from https://en.wikipedia.org/wiki/HSL_and_HSV
     */
    Color Color::hsl_to_rgb() const {
        float H = r, S = g, L = b;
        float C = (1 - std::abs(2 * L - 1)) * S;
        short int Hp = H / 60;
        float X = C * (1 - std::abs(Hp % 2 - 1));
        float M = L - 0.5 * C;

        float r = M, g = M, b = M;
        switch ((int) (H / 60)) {
            case 0:
                r += C, g += X, b += 0;
                break;
            case 1:
                r += X, g += C, b += 0;
                break;
            case 2:
                r += 0, g += C, b += X;
                break;
            case 3:
                r += 0, g += X, b += C;
                break;
            case 4:
                r += X, g += 0, b += C;
                break;
            case 5:
                r += C, g += 0, b += X;
                break;
        }

        return Color{r, g, b, ColorSpace::RGB};
    }

    /*
     * Adapted from https://en.wikipedia.org/wiki/HSL_and_HSV
     */
    Color Color::rgb_to_hsl() const {
        float M = std::max(r, std::max(g, b));
        float m = std::min(r, std::min(g, b));
        float C = M - m;
        float Hp;

        if (M == r) {
            Hp = ((int) ((g - b) / C)) % 6;
        } else if (M == g) {
            Hp = ((b - r) / C) + 2;
        } else {
            Hp = ((r - g) / C) + 4;
        }
        float H = 60. * Hp;
        float L = 0.5 * (M + m);
        float S = (C == 0 ? 0 : C / (1 - std::abs(2 * L - 1)));

        return Color{H, S, L, ColorSpace::HSL};
    }

    /*
     * Adapted from https://en.wikipedia.org/wiki/HSL_and_HSV
     */
    Color Color::hsv_to_rgb() const {
        float H = r, S = g, V = b;
        float C = V * S;
        short int Hp = H / 60;
        float X = C * (1 - std::abs(Hp % 2 - 1));
        float M = V - C;

        float r = M, g = M, b = M;
        switch ((int) (H / 60)) {
            case 0:
                r += C, g += X, b += 0;
                break;
            case 1:
                r += X, g += C, b += 0;
                break;
            case 2:
                r += 0, g += C, b += X;
                break;
            case 3:
                r += 0, g += X, b += C;
                break;
            case 4:
                r += X, g += 0, b += C;
                break;
            case 5:
                r += C, g += 0, b += X;
                break;
        }

        return Color{r, g, b, ColorSpace::RGB};
    }

    /*
     * Adapted from https://en.wikipedia.org/wiki/HSL_and_HSV
     */
    Color Color::rgb_to_hsv() const {
        float M = std::max(r, std::max(g, b));
        float m = std::min(r, std::min(g, b));
        float C = M - m;
        float Hp;

        if (M == r) {
            Hp = ((int) ((g - b) / C)) % 6;
        } else if (M == g) {
            Hp = ((b - r) / C) + 2;
        } else {
            Hp = ((r - g) / C) + 4;
        }
        float H = 60. * Hp;
        float V = M;
        float S = (C == 0 ? 0 : C / V);

        return Color{H, S, V, ColorSpace::HSV};
    }

    /*
     * Adapted from http://wiki.secondlife.com/wiki/Color_conversion_scripts#HSV_to_HSL
     */
    Color Color::hsv_to_hsl() const {
        float H = r, S = g, V = b;
        float L = (2 - S) * V;
        S = S * V;
        if (L <= 1) {
            S /= L;
        } else {
            S /= (2 - L);
        }
        L /= 2;

        return Color{H, S, L, ColorSpace::HSL};
    }

    /*
     * Adapted from http://wiki.secondlife.com/wiki/Color_conversion_scripts#HSV_to_HSL
     */
    Color Color::hsl_to_hsv() const {
        float H = r, S = g, L = b;
        L *= 2;
        if (L <= 1) {
            S *= L;
        } else {
            S *= (2 - L);
        }

        float V = (L + S) / 2;
        S = (2 * S) / (L + S);

        return Color{H, S, V, ColorSpace::HSV};
    }
}
