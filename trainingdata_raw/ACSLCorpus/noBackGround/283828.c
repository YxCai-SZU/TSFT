#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    ensures ((a) + (a) * (a) + (a) * (a) * (a) >= 3 && (a) + (a) * (a) + (a) * (a) * (a) <= 1110);
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert a >= 1 && a <= 10;
    //@ assert a * a >= 1 && a * a <= 100;
    //@ assert a * a * a >= 1 && a * a * a <= 1000;
    //@ assert a + a * a >= 2 && a + a * a <= 110;
    //@ assert a + a * a + a * a * a >= 3 && a + a * a + a * a * a <= 1110;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == a + a * a + a * a * a;
    return result;
}

int main()
{
    return 0;
}
