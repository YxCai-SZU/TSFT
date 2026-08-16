#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *a) {
    int count = 0;
    int index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
      (count) >= 0 && (count) <= (index) &&
      ((index) > 0 ==> \forall integer k; 0 <= k < (index) && k % 2 == 0 && ((a)[k] & 1) == 1 ==> (count) > 0));
        loop invariant ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int ai = a[index];
        
        //@ assert index % 2 == 0 ==> (ai & 1) == 1 ==> count >= 0;
        
        if (index % 2 == 0 && (ai & 1) == 1) {
            count += 1;
        }
        
        //@ assert count <= index + 1;
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
