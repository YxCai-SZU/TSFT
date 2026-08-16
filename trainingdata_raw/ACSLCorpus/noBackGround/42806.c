#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) * 100 + (b)) % 200 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int sum;
    bool is_divisible_by_200;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    
    //@ assert a * 100 <= 10000;
    //@ assert a * 100 + b <= 10100;
    
    sum = a * 100 + b;
    is_divisible_by_200 = (sum % 200 == 0);
    
    //@ assert sum == a * 100 + b;
    //@ assert is_divisible_by_200 == (sum % 200 == 0);
    
    return is_divisible_by_200;
}
