/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_valid_range(integer x) = 1 <= x <= 20;
    logic integer max(integer x, integer y) = (x > y) ? x : y;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    ensures (is_small(a) && is_small(b)) ==> \result == a * b;
    ensures (!is_small(a) || !is_small(b)) ==> \result == -1;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int max_value;
    int result;

    //@ assert is_valid_range(a) && is_valid_range(b);
    max_value = (a > b) ? a : b;

    if (max_value <= 9)
    {
        //@ assert is_small(a) && is_small(b);
        //@ assert a * b <= 81;
        result = (int)(a * b);
        return result;
    }
    else
    {
        //@ assert !is_small(a) || !is_small(b);
        result = -1;
        return result;
    }
}
