#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 9 && 1 <= (m) && (m) <= 9);
    ensures \result == true <==> (n * m) % 2 == 0;
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;

    //@ assert (1 <= (n) && (n) <= 9 && 1 <= (m) && (m) <= 9);
    
    //@ assert ((n) * (m)) <= 81;
    product = n * m;
    
    //@ assert product == ((n) * (m));
    is_even = (product % 2 == 0);
    
    //@ assert is_even == ((((n) * (m)) % 2) == 0);
    return is_even;
}
