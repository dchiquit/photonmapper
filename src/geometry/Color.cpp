
namespace graphics {

	Color::Color(double r, double g, double b) : r(r), g(g), b(b) {}
	
	Color::Color(const Color& c) : r(c.r), g(c.g), b(c.b) {}
	
	Color::Color operator+ (const Color& c) {
		return Color(r+c.r, g+c.g, b+c.b);
	}
}
