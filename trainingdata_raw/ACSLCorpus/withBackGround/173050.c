#include <stdbool.h>

/*@
    predicate is_possible(integer a, integer b, bool result) =
        result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool is_possible = false;

    // Check the first condition
    //@ assert is_possible == false;
    if (a % 3 == 0)
    {
        is_possible = true;
    }

    // Check the second condition
    if (b % 3 == 0)
    {
        is_possible = true;
    }

    // Check the third condition
    if ((a + b) % 3 == 0)
    {
        is_possible = true;
    }

    //@ assert is_possible(a, b, is_possible);
    return is_possible;
}
