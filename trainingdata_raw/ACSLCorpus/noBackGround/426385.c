#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long c;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= ((a) * (b)) <= 100000000;
    
    c = a * b;
    
    //@ assert c == ((a) * (b));
    //@ assert c % 2 == ((a) * (b)) % 2;
    
    return c % 2 != 0;
}
