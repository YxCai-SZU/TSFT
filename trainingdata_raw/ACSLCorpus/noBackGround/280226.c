#include <stddef.h>
#include <limits.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    ensures \result >= 0;
*/
int func(size_t n, int* a) {
    int ans = INT_MAX;
    size_t i = 0;
    
    //@ assert ans >= 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
        loop invariant n > 0 && n <= 100;
        loop invariant ans <= INT_MAX;
        loop invariant ((i) > 0 ==> \forall size_t k; 0 <= k < (i) ==> 
        (((a)[k] >> 31) == 0 ==> (a)[k] >= 0) && 
        (((a)[k] >> 31) != 0 ==> (a)[k] + 1 >= 0));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        //@ assert a[i] >= 1 && a[i] <= 100;
        
        int tmp = (a[i] >> 31) == 0 ? a[i] : a[i] + 1;
        int sum = 0;
        size_t j = 0;
        
        //@ assert tmp >= 0;
        
        /*@ loop invariant 0 <= j <= 32;
            loop invariant sum >= 0;
            loop invariant ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
            loop invariant n > 0 && n <= 100;
            loop invariant sum <= (int)j;
            loop invariant ((i) > 0 ==> \forall size_t k; 0 <= k < (i) ==> 
        (((a)[k] >> 31) == 0 ==> (a)[k] >= 0) && 
        (((a)[k] >> 31) != 0 ==> (a)[k] + 1 >= 0));
            loop invariant tmp >= 0;
            loop assigns j, sum;
            loop variant 32 - j;
        */
        while (j < 32) {
            int bit = (tmp >> j) & 1;
            if (bit == 1) {
                sum += 1;
            }
            j += 1;
        }
        
        ans = ans < sum ? ans : sum;
        i += 1;
    }
    
    return ans;
}
