#include <stdbool.h>

/*@ requires 2 <= n <= 1000000;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 5));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int ans = 0;
    int i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 5));
        loop invariant 2 <= n <= 1000000;
        loop assigns i, ans;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value == 1 || value == 2 || value == 5;
        if (value == 1) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
