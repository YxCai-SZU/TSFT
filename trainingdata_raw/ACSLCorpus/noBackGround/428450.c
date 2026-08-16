#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(x + (0 .. 4));
    requires (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures \result >= 1 && \result <= 5 || \result == -1;
    ensures \result != -1 ==> \exists integer i; 0 <= i < 5 && x[i] == \result;
*/
int func(int* x) {
    int ans = -1;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant ((ans) >= -1 && (ans) <= 5 &&
      ((ans) != -1 ==> \exists integer i; 0 <= i < (5) && (x)[i] == (ans)));
        loop invariant (\forall integer k; 0 <= k < (i) ==> (x)[k] != 0);
        loop assigns ans, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            ans = (int)(i + 1);
            break;
        }
        i++;
    }
    return ans;
}
