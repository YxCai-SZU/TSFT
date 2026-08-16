/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    predicate product_in_range(integer a, integer b) =
        1 <= a * b && a * b <= 2000;

    lemma product_range_lemma:
        \forall integer a, b;
        valid_range(a, b, 2000) ==> product_in_range(a, b);
*/

/*@
    requires valid_range(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int x;
    int max_value;
    int min_value;
    int diff;
    int result;

    //@ assert product_in_range(a, b);
    x = a * b;

    // Manual max implementation
    if (x > c) {
        max_value = x;
    } else {
        max_value = c;
    }

    // Manual min implementation
    if (x < c) {
        min_value = x;
    } else {
        min_value = c;
    }

    // Manual abs implementation
    if (max_value - min_value < 0) {
        diff = -(max_value - min_value);
    } else {
        diff = max_value - min_value;
    }

    // Final max implementation
    if (diff < c) {
        result = diff;
    } else {
        result = c;
    }

    //@ assert result <= c;
    //@ assert result >= 0;
    return result;
}
