/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a * 2 - 1 || \result == b * 2 - 1 || \result == a + b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int a_twice_minus_one;
    int b_twice_minus_one;
    int a_plus_b;
    int max_val;

    a_twice_minus_one = a * 2 - 1;
    b_twice_minus_one = b * 2 - 1;
    a_plus_b = a + b;

    max_val = a_twice_minus_one;
    if (b_twice_minus_one > max_val)
    {
        max_val = b_twice_minus_one;
    }
    if (a_plus_b > max_val)
    {
        max_val = a_plus_b;
    }

    //@ assert max_val == a * 2 - 1 || max_val == b * 2 - 1 || max_val == a + b;

    return max_val;
}
