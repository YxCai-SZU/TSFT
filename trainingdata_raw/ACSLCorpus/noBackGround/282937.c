#include <limits.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
*/
long func(long a, long b) {
    long sum;
    long diff;
    long prod;
    long max_val;

    sum = a + b;
    diff = a - b;

    //@ assert (-100 <= (a) && (a) <= 100);
    //@ assert (-100 <= (b) && (b) <= 100);
    //@ assert -10000 <= a * b && a * b <= 10000;

    prod = a * b;

    max_val = sum;
    if (diff > max_val) {
        max_val = diff;
    }
    if (prod > max_val) {
        max_val = prod;
    }

    return max_val;
}
