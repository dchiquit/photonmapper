
#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

namespace graphics {
	class Color {
		public:
			const float r;
			const float g;
			const float b;
			Color(float r, float g, float b);
			Color(const Color& c);
			Color operator+ (const Color& c);
			Color operator* (const double d);
	};
}

#endif /* SRC_COLOR_H_ */