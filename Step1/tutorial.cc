#include <iostream>
//#include <cstdlib>
#include <cmath>
#include <string>
#include <TutorialConfig.h>
#ifdef USE_MYMATH	// 要定义在TutorialConfig.h的下面，不然没有USE_MYMATH宏
#  include "MathFunctions.h"
#endif

int main(int argc, char *argv[]) {
	if (argc < 2) {
		// report version
		std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
				  << Tutorial_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}
	if (argc == 2) {
		//const double inputValue = atof(argv[1]);
		const double inputValue = std::stod(argv[1]);
		#ifdef USE_MYMATH
			std::cout << mysqrt(inputValue) << std::endl;
		#else
			std::cout << sqrt(inputValue) << std::endl;
		#endif
	}
	return 0;
}