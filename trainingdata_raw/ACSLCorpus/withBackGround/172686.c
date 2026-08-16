#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 20 && 1 <= b && b <= 20;

    logic integer func_spec(integer a, integer b) =
        a <= 9 && b <= 9 ? a * b : -1;

    lemma multiplication_bounds:
        \forall integer a, b;
            1 <= a && a <= 9 && 1 <= b && b <= 9 ==> a * b <= 81;
*/

/*@
    requires valid_input(a, b);
    ensures \result == func_spec(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t a_val;
    int32_t b_val;
    int32_t result;

    //@ assert valid_input(a, b);

    a_val = (a <= 9) ? (int32_t)a : -1;
    b_val = (b <= 9) ? (int32_t)b : -1;

    if (a_val == -1 || b_val == -1)
    {
        result = -1;
        //@ assert result == func_spec(a, b);
        return result;
    }
    else
    {
        //@ assert 1 <= a_val && a_val <= 9;
        //@ assert 1 <= b_val && b_val <= 9;
        //@ assert a_val * b_val <= 81;
        result = a_val * b_val;
        //@ assert result == func_spec(a, b);
        return result;
    }
}

int main()
{
    return 0;
}
