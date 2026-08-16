#include <stdbool.h>

/*@ predicate is_triangle(integer a, integer b, integer c) =
      a + b == c || a + c == b || b + c == a;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> is_triangle(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int max;
    bool result;

    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    result = false;
    if (max == a) {
        result = (b + c == max);
    } else if (max == b) {
        result = (a + c == max);
    } else {
        result = (a + b == max);
    }

    return result;
}
