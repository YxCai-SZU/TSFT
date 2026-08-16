#include <stdbool.h>

/*@ requires 1 <= n <= 100;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 100));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *a) {
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 100));
        loop invariant \forall integer k; 0 <= k < i ==> (1 <= (a[k]) <= 100);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) < (n));
        if (a[i] >= 1 && a[i] <= 100) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
