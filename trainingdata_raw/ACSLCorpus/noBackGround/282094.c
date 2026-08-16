#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (k) && (k) <= 500);
    requires (\valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (n) &&
        (\forall integer i; 0 <= i < (n) && (h)[i] >= (k) ==> (\result) >= 1) &&
        (\forall integer i; 0 <= i < (n) && (h)[i] < (k) ==> (\result) >= 0));
*/
long func(long n, long k, int *h) {
    long count = 0;
    unsigned long index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> 
            (\forall integer i; 0 <= i < index && h[i] >= k ==> count >= 1);
        loop invariant index > 0 ==> 
            (\forall integer i; 0 <= i < index && h[i] < k ==> count >= 0);
        loop invariant (1 <= (n) && (n) <= 100000 &&
        1 <= (k) && (k) <= 500);
        loop invariant (\valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < (unsigned long)n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}
