/*@
    requires (1 <= (n) <= 10000);
    ensures \result == ((((n)) / 2) + (((n)) % 2));
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int half;
    unsigned int rem;
    unsigned int result;
    
    half = n / 2;
    rem = n % 2;
    
    //@ assert half == n / 2;
    //@ assert rem == n % 2;
    
    result = half + rem;
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(10) == 6);
    assert(func(11) == 6);
    return 0;
}
#endif
