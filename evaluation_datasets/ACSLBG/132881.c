/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a && a <= b && b <= 20;

    logic integer absolute(integer v) =
        v < 0 ? -v : v;

    lemma loop_decreases:
        \forall integer x, y;
            x >= 0 && y >= 0 && x + y > 0 ==>
            (x > 1 ? x - 2 : 0) + (y > 1 ? y - 2 : 0) < x + y;
*/


long func(long a, long b) {
    long result;
    long temp_a;
    long temp_b;
    long x;
    long y;
    int is_even;

    result = 0;
    temp_a = a;
    temp_b = b;

    //@ assert is_valid_range(a, b);

    if (temp_a < 0) {
        temp_a = -temp_a;
    }
    if (temp_b < 0) {
        temp_b = -temp_b;
    }

    //@ assert temp_a == absolute(a);
    //@ assert temp_b == absolute(b);

    x = temp_a;
    y = temp_b;
    is_even = 1;

    
    while (x > 1 || y > 1) {
        if (x == 1 || y == 1) {
            is_even = 0;
            break;
        }
        x = (x > 1) ? x - 2 : 0;
        y = (y > 1) ? y - 2 : 0;
    }

    if (is_even) {
        result = temp_a + temp_b;
    } else {
        result = temp_b - temp_a;
    }

    //@ assert result == a + b || result == b - a;
    return result;
}
