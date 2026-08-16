#include <stdbool.h>

/*@ predicate is_triangle_sum(integer a, integer b, integer c) =
      a + b == c || b + c == a || c + a == b;
*/

/*@ requires \valid(x + (0..2));
    requires x[0] >= 1 && x[1] >= 1 && x[2] >= 1;
    requires x[0] <= 100 && x[1] <= 100 && x[2] <= 100;
    ensures \result == true <==> is_triangle_sum(x[0], x[1], x[2]);
*/
bool func(unsigned int* x) {
    //@ assert x[0] >= 1 && x[0] <= 100;
    //@ assert x[1] >= 1 && x[1] <= 100;
    //@ assert x[2] >= 1 && x[2] <= 100;
    return (x[0] + x[1] == x[2] || x[1] + x[2] == x[0] || x[2] + x[0] == x[1]);
}
