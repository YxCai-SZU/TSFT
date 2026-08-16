#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires (1 <= (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
    ensures \result >= 0;
*/
int64_t func(int64_t n, int64_t x, int64_t *numbers)
{
    int64_t ans = 0;
    int64_t sum = 0;
    int64_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= sum <= i * 100;
        loop invariant 0 <= ans <= i;
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= x <= 10000;
        loop invariant (1 <= (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] <= 100);
        loop assigns i, sum, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        int64_t a = numbers[i];
        sum += a;
        
        //@ assert 1 <= a <= 100;
        
        if (sum <= x)
        {
            ans += 1;
        }
        i += 1;
        
        //@ assert i <= n;
    }
    
    //@ assert ans >= 0;
    return ans;
}
