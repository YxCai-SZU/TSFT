#include <stdbool.h>

/*@
    predicate is_ok(integer n, bool result) =
        (n >= 2000) <==> (result == true);
    predicate is_ng(integer n, bool result) =
        (n < 2000) <==> (result == false);
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result == true <==> n >= 2000;
    ensures \result == false <==> n < 2000;
    assigns \nothing;
*/
bool func(unsigned long n)
{
    bool result;

    //@ assert 1 <= n <= 100000;
    if (n < 2000)
    {
        result = false;
        //@ assert result == false;
    }
    else
    {
        result = true;
        //@ assert result == true;
    }

    //@ assert is_ok(n, result);
    //@ assert is_ng(n, result);
    return result;
}

/*@
    lemma func_postcondition:
        \forall integer n, bool result;
            (1 <= n <= 100000) &&
            ((result == true) <==> (n >= 2000)) &&
            ((result == false) <==> (n < 2000)) ==>
            (n < 2000 ==> result == false) &&
            (n >= 2000 ==> result == true);
*/
