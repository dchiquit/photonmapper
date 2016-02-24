
namespace {
	class Color {
		public:
			const double r;
			const double g;
			const double b;
			Color(double r, double g, double b);
			Color(Color c);
			Color operator+ (Color c);
	}
}