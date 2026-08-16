#include <stdbool.h>
/*@
    requires 1 <= n <= 20;
    requires \valid(a + (0..n-1));
    requires \valid(b + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 50);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] <= 50);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *a, int *b) {
    int res = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (res) >= 0 && (res) <= (i) &&
        (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 50) && (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((b))[i] <= 50) &&
        1 <= (n) <= 20);
        loop invariant i <= n;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] == b[i]) {
            //@ assert a[i] == b[i];
            res = res + 1;
        }
        i = i + 1;
    }
    //@ assert i == n;
    //@ assert res >= 0 && res <= n;
    return res;
}
