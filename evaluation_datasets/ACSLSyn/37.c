/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer target_value(integer a, integer b) = 6 - a - b;

    lemma target_in_range: \forall integer a, b; valid_inputs(a, b) ==> 1 <= target_value(a, b) <= 3;
*/

long find_missing_player(long a, long b)
{
    long result;

    result = 6 - a - b;

    return result;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 3;
    predicate b_in_range(integer b) = 1 <= b && b <= 3;
    predicate a_not_b(integer a, integer b) = a != b;
    predicate sum_condition(integer res, integer a, integer b) = res + a + b == 6;
    predicate res_in_range(integer res) = 1 <= res && res <= 3;
    
    logic integer compute_res(integer a, integer b) = 6 - a - b;
    
    lemma compute_res_properties:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) && a_not_b(a, b) ==>
        sum_condition(compute_res(a, b), a, b) && res_in_range(compute_res(a, b));
*/

long validate_and_compute(long a, long b) {
    long res;
    
    res = 6 - a - b;
    
    return res;
}

long tournament_round(long a, long b)
{
    long missing_player;

    missing_player = find_missing_player(a, b);

    long verified_missing = validate_and_compute(a, b);

    //@ assert missing_player == verified_missing;

    //@ assert (missing_player != a && missing_player != b && 1 <= missing_player <= 3);

    return missing_player;
}
