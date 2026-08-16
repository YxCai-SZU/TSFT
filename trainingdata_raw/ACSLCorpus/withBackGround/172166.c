/*@
    predicate valid_range(integer v) = 3 <= v && v <= 20;

    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
    logic integer max_val(integer a, integer b) = (a > b) ? a : b;

    lemma min_val_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> min_val(a, b) >= 0;
    lemma max_val_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> max_val(a, b) >= 0;
    lemma sum_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> a + b >= 0;
    lemma double_minus_one_nonnegative:
        \forall integer x; 11 <= x && x <= 20 ==> x * 2 - 1 >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int result;

    // Declare all variables at the top
    min_val = (a < b) ? a : b;
    max_val = (a > b) ? a : b;

    //@ assert min_val >= 3 && min_val <= 20;
    //@ assert max_val >= 3 && max_val <= 20;
    //@ assert min_val <= max_val;

    if (max_val <= 10) {
        result = max_val + min_val;
    } else if (min_val == 3) {
        result = max_val * 2 - 1;
    } else {
        result = max_val + min_val;
    }

    return result;
}
