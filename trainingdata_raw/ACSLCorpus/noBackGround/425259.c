#include <stdbool.h>

/*@
  requires 1 <= x <= 100;
  requires 1 <= y <= 100;
  ensures \result == true <==> 
          ((x % 2 == 0 && (y % 4 == 0 || y % 4 == 2)) || 
           (x % 2 != 0 && y % 4 == 0));
*/
bool func(unsigned long long x, unsigned long long y) {
    bool result;
    
    if (x % 2 == 0) {
        if (y % 4 == 0 || y % 4 == 2) {
            //@ assert x % 2 == 0 && (y % 4 == 0 || y % 4 == 2);
            result = true;
        } else {
            //@ assert !(x % 2 == 0 && (y % 4 == 0 || y % 4 == 2));
            result = false;
        }
    } else {
        if (y % 4 == 0) {
            //@ assert x % 2 != 0 && y % 4 == 0;
            result = true;
        } else {
            //@ assert !(x % 2 != 0 && y % 4 == 0);
            result = false;
        }
    }
    
    return result;
}
