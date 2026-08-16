#include <limits.h>

/*@
  requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
  requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
  ensures \result == 1 <==> (((c) > (a) && (c) < (b)) || ((c) > (b) && (c) < (a)));
  assigns \nothing;
*/
int func(int a, int b, int c) {
    // Variable declarations at scope top
    int result;

    //@ assert a < INT_MAX;
    //@ assert b < INT_MAX;
    //@ assert c < INT_MAX;
    //@ assert a > INT_MIN;
    //@ assert b > INT_MIN;
    //@ assert c > INT_MIN;

    if ((c > a && c < b) || (c < a && c > b)) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}
