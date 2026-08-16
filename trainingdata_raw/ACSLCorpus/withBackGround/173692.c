/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max_val(integer a, integer b) = (a > b) ? a : b;
    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures 0 <= \result <= a + b;
    assigns \nothing;
*/
int min_unique_operations(int a, int b) {
    int max_val;
    int min_val;
    int half_max_val;
    int count;
    int result;

    // Calculate max and min
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    //@ assert max_val == max_val(a, b);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    //@ assert min_val == min_val(a, b);

    // Manual division by 2
    half_max_val = 0;
    count = max_val;

    /*@
        loop invariant 0 <= half_max_val <= max_val / 2;
        loop invariant 0 <= count <= max_val;
        loop invariant count == max_val - 2 * half_max_val;
        loop assigns count, half_max_val;
    */
    while (count >= 2) {
        count -= 2;
        half_max_val += 1;
    }

    // Calculate result
    result = half_max_val + min_val;
    if (half_max_val < min_val) {
        result += half_max_val;
    } else {
        result += min_val;
    }

    //@ assert 0 <= result <= a + b;
    return result;
}
