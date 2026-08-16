#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (0 <= (x) && (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    
    result = x * x;
    
    //@ assert result == ((x) * (x));
    return result;
}

int main()
{
    return 0;
}
