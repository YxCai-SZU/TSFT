#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123 &&
        (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
    requires 0 <= k <= 123;
    ensures \result == (k >= v[4] - v[0]);
*/
bool func(int *v, int k)
{
    //@ assert ((5) == 5 &&         \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123 &&         (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
    //@ assert 0 <= k <= 123;
    //@ assert ((v)[4] - (v)[0]) >= 0;
    return k >= v[4] - v[0];
}
