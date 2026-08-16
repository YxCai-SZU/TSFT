#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int a_2;
    int a_3;
    int ans;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    //@ assert 1 <= a_2 * a && a_2 * a <= 1000;
    a_3 = a_2 * a;
    
    ans = a + a_2 + a_3;
    
    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return ans;
}
