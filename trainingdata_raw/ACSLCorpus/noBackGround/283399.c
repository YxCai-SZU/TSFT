#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t a_2;
    int64_t a_3;
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 10);
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_3 = a * a * a;
    
    ans = a + a_2 + a_3;
    
    //@ assert 3 <= ans && ans <= 1110;
    //@ assert ans == a + (a * a) + (a * a * a);
    
    return ans;
}
