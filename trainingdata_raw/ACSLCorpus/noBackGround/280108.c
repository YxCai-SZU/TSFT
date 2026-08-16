#include <stdint.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == x * 800 - (x / 15) * 200;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t tax = 800;
    int64_t reduction = 200;
    int64_t n = 0;
    int64_t temp_x = x;
    
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 0 <= n <= x / 15;
        loop invariant temp_x == x - n * 15;
        loop invariant temp_x >= 0;
        loop assigns n, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 15)
    {
        temp_x -= 15;
        n += 1;
    }
    
    //@ assert x * 800 <= 100 * 800;
    //@ assert n * 200 <= 100 * 200;
    //@ assert x * 800 >= n * 200;
    
    int64_t ans = x * tax - n * reduction;
    return ans;
}

int main()
{
    return 0;
}
