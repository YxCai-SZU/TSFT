#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
    ensures \result >= 0 && \result <= n;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ((count) >= 0 && (count) <= (i));
        loop invariant ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == 1 || a[k] == 2 || a[k] == 3);
        loop assigns count, i;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        
        if (value == 2) {
            count += 1;
        } else if (value == 1 && i != 0) {
            if (count > 0) {
                count -= 1;
            } else {
                count += 1;
            }
        } else if (value == 3 && i != 0) {
            if (count > 0) {
                count -= 1;
            }
        }
        
        //@ assert ((count) >= 0 && (count) <= (i+1));
        i += 1;
    }
    
    //@ assert ((count) >= 0 && (count) <= (n));
    return count;
}
