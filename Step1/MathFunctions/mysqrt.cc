#include <iostream>
//#include <cmath>
#include <Table.h>
double mysqrt(double inputValue) {
	if (inputValue <= 0) {
    return 0;
  }

  // use the table to help find an initial value
  double result = inputValue;
  if (inputValue >= 1 && inputValue < 10) {
    std::cout << "Use the table to help find an initial value " << std::endl;
    result = sqrtTable[static_cast<int>(inputValue)];
  }

  // do ten iterations
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = inputValue - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << inputValue << " to be " << result << std::endl;
  }

  return result;
}