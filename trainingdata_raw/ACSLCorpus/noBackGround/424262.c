#include <stdint.h>

/*@
    requires 2 <= k <= 100;
    ensures \result == (k / 2) * ((k + 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t k)
{
    uint64_t kisu;
    uint64_t gusu;
    uint64_t ans;
    
    //@ assert (2 <= (k) <= 100);
    
    kisu = k / 2;
    gusu = (k + 1) / 2;
    
    //@ assert kisu == ((k) / 2);
    //@ assert gusu == (((k) + 1) / 2);
    
    //@ assert 1 <= kisu <= 50;
    //@ assert 1 <= gusu <= 50;
    //@ assert kisu * gusu <= 2500;
    //@ assert kisu * gusu == (k / 2) * ((k + 1) / 2);
    
    ans = kisu * gusu;
    
    //@ assert ans == ((((k)) / 2) * ((((k)) + 1) / 2));
    return ans;
}
