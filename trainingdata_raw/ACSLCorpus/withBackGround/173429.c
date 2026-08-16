/*@
    predicate is_in_range(integer num, integer min_val, integer max_val) =
        num >= min_val && num <= max_val;
*/

/*@
    lemma is_in_range_properties:
        \forall integer num, min_val, max_val;
            is_in_range(num, min_val, max_val) <==> (num >= min_val && num <= max_val);
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx = 3;
    int circumference;
    //@ assert 2 * r * 3 == 2 * r * pi_approx;
    circumference = 2 * r * pi_approx;
    return circumference;
}

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
int func_range(int r)
{
    int pi_approx = 3;
    int circumference;
    //@ assert is_in_range(2 * r * pi_approx, 2 * 1 * pi_approx, 2 * 100 * pi_approx);
    //@ assert 2 * r * 3 == 2 * r * pi_approx;
    circumference = 2 * r * pi_approx;
    return circumference;
}
