#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (3142)* (r)) / (1000));
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t scale;
    int64_t ans;
    int64_t temp;
    
    pi_approx = 3142;
    scale = 1000;
    ans = 0;
    temp = 2 * r * pi_approx;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant scale == 1000;
        loop invariant temp >= 0;
        loop invariant ans >= 0;
        loop invariant temp == 2 * r * pi_approx - ans * scale;
        loop assigns ans, temp;
    */
    while (temp >= scale)
    {
        //@ assert temp == 2 * r * pi_approx - ans * scale;
        
        ans += 1;
        temp -= scale;
        
        //@ assert temp == 2 * r * pi_approx - ans * scale;
    }
    
    //@ assert ans * scale + temp == 2 * pi_approx * r;
    //@ assert ans * 1000 + temp == 2 * 3142 * r;
    
    return ans;
}

int main()
{
    return 0;
}
