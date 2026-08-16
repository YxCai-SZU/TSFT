#include <limits.h>

/*@
    requires \valid(a + (0..2)) && \valid(b + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (a)[i] >= 1 && (a)[i] <= 20);
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (b)[i] >= 1 && (b)[i] <= 20);
    ensures \result >= 0;
    ensures \result == ((a)[(0)] * (b)[(0)]) ||
            \result == ((a)[(1)] * (b)[(1)]) ||
            \result == ((a)[(2)] * (b)[(2)]);
*/
int func(int* a, int* b) {
    int answer = INT_MIN;
    int product1;
    int product2;
    int product3;

    //@ assert a[0] >= 1 && a[0] <= 20;
    //@ assert b[0] >= 1 && b[0] <= 20;
    //@ assert a[0] * b[0] <= 400;
    product1 = a[0] * b[0];

    //@ assert a[1] >= 1 && a[1] <= 20;
    //@ assert b[1] >= 1 && b[1] <= 20;
    //@ assert a[1] * b[1] <= 400;
    product2 = a[1] * b[1];

    //@ assert a[2] >= 1 && a[2] <= 20;
    //@ assert b[2] >= 1 && b[2] <= 20;
    //@ assert a[2] * b[2] <= 400;
    product3 = a[2] * b[2];

    if (product1 >= answer) {
        answer = product1;
    }
    if (product2 >= answer) {
        answer = product2;
    }
    if (product3 >= answer) {
        answer = product3;
    }
    return answer;
}
