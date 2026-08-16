#include <stdbool.h>

/*@
  requires \valid_read(v + (0 .. 1));
  requires ((2) == 2);
  requires (\forall integer i; 0 <= i < (2) ==> (0 <= ((v)[i]) <= 100));
  ensures \result == (v[0] <= v[1]);
*/
bool func(unsigned int *v) {
    unsigned int a;
    unsigned int b;
    
    //@ assert ((2) == 2);
    
    a = v[0];
    b = v[1];
    
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    
    if (a <= b) {
        return true;
    } else {
        return false;
    }
}
