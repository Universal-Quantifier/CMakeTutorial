#include <iostream>
#include <cmath>
double mysqrt(double inputValue) {
	//std::cout << "this is in the function of mysqrt" << std::endl;
	#if defined(HAVE_LOG) && defined(HAVE_EXP)
		std::cout << "Computing sqrt of " << inputValue << " to be " << exp(log(inputValue) * 0.5)
            << " using log and exp" << std::endl;
		return exp(log(inputValue) * 0.5);
	#else
		return sqrt(inputValue);
	#endif
}