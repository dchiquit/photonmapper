#include "color.h"
namespace graphics {

	Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}
	
	Color::Color(const Color& c) : r(c.r), g(c.g), b(c.b) {}
	
	Color Color::operator+ (const Color& c) {
		return Color(r+c.r, g+c.g, b+c.b);
	}
	
	Color Color::operator* (const double d) {
		return Color(r*d, g*d, b*d);
	}
}
