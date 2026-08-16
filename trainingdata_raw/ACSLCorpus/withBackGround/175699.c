#include <limits.h>

/*@
    predicate in_range(integer v) = INT_MIN <= v <= INT_MAX - 4;

    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a >= b && a >= c && a >= d) ? a :
        (b >= a && b >= c && b >= d) ? b :
        (c >= a && c >= b && c >= d) ? c : d;

    lemma max_is_last:
        \forall integer x; in_range(x) ==> max_of_four(x, x+1, x+2, x+3) == x+3;
    lemma max_is_fourth:
        \forall integer x; in_range(x) ==> max_of_four(x, x+1, x+2, x+4) == x+4;
*/

/*@
    requires INT_MIN <= x <= INT_MAX - 4;
    ensures \result == x + 4;
    assigns \nothing;
*/
int func(int x)
{
    int max_val;

    //@ assert in_range(x);
    
    if (x < x + 1) {
        if (x + 1 < x + 2) {
            if (x + 2 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 2 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 2;
                }
            }
        } else {
            if (x + 1 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 1 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 1;
                }
            }
        }
    } else {
        if (x < x + 2) {
            if (x + 2 < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x + 2 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 2;
                }
            }
        } else {
            if (x < x + 3) {
                if (x + 3 < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x + 3;
                }
            } else {
                if (x < x + 4) {
                    max_val = x + 4;
                } else {
                    max_val = x;
                }
            }
        }
    }

    //@ assert max_val == x + 4;
    return max_val;
}
