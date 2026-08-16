#include <stdbool.h>
#include <stddef.h>

/*@
    requires (0 < (n) <= 200);
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, const int *numbers) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (0 <= (ans) <= (i) <= (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop invariant (\forall integer k; 0 <= k < (i) ==> ((numbers)[k] & 1) == 1 ==> (ans) > 0);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        
        //@ assert (1 <= (a) <= 1000000000);
        
        if ((a & 1) == 1) {
            ans = ans + 1;
        }
        
        //@ assert (\forall integer k; 0 <= k < (i + 1) ==> ((numbers)[k] & 1) == 1 ==> (ans) > 0);
        i = i + 1;
    }
    
    //@ assert (0 <= (ans) <= ((n)) <= (n));
    return ans;
}
