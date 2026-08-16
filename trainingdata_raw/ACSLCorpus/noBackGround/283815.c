#include <limits.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    int a_2;
    int a_3;
    int result;
    
    //@ assert (1 <= (a) <= 10);
    
    // a * a
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    // a * a_2
    //@ assert 1 <= a * a_2 && a * a_2 <= 1000;
    a_3 = a * a_2;
    
    // a + a_2 + a_3
    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a_2 && a_2 <= 100;
    //@ assert 1 <= a_3 && a_3 <= 1000;
    //@ assert 3 <= a + a_2 + a_3 && a + a_2 + a_3 <= 1110;
    
    result = a + a_2 + a_3;
    return result;
}
