#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int func(int a)
{
    int a_pow2;
    int a_pow3;
    int res;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_pow2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_pow3 = a * a * a;
    
    res = a + a_pow2 + a_pow3;
    //@ assert res == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    
    return res;
}
