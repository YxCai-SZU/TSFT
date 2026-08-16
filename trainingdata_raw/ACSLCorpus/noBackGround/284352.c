#include <stdint.h>

/*@
    requires (-100 <= (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int32_t cube(int32_t x)
{
    //@ assert (-100 <= (x) <= 100);
    
    //@ assert -10000 <= x * x <= 10000;
    
    return x * x * x;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
