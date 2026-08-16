#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
*/
int64_t func(int64_t a)
{
    int64_t result;
    int64_t a_pow2;
    int64_t a_pow3;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-10000 <= (a * a) <= 10000);
    a_pow2 = a * a;
    
    //@ assert (-1000000 <= (a * a * a) <= 1000000);
    a_pow3 = a * a * a;
    
    result = a;
    //@ assert result == a;
    
    //@ assert result + a_pow2 == a + a * a;
    result += a_pow2;
    
    //@ assert result + a_pow3 == a + a * a + a * a * a;
    result += a_pow3;
    
    return result;
}
