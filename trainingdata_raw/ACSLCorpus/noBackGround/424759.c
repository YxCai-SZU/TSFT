#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        0 <= (ans) && (ans) <= (int)(i) &&
        (((n)) > 0 && ((n)) <= 100 &&
        \valid(((a)) + (0 .. ((n))-1)) &&
        \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= 100) &&
        \forall size_t k; 0 <= k < (i) ==> 
            ((a)[k] % 2 == 0 ==> (ans) == (ans)) && 
            ((a)[k] % 2 != 0 ==> (ans) >= 0 && (ans) <= (int)(i)));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int index = a[i];
        int value = (index % 2 == 0) ? 0 : 1;
        
        //@ assert value == 0 || value == 1;
        
        if (value == 0) {
            ans = ans;
        } else {
            ans = ans + 1;
        }
        
        //@ assert 0 <= ans && ans <= (int)(i + 1);
        
        i = i + 1;
    }
    
    //@ assert ans >= 0 && ans <= (int)n;
    return ans;
}
