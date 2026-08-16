#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer x, long *numbers) =
    n >= 2 && n <= 50 &&
    x >= 0 && x <= 50 &&
    \valid(numbers + (0 .. n-1)) &&
    \forall integer k; 0 <= k < n ==> numbers[k] >= 0 && numbers[k] <= 50;
*/

/*@ lemma ans_non_negative:
    \forall integer n, x, ans, i;
    valid_params(n, x, (long *)0) &&
    0 <= i <= n &&
    0 <= ans <= i ==>
    ans >= 0;
*/

/*@
    requires valid_params(n, x, numbers);
    ensures \result >= 0;
    assigns \nothing;
*/
long func(long n, long x, long *numbers) {
    long ans = 0;
    long i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        long num = numbers[i];
        
        //@ assert 0 <= num <= 50;
        
        if (x >= num) {
            ans = ans + 1;
        }
        
        i = i + 1;
        
        //@ assert 0 <= ans <= i;
    }
    
    //@ assert ans >= 0;
    return ans;
}
