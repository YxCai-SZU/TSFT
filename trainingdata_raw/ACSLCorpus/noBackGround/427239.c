#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at scope top
    unsigned long long c;
    bool is_even;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert ((a) * (b)) <= 10000;
    
    c = a * b;
    
    //@ assert c == ((a) * (b));
    
    switch (c % 2)
    {
        case 0:
            is_even = true;
            break;
        case 1:
            is_even = false;
            break;
        default:
            is_even = false;
            break;
    }
    
    //@ assert is_even == (((a) * (b)) % 2 == 0);
    
    return is_even;
}
