#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000000 &&
        1 <= (k) <= 1000000000000);
    ensures ((\result) >= 0 && (\result) <= (n));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t result;
    
    //@ assert (1 <= (n) <= 1000000000000 &&         1 <= (k) <= 1000000000000);
    
    if (n - 2 * k > 0)
    {
        //@ assert n - 2 * k >= 0;
        result = n - 2 * k;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert ((result) >= 0 && (result) <= (n));
    return result;
}

int main()
{
    return 0;
}
