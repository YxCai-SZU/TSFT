#include <stdbool.h>

/*@
    predicate is_even(integer n) = (n % 2) == 0;
*/

/*@
    requires \true;
    ensures \result == ((n % 2) == 0);
    assigns \nothing;
*/
bool is_even(unsigned int n) {
    //@ assert n % 2 == 0 ==> (n % 2) == 0;
    return (n % 2) == 0;
}
