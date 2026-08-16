#include <stddef.h>

/*@
    requires ((n) > 0 && (k) > 0 && (len) == (n));
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t k, int *h, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    //@ assert ((n) > 0 && (k) > 0 && (len) == (n));
    //@ assert (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
    
    /*@
        loop invariant (0 <= (i) <= (n) && 0 <= (count) <= (i) && (count) <= (n));
        loop invariant (\forall integer j; 0 <= j < (i) && (h)[j] >= (k) ==> (count) > 0);
        loop invariant (\forall integer j; 0 <= j < (i) && (h)[j] < (k) ==> (count) <= (i));
        loop invariant ((n) > 0 && (k) > 0 && (len) == (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) <= (n) && 0 <= (count) <= (i) && (count) <= (n));
        //@ assert (\forall integer j; 0 <= j < (i) && (h)[j] >= (k) ==> (count) > 0);
        //@ assert (\forall integer j; 0 <= j < (i) && (h)[j] < (k) ==> (count) <= (i));
        
        if (h[i] >= (int)k) {
            //@ assert h[i] >= (int)k;
            count++;
            //@ assert count > 0;
        } else {
            //@ assert h[i] < (int)k;
        }
        
        i++;
        
        //@ assert (0 <= (i) <= (n) && 0 <= (count) <= (i) && (count) <= (n));
        //@ assert (\forall integer j; 0 <= j < (i) && (h)[j] >= (k) ==> (count) > 0);
        //@ assert (\forall integer j; 0 <= j < (i) && (h)[j] < (k) ==> (count) <= (i));
    }
    
    //@ assert i == n;
    //@ assert (0 <= (i) <= (n) && 0 <= (count) <= (i) && (count) <= (n));
    //@ assert 0 <= count <= n;
    
    return count;
}
