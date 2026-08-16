/*@
    predicate is_in_range(integer x) = 3 <= x && x <= 20;

    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
    logic integer max_val(integer a, integer b) = (a > b) ? a : b;

    lemma condition_lemma:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) ==>
            (max_val(a, b) > 2 * min_val(a, b) - 1) ==>
            (2 * min_val(a, b) - 1) >= 2;

    lemma alternative_lemma:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) ==>
            (max_val(a, b) <= 2 * min_val(a, b) - 1) ==>
            (a + b) >= 2;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == a + b || \result == 2 * b - 1 || \result == 2 * a - 1;
    ensures \result >= 2;
*/
int func(int a, int b)
{
    int min_a;
    int max_a;
    int result;

    //@ assert is_in_range(a) && is_in_range(b);

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

    //@ assert min_a == min_val(a, b);
    //@ assert max_a == max_val(a, b);

    if (max_a > 2 * min_a - 1) {
        //@ assert max_a > 2 * min_a - 1;
        result = 2 * min_a - 1;
        //@ assert result == 2 * min_val(a, b) - 1;
    } else {
        //@ assert max_a <= 2 * min_a - 1;
        result = a + b;
        //@ assert result == a + b;
    }

    //@ assert result >= 2;
    return result;
}
