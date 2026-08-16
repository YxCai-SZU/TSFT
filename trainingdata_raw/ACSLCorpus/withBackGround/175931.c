#include <stdbool.h>

/*@
    predicate has_seven(integer n) =
        (n / 100) == 7 ||
        (n / 10) % 10 == 7 ||
        (n % 100) % 10 == 7;
*/

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> has_seven(n);
    assigns \nothing;
*/
bool func(int n)
{
    bool ok = false;
    
    //@ assert 100 <= n <= 999;
    
    if ((n / 100) == 7) {
        ok = true;
    } else if ((n / 10) % 10 == 7) {
        ok = true;
    } else if ((n % 100) % 10 == 7) {
        ok = true;
    }
    
    //@ assert ok == true <==> has_seven(n);
    
    return ok;
}
