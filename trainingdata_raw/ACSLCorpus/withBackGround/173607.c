#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer a) =
        1 <= n && n <= 10000 &&
        0 <= a && a <= 1000;

    logic integer remainder(integer n) = n % 500;
*/

/*@
    requires is_valid_params(n, a);
    ensures \result == (remainder(n) <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int pay;
    unsigned int remain;
    
    pay = n / 500;
    remain = n % 500;
    
    if (remain > a) {
        //@ assert remain == remainder(n);
        return false;
    } else {
        //@ assert remain == remainder(n) && remain <= a;
        return true;
    }
}
