
#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

namespace {
	class Color {
		public:
			const double r;
			const double g;
			const double b;
			Color(double r, double g, double b);
			Color(const Color& c);
			Color operator+ (const Color& c);
	};
}
