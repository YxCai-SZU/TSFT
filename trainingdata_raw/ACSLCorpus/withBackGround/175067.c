#include <stdbool.h>

/*@ predicate condition_holds(integer a, integer b, integer c) = 
      (a + b) >= c; */

/*@
  requires 1 <= a && a <= 500;
  requires 1 <= b && b <= 500;
  requires 1 <= c && c <= 1000;
  ensures \result <==> condition_holds(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    bool result;
    
    sum = a + b;
    
    if (sum < c) {
        //@ assert sum < c;
        result = false;
    } else {
        //@ assert sum >= c;
        result = true;
    }
    
    return result;
}
