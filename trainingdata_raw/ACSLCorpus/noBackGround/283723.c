#include <stdbool.h>

/*@
    requires ((a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123 && (k) <= 123 &&
    (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k) {
    unsigned int diff;
    
    //@ assert a <= 123 && e <= 123;
    //@ assert a >= 0 && e >= 0;
    
    if (e > a) {
        diff = e - a;
    } else {
        diff = a - e;
    }
    
    //@ assert diff <= 123;
    //@ assert diff == e - a;
    
    return diff <= k;
}
