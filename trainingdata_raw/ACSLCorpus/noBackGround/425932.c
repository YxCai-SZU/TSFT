#include <stdbool.h>
#include <stddef.h>

/*@ requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
    requires \valid(a + (0 .. n-1));
    requires ((n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (int)(n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    assigns \nothing;
    ensures 0 <= \result <= (int)n;
*/
int func(size_t n, size_t k, const int *a) {
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= l <= i;
        loop invariant 0 <= r < n;
        loop invariant ((n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (int)(n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
        loop invariant (2 <= (k) && (k) <= (n) && (n) <= 100000);
        loop invariant i == 0 ==> l == 0 && r == 0;
        loop assigns i, l, r;
        loop variant n - i;
    */
    while (i < n) {
        if (a[i] == 1) {
            l = i;
            r = n - i - 1;
            break;
        }
        i++;
    }
    
    size_t d = l > r ? l : r;
    int ans = d < k ? 0 : (int)(d - k + 1);
    
    //@ assert ans <= (int)n;
    
    return ans;
}
