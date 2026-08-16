#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t a_1;
    int64_t a_2;
    int64_t a_3;
    int64_t ans;
    
    a_1 = a;
    
    //@ assert ((a_1) * (a_1)) <= 100;
    //@ assert ((a_1) * (a_1) * (a_1)) <= 1000;
    //@ assert ((a_1) + (((a_1)) * ((a_1))) + (((a_1)) * ((a_1)) * ((a_1)))) <= 1110;
    
    a_2 = a_1 * a_1;
    a_3 = a_1 * a_1 * a_1;
    ans = a_1 + a_2 + a_3;
    
    //@ assert ans == ((a_1) + (((a_1)) * ((a_1))) + (((a_1)) * ((a_1)) * ((a_1))));
    return ans;
}
