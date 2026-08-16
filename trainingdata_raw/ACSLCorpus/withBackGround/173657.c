#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n > 0 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, integer n, integer num, integer count) =
      0 <= num <= n &&
      0 <= count <= num &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ lemma array_property_preserved:
      \forall int *a, integer n;
      valid_array(a, n) ==>
      \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 100;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *a) {
    // Variable declarations at scope top
    int count = 0;
    size_t num = 0;
    
    // Precondition verification
    //@ assert n > 0 && n <= 100;
    //@ assert \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
    
    /*@ loop invariant 0 <= num <= n;
        loop invariant 0 <= count <= num;
        loop invariant \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
        loop assigns count, num;
        loop variant n - num;
    */
    while (num < (size_t)n) {
        //@ assert 0 <= num <= n;
        //@ assert 0 <= count <= num;
        //@ assert \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
        
        if (num + 1 < (size_t)n && a[num] == (int)num + 1) {
            count += 1;
        }
        num += 1;
        
        // Critical verification property
        //@ assert \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
    }
    
    // Postcondition verification
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
