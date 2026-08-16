#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        \valid((numbers) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (numbers)[j] <= 100);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *numbers)
{
    int ans = 1;
    int sum = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (sum) >= 0 &&
        (sum) <= (i) * 100 &&
        (ans) >= 1 &&
        (ans) <= (i) + 1);
        loop assigns i, sum, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        int num = numbers[i];
        sum += num;
        
        //@ assert sum >= 0;
        
        if (sum > x)
        {
            //@ assert ans >= 1;
            return ans;
        }
        
        ans += 1;
        i += 1;
        
        //@ assert ans <= i + 1;
    }
    
    //@ assert ans <= n + 1;
    return ans;
}
