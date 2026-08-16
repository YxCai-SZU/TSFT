#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <==> (((a) + (b) + (c)) % 2) == 0;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    unsigned int ab_sum;
    unsigned int total_sum;
    bool result;
    
    // Proof assertions
    //@ assert 1 <= a + b <= 200;
    //@ assert 1 <= a + b + c <= 300;
    
    ab_sum = a + b;
    total_sum = ab_sum + c;
    result = (total_sum % 2) == 0;
    
    return result;
}
