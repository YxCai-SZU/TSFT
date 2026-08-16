#include <stdbool.h>

/*@
    predicate condition_holds(integer n, integer a, integer b) =
        n % a < b;

    lemma branch_true:
        \forall integer n, a, b;
            1 <= n <= 10000 && 1 <= a <= 1000 && 1 <= b <= 2000 &&
            n % a < b ==> condition_holds(n, a, b);

    lemma branch_false:
        \forall integer n, a, b;
            1 <= n <= 10000 && 1 <= a <= 1000 && 1 <= b <= 2000 &&
            !(n % a < b) ==> !condition_holds(n, a, b);
*/

/*@
    requires 1 <= n <= 10000;
    requires 1 <= a <= 1000;
    requires 1 <= b <= 2000;
    ensures \result == true <==> (n % a < b);
*/
bool func(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int remainder;
    bool result;

    remainder = n % a;

    if (remainder < b)
    {
        //@ assert remainder < b;
        result = true;
    }
    else
    {
        //@ assert !(remainder < b);
        result = false;
    }

    //@ assert result == true <==> (remainder < b);
    return result;
}
