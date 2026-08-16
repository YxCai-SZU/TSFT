#include <stdbool.h>

/*@
  requires 0 <= a && a <= 100;
  requires 0 <= b && b <= 100;
  requires 0 <= c && c <= 100;
  requires 0 <= d && d <= 100;
  ensures \result == ((a > b ? b : a) <= (c > d ? d : c));
  assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    unsigned long min_ab;
    unsigned long min_cd;
    bool result;

    /*@ assert (((a) > (b)) ? ((a > b ? b : a) == (b)) : ((a > b ? b : a) == (a))); */
    min_ab = (a > b) ? b : a;

    /*@ assert (((c) > (d)) ? ((c > d ? d : c) == (d)) : ((c > d ? d : c) == (c))); */
    min_cd = (c > d) ? d : c;

    result = (min_ab <= min_cd);
    return result;
}
