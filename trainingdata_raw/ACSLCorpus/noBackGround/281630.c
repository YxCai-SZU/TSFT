#include <stdbool.h>

/*@
    requires 1 <= n <= 100 && 1 <= k <= 100;
    ensures \result == true <==> n % k == 0;
    assigns \nothing;
*/
bool is_evenly_divisible(unsigned int n, unsigned int k)
{
    // Variable declarations at scope top
    unsigned int remainder;
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    remainder = n % k;
    
    //@ assert remainder <= 100;
    
    if (remainder == 0) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> n % k == 0;
    return result;
}

/*@
    requires -1000 <= a <= 1000 && -1000 <= b <= 1000;
    ensures \result == a + b;
    ensures -2000 <= \result <= 2000;
    assigns \nothing;
*/
int add(int a, int b)
{
    int result;
    
    //@ assert -1000 <= a <= 1000;
    //@ assert -1000 <= b <= 1000;
    
    result = a + b;
    
    //@ assert result == a + b;
    //@ assert -2000 <= result <= 2000;
    
    return result;
}
