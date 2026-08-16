/*@
    predicate is_valid_range(integer x) = 3 <= x && x <= 20;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    ensures \result == a + a - 1 || \result == b + b - 1 || \result == a + b || \result == b + a;
*/
int func(int a, int b)
{
    int min_a;
    int min_b;
    int min_ab;
    int min_val;

    min_a = a + a - 1;
    min_b = b + b - 1;
    min_ab = a + b;

    min_val = min_a;
    //@ assert min_val == min_a;
    if (min_b < min_val)
    {
        min_val = min_b;
        //@ assert min_val == min_b;
    }
    //@ assert min_val == min_a || min_val == min_b;
    if (min_ab < min_val)
    {
        min_val = min_ab;
        //@ assert min_val == min_ab;
    }
    //@ assert min_val == min_a || min_val == min_b || min_val == min_ab;
    return min_val;
}
