#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (((n) + 999) / 1000);
    assigns \nothing;
*/
int func(int n)
{
    int ans = 0;
    int temp_n = n + 999;
    int count = 0;
    
    //@ assert temp_n == n + 999 - 1000 * count;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n + 999 - 1000 * count;
        loop invariant count >= 0;
        loop invariant count <= (((n) + 999) / 1000);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        //@ assert temp_n >= 1000;
        temp_n -= 1000;
        count += 1;
        //@ assert temp_n == n + 999 - 1000 * count;
    }
    
    ans = count;
    //@ assert ans == (((n) + 999) / 1000);
    return ans;
}
