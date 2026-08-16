#include <limits.h>
#include <stdbool.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0..n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int *a, int n) {
    int min = INT_MAX;
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant min == INT_MAX || \exists integer j; 0 <= j < i && min == a[j];
        loop assigns i, min, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] < min) {
            //@ assert min == INT_MAX || a[i] < min;
            count += 1;
            min = a[i];
        }
        i += 1;
    }
    //@ assert count <= n;
    return count;
}
