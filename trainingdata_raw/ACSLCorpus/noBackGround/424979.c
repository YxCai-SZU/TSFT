#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100000 && 0 <= (a) <= 100);
    ensures \result == ((n / 500) >= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int division_result;
    bool comparison_result;

    //@ assert n / 500 <= 200;
    division_result = n / 500;
    comparison_result = (division_result >= a);
    
    return comparison_result;
}
