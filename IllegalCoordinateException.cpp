#include <string>
#include "Coordination.h"

using namespace std;

class IllegalCoordinateException {
  private:
    const Coordination& _coordination;
    
  public:
	  IllegalCoordinateException(const Coordination& illegalCoordination): _coordination(illegalCoordination) { }
      
      string theCoordinate() const{
          return string(to_string(_coordination.getXCoordination()) + "," + to_string(_coordination.getYCoordination()));
      }  
};
