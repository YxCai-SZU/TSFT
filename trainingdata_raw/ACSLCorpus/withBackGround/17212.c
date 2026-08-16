/*@
    predicate is_in_range(integer x) = 3 <= x && x <= 20;

    logic integer max(integer a, integer b) = a > b ? a : b;
    logic integer min(integer a, integer b) = a < b ? a : b;

    lemma diff_one_implies_sum:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) && max(a,b) - min(a,b) == 1 ==>
            max(a,b) + min(a,b) == a + b;

    lemma diff_not_one_implies_double_max_minus_one:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) && max(a,b) - min(a,b) != 1 ==>
            2 * max(a,b) - 1 == 2 * a - 1 || 2 * max(a,b) - 1 == 2 * b - 1;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    int min_value;
    int result;

    if (a > b)
    {
        max_value = a;
        min_value = b;
    }
    else
    {
        max_value = b;
        min_value = a;
    }

    //@ assert max_value == max(a, b);
    //@ assert min_value == min(a, b);

    if (max_value - min_value == 1)
    {
        //@ assert max_value - min_value == 1;
        result = max_value + min_value;
        //@ assert result == a + b;
    }
    else
    {
        //@ assert max_value - min_value != 1;
        result = 2 * max_value - 1;
        //@ assert result == 2 * a - 1 || result == 2 * b - 1;
    }

    return result;
}
