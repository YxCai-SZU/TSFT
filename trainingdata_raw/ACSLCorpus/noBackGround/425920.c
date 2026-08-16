#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    //@ assert (1 <= (a) <= 10);
    
    //@ assert 1 <= a * a <= 100;
    //@ assert 1 <= a * a * a <= 1000;
    
    return a + a * a + a * a * a;
}

int main()
{
    return 0;
}
