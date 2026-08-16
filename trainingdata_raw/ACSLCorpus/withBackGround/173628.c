#include <stdbool.h>

/*@
    predicate is_valid_range(integer k, integer a, integer b) =
        1 <= k && k <= 1000 && 1 <= a && a <= b && b <= 1000;

    logic integer mod(integer x, integer y) = x % y;

    predicate condition_holds(integer k, integer a, integer b) =
        mod(a, k) == 0 || mod(b, k) == 0 || (b - a) >= k || mod(a, k) > mod(b, k);

    lemma mod_properties:
        \forall integer k, a, b;
            is_valid_range(k, a, b) && !condition_holds(k, a, b) ==>
                mod(a, k) != 0 && mod(b, k) != 0 && (b - a) < k && mod(a, k) <= mod(b, k);
*/

/*@
    requires is_valid_range(k, a, b);
    ensures \result == true <==> condition_holds(k, a, b);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    unsigned int a_mod_k;
    unsigned int b_mod_k;
    unsigned int diff;
    bool result;

    a_mod_k = a % k;
    b_mod_k = b % k;
    diff = b - a;

    if (a_mod_k == 0 || b_mod_k == 0)
    {
        result = true;
        //@ assert condition_holds(k, a, b);
        return result;
    }
    else if (diff >= k)
    {
        result = true;
        //@ assert condition_holds(k, a, b);
        return result;
    }
    else if (a_mod_k > b_mod_k)
    {
        result = true;
        //@ assert condition_holds(k, a, b);
        return result;
    }
    else
    {
        //@ assert a_mod_k != 0 && b_mod_k != 0 && diff < k && a_mod_k <= b_mod_k;
        result = false;
        //@ assert !condition_holds(k, a, b);
        return result;
    }
}
