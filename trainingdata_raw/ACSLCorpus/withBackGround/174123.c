#include <stdbool.h>

/*@
    predicate is_valid_array(long *a, long n) =
        n >= 1 && n <= 200000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> a[j] >= 1 && a[j] <= 1000000000;

    logic integer array_length(long *a, long n) = n;

    lemma loop_invariant_maintains:
        \forall long *a, long n, long i, long count;
        is_valid_array(a, n) &&
        0 <= i <= n &&
        0 <= count <= i ==>
        \forall integer j; 0 <= j < n ==> a[j] >= 1 && a[j] <= 1000000000;
*/

/*@
    requires is_valid_array(a, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
long func(long n, long *a) {
    long count = 0;
    long num = 0;
    long i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant is_valid_array(a, n);
        loop assigns i, count, num;
        loop variant n - i;
    */
    while (i < n) {
        long ai = a[i];
        
        //@ assert ai >= 1 && ai <= 1000000000;
        
        if (num == ai) {
            count = count + 1;
            num = 0;
        } else {
            num = ai;
        }
        i = i + 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
