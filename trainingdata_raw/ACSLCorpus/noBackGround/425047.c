#include <stdbool.h>
#include <stdint.h>

/*@
    requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires \valid(h + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
unsigned int func(unsigned int n, unsigned int k, int *h) {
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> h[j] >= 1 && h[j] <= 500;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
    \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
        loop invariant ((k) >= 1 && (k) <= 500);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (h[i] >= (int)k) {
            //@ assert h[i] >= (int)k;
            count++;
        }
        i++;
    }
    
    //@ assert count <= n;
    return count;
}
