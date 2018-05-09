#include <string>
#include "Coordination.h"

using namespace std;

class IllegalCoordinateException {
  private:
    const Coordination& c;
    
  public:
	  IllegalCoordinateException(const Coordination& c): c(c) { }
      
      string theCoordination() const{
          return string(to_string(c.getX()) + "," + to_string(c.getY()));
      }  
};