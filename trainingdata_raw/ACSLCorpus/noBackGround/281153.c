#include <stdbool.h>

/*@ requires ((a) != (b) && (b) != (c) && (a) != (c) &&
      0 <= (a) && (a) <= 100 &&
      0 <= (b) && (b) <= 100 &&
      0 <= (c) && (c) <= 100);
    ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((c) < (b) && (b) < (a)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert a <= 100;
    
    if ((a < b && b < c) || (c < b && b < a)) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
