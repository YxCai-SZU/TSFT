#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B && \result >= A - B && \result >= A * B;
*/
int func(int A, int B) {
    int sum;
    int diff;
    int prod;
    int max_val;

    sum = A + B;
    diff = A - B;

    //@ assert A * B >= -10000 && A * B <= 10000;
    prod = A * B;

    //@ assert -100 <= A <= 100;
    //@ assert -100 <= B <= 100;

    max_val = sum;
    if (diff > max_val) {
        max_val = diff;
    }
    if (prod > max_val) {
        max_val = prod;
    }

    return max_val;
}
