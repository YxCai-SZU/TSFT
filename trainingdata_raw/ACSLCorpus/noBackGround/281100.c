#include <stdbool.h>

/*@
    requires \valid(a + (0..2)) && \valid(b + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (a)[i] <= 10000) && ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (b)[i] <= 10000);
    ensures \result == (a[0] < b[2] && b[0] < a[2]);
*/
bool func(int *a, int *b) {
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a[0] <= 10000;
    //@ assert 1 <= a[1] <= 10000;
    //@ assert 1 <= a[2] <= 10000;
    //@ assert 1 <= b[0] <= 10000;
    //@ assert 1 <= b[1] <= 10000;
    //@ assert 1 <= b[2] <= 10000;

    result = (a[0] < b[2] && b[0] < a[2]);
    return result;
}
