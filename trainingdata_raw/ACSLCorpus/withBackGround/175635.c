#include <limits.h>

/*@ predicate is_min(integer ret, integer a, integer b, integer c) =
      ret <= a && ret <= b && ret <= c &&
      (ret == a || ret == b || ret == c);
*/

/*@
  requires INT_MIN <= a <= INT_MAX;
  requires INT_MIN <= b <= INT_MAX;
  requires INT_MIN <= c <= INT_MAX;
  ensures \result <= a && \result <= b && \result <= c;
  ensures \result == a || \result == b || \result == c;
  ensures is_min(\result, a, b, c);
*/
int min_of_three(int a, int b, int c) {
    int ret;
    
    if (a <= b && a <= c) {
        ret = a;
        //@ assert ret <= a && ret <= b && ret <= c;
    } else if (b <= a && b <= c) {
        ret = b;
        //@ assert ret <= a && ret <= b && ret <= c;
    } else {
        ret = c;
        //@ assert ret <= a && ret <= b && ret <= c;
    }
    
    //@ assert ret == a || ret == b || ret == c;
    return ret;
}
