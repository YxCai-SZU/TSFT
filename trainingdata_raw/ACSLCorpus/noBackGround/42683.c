#include <stdbool.h>

/*@
    requires (1000 <= (a) <= 9999);
    ensures \result == ((a / 100) % 10 == a % 10);
*/
bool func(unsigned int a)
{
    unsigned int b;
    unsigned int c;
    unsigned int d;
    bool result;

    b = a / 100;
    //@ assert b == a / 100;
    
    c = b % 10;
    //@ assert c == b % 10;
    
    d = a % 10;
    //@ assert d == a % 10;
    
    result = (c == d);
    return result;
}
