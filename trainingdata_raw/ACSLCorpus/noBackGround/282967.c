#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(v + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 0 <= (v)[i] && (v)[i] <= 1000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *v) {
    int high = 0;
    int low = 0;
    int i = 0;

    /*@ loop invariant (0 <= (i) <= (n) &&
      0 <= (low) <= (i) &&
      0 <= (high) <= 1000 &&
      \forall integer j; 0 <= j < (i) ==> (v)[j] <= (high));
        loop invariant v == \at(v, Pre);
        loop invariant n == \at(n, Pre);
        loop assigns i, high, low;
        loop variant n - i;
    */
    while (i < n) {
        int value = v[i];

        //@ assert 0 <= value && value <= 1000;
        if (value < high) {
            low = low + 1;
        } else {
            high = value;
        }
        i = i + 1;
    }

    //@ assert low >= 0;
    //@ assert low <= n;
    return low;
}
