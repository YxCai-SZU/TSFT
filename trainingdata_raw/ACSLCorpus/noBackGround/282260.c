#include <limits.h>

/*@
    requires (-1290 <= (a) <= 1290);
    ensures \result == ((a) * (a) * (a));
    assigns \nothing;
*/
int func(int a)
{
    int a_pow_2;
    int a_pow_3;
    
    //@ assert a * a >= -1290 * 1290 && a * a <= 1290 * 1290;
    a_pow_2 = a * a;
    
    //@ assert a * a_pow_2 >= -1290 * 1290 * 1290 && a * a_pow_2 <= 1290 * 1290 * 1290;
    a_pow_3 = a * a_pow_2;
    
    return a_pow_3;
}

int main()
{
    return 0;
}
