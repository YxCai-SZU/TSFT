#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x && x <= 100; */

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == a + b || \result == b + c || \result == c + a;
    ensures \result >= 0;
*/
int func(int a, int b, int c) {
    int min_ab;
    int min_bc;
    int min_ca;
    int min;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    min_ab = a + b;
    min_bc = b + c;
    min_ca = c + a;
    min = min_ab;

    if (min_bc < min) {
        min = min_bc;
    }
    if (min_ca < min) {
        min = min_ca;
    }

    //@ assert min == a + b || min == b + c || min == c + a;
    return min;
}
