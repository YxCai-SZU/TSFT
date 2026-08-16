#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 3 && n <= 20;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 3 && (n) <= 20 &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (n));
*/
size_t func(size_t n, int *a) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant ((n) >= 3 && (n) <= 20 &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = true;
        size_t j = 1;
        
        /*@ loop invariant 1 <= j <= n;
            loop invariant is_divisible == true || is_divisible == false;
            loop invariant ((n) >= 3 && (n) <= 20 &&
      \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                //@ assert ((n) >= 3 && (n) <= 20 &&       \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
                if (a[i] % a[j] == 0) {
                    is_divisible = false;
                    break;
                }
            }
            j++;
        }
        
        if (is_divisible) {
            ans++;
        }
        i++;
    }
    
    //@ assert ((ans) >= 0 && (ans) <= (n));
    return ans;
}
