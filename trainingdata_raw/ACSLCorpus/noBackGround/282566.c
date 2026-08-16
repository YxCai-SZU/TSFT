#include <stdbool.h>

/*@
  requires 0 <= a <= 1000000000000000000;
  requires 0 <= b <= 1000000000000000000;
  requires 0 <= x <= 1000000000000000000;
  ensures \result <==> ((a) <= (x) && (a) + (b) >= (x));
*/
bool is_possible_x_cats(long long a, long long b, long long x) {
    //@ assert 0 <= a <= 1000000000000000000;
    //@ assert 0 <= b <= 1000000000000000000;
    //@ assert 0 <= x <= 1000000000000000000;
    //@ assert a <= x && a + b >= x <==> (a <= x && a + b >= x);
    return a <= x && a + b >= x;
}
