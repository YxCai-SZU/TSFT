#include <stdint.h>

/*@
    requires 1 <= a && a <= 100;
    ensures \result == a + a * a + a * a * a;
    ensures 3 <= \result <= 1110000;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a_2;
    int64_t a_3;
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert ((a) * (a)) == a * a;
    
    a_2 = a * a;
    //@ assert a_2 == ((a) * (a));
    //@ assert 1 <= a_2 && a_2 <= 10000;
    
    a_3 = a * a_2;
    //@ assert a_3 == ((a) * (a) * (a));
    //@ assert 1 <= a_3 && a_3 <= 1000000;
    
    ans = a + a_2 + a_3;
    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    //@ assert 3 <= ans && ans <= 1110000;
    
    return ans;
}
