#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
    requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (n));
    ensures (\forall integer i; 0 <= i < (n) ==> 
        ((h)[i] >= (k) ==> (\result) > 0) &&
        ((h)[i] < (k) ==> (\result) >= 0));
*/
long func(long n, long k, int *h) {
    long count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= (size_t)n;
        loop invariant count >= 0;
        loop invariant count <= (long)i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (h[j] >= k ==> count > 0) &&
            (h[j] < k ==> count >= 0);
        loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
        loop invariant \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 500;
        loop assigns count, i;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        //@ assert 0 <= i < (size_t)n;
        //@ assert h[i] >= 1 && h[i] <= 500;
        
        if (h[i] >= k) {
            //@ assert h[i] >= k;
            count += 1;
            //@ assert count > 0;
        } else {
            //@ assert h[i] < k;
            //@ assert count >= 0;
        }
        
        i += 1;
        //@ assert count <= (long)i;
    }
    
    //@ assert i == (size_t)n;
    //@ assert ((count) >= 0 && (count) <= (n));
    //@ assert (\forall integer i; 0 <= i < (n) ==>          ((h)[i] >= (k) ==> (count) > 0) &&         ((h)[i] < (k) ==> (count) >= 0));
    return count;
}
