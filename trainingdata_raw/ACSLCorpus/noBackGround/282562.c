#include <stddef.h>
#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int func(size_t n)
{
    int x = 800;
    int y = 200;
    int ans = 0;
    size_t temp_n = n;
    size_t count = 0;

    //@ assert (1 <= (n) <= 100);
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant ans == (((n) - (temp_n)) * 800);
        loop invariant (1 <= (n) <= 100);
        loop assigns ans, temp_n;
        loop variant temp_n;
    */
    while (temp_n > 0)
    {
        //@ assert temp_n > 0;
        ans += x;
        temp_n -= 1;
        //@ assert ans == (((n) - (temp_n)) * 800);
    }

    //@ assert temp_n == 0;
    //@ assert ans == n * 800;

    /*@
        loop invariant 0 <= count <= n / 15;
        loop invariant ans == (((((n)) - ((temp_n))) * 800) - (count) * 200);
        loop invariant (1 <= (n) <= 100);
        loop assigns ans, count;
        loop variant n / 15 - count;
    */
    while (count < n / 15)
    {
        //@ assert count < n / 15;
        ans -= y;
        count += 1;
        //@ assert ans == (((((n)) - ((temp_n))) * 800) - (count) * 200);
    }

    //@ assert count == n / 15;
    //@ assert ans == ((n) * 800 - ((n) / 15) * 200);
    //@ assert ans == n * 800 - (n / 15) * 200;

    return ans;
}
