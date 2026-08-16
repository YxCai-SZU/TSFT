/*@
    predicate is_valid_range(integer v) = 3 <= v && v <= 20;

    logic integer min_val(integer x, integer y) = (x < y) ? x : y;
    logic integer max_val(integer x, integer y) = (x > y) ? x : y;

    lemma min_max_properties:
        \forall integer a, b;
            is_valid_range(a) && is_valid_range(b) ==>
            (min_val(a,b) == a || min_val(a,b) == b) &&
            (max_val(a,b) == a || max_val(a,b) == b) &&
            min_val(a,b) <= max_val(a,b);
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
*/
int func(int a, int b) {
    int min_a;
    int max_a;
    int result;

    //@ assert is_valid_range(a) && is_valid_range(b);

    if (a < b) {
        min_a = a;
    } else {
        min_a = b;
    }

    if (a > b) {
        max_a = a;
    } else {
        max_a = b;
    }

    //@ assert min_a == a || min_a == b;
    //@ assert max_a == a || max_a == b;
    //@ assert min_a <= max_a;

    if (max_a - min_a == 1) {
        result = a + b;
    } else {
        result = 2 * max_a - 1;
    }

    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 0;
    return result;
}
