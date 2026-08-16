#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t result;
    
    pi = 3;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert pi == 3;
    
    //@ assert 2 * 3 * 1 <= 2 * pi * r;
    //@ assert 2 * pi * r <= 2 * 3 * 100;
    
    result = 2 * pi * r;
    
    //@ assert result == (6 * (r));
    
    return result;
}

int main()
{
    return 0;
}
