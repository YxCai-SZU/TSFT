#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((1 <= (n) && (n) <= 100) &&
    (1 <= (x) && (x) <= 10000) &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (1 <= (numbers)[j] && (numbers)[j] <= 100));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n + 1;
*/
long func(long n, long x, long *numbers) {
    long ans = 1;
    long sum = 0;
    long i = 0;
    
    /*@
        loop invariant ((0 <= (i) && (i) <= (n)) &&
    (1 <= (n) && (n) <= 100) &&
    (1 <= (x) && (x) <= 10000) &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (1 <= (numbers)[j] && (numbers)[j] <= 100) &&
    ((sum) >= 0) &&
    ((sum) <= (i) * 100) &&
    ((ans) >= 1) &&
    ((ans) <= (i) + 1));
        loop assigns i, sum, ans;
        loop variant n - i;
    */
    while (i < n) {
        long num = numbers[i];
        sum += num;
        
        //@ assert sum >= 0 && sum <= (i + 1) * 100;
        
        if (sum <= x) {
            ans += 1;
        }
        
        //@ assert ans >= 1 && ans <= i + 2;
        
        i += 1;
    }
    
    //@ assert ans >= 0 && ans <= n + 1;
    
    return ans;
}
