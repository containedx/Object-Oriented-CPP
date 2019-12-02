
#include "Space.h"

#include <limits>
#include "Point.h"
#include <vector>

class SpaceImpl : public Space {
public:

void create(unsigned int dimensions) override ;
unsigned int dimensions() const override ;

private:
unsigned int dimensionsCount;
std::vector<Point> points;
};