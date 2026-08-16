#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result >= 0;
    ensures \result <= 314159;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;
    
    //@ assert (1 <= (r) <= 100);
    
    pi_approx = 3;
    circumference = 2 * pi_approx * r;
    
    //@ assert circumference == (2 * (3)* (r));
    //@ assert circumference >= 0;
    
    return circumference;
}

#ifdef TEST
#include <assert.h>

int main(void)
{
    int64_t result;
    
    result = func(1);
    assert(result == 6);
    
    return 0;
}
#endif
