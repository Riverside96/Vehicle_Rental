#include "vehicle.h"
class bike: public vehicle {



public:
  bike(int engineCC, int numOfWheels, string reg, string make, string model, int age);
  ~bike();
  double costPerDay();

private:
  const int numOfWheels;
  const int engineCC;
};
