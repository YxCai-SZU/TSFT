#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures ((\result) == (((((x)) / 100) * 100) <= (x)));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int m;
    unsigned int sub_total;
    
    n = x / 100;
    m = x % 100;
    sub_total = n * 100;
    
    //@ assert sub_total == (((x) / 100) * 100);
    
    return sub_total <= x;
}
