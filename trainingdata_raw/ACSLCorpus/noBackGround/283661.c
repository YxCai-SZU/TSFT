#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    //@ assert (1 <= (a) && (a) <= 10);
    
    int64_t result;
    
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    //@ assert a + a * a + a * a * a <= 1110;
    //@ assert a + a * a + a * a * a >= 3;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == ((a) + (a) * (a) + (a) * (a) * (a));
    return result;
}

int main()
{
    return 0;
}
