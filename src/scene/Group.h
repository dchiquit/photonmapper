
#ifndef SRC_GROUP_H_
#define SRC_GROUP_H_

#include <vector>
#include "Object.h"

namespace graphics {
	class Group {
		private:
			std::vector<Object> objects;
		public:
			void addObject(Object o);
	};
}


#endif /* SRC_GROUP_H_ */