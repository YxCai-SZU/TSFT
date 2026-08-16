#include <stdbool.h>

/*@ predicate is_max(integer max, integer a, integer b, integer c) =
      max == a || max == b || max == c;
*/
/*@ predicate is_min(integer min, integer a, integer b, integer c) =
      min == a || min == b || min == c;
*/

/*@
  requires 1 <= a <= 500;
  requires 1 <= b <= 500;
  requires 1 <= c <= 1000;
  ensures \result == ((a + b) >= c);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long max;
    unsigned long long min;

    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    //@ assert is_max(max, a, b, c);
    //@ assert is_min(min, a, b, c);

    return (a + b) >= c;
}
