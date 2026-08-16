#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    requires ((a) * (b) <= 10000) && ((a) * (c) <= 10000) && ((b) * (c) <= 10000);
    ensures \result == (a * b > c);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    long product;
    bool is_greater;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert ((a) * (b) <= 10000);
    
    product = a * b;
    is_greater = false;
    
    if (product > c) {
        is_greater = true;
    }
    
    //@ assert product == a * b;
    //@ assert product > c ==> is_greater == true;
    
    return is_greater;
}
