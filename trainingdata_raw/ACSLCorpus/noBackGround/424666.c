#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int res;

    //@ assert -1000 <= a <= 1000;
    //@ assert -1000 <= b <= 1000;
    //@ assert -1000000 <= a * b <= 1000000;

    sum = a + b;
    diff = a - b;
    prod = a * b;

    //@ assert sum >= a + b;
    //@ assert diff >= a - b;
    //@ assert prod >= a * b;

    if (sum >= diff && sum >= prod) {
        res = sum;
    } else if (diff >= sum && diff >= prod) {
        res = diff;
    } else {
        res = prod;
    }

    return res;
}
