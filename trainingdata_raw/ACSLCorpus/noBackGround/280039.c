#include <stdbool.h>

/*@
  requires x && y == true;
  ensures \result == true;
*/
bool verify_conjunction(bool x, bool y) {
    bool result;
    
    //@ assert x && y;
    result = x && y;
    
    //@ assert x;
    //@ assert y;
    
    return result;
}

int main() {
    return 0;
}
