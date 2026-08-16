#include <limits.h>

/*@
    requires (0 <= (x) <= 100) && (0 <= (y) <= 100);
    ensures \result == x + y || \result == x - y || \result == x * y;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int x, int y) {
    int sum;
    int diff;
    int prod;
    int max1;
    int result;

    //@ assert 0 <= x * y <= 10000;
    sum = x + y;
    diff = x - y;
    prod = x * y;

    if (sum > diff) {
        max1 = sum;
    } else {
        max1 = diff;
    }

    if (max1 > prod) {
        result = max1;
    } else {
        result = prod;
    }

    //@ assert result == x + y || result == x - y || result == x * y;
    //@ assert result >= 0;
    return result;
}
