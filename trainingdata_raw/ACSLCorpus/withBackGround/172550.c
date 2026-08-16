#include <limits.h>

/*@ predicate is_valid_param(integer v) = 1 <= v <= 1000; */

/*@
  requires is_valid_param(a) && is_valid_param(b) && 
           is_valid_param(c) && is_valid_param(d);
  ensures \result == a + c || \result == a + d || 
          \result == b + c || \result == b + d;
  ensures \result >= 2;
*/
int func(int a, int b, int c, int d) {
    int min_ab;
    int min_cd;
    int result;
    
    //@ assert is_valid_param(a) && is_valid_param(b);
    //@ assert is_valid_param(c) && is_valid_param(d);
    
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    
    //@ assert min_ab == a || min_ab == b;
    
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    
    //@ assert min_cd == c || min_cd == d;
    
    result = min_ab + min_cd;
    
    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    //@ assert result >= 2;
    
    return result;
}
