/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 9;

    logic integer condition_result(integer a, integer b, integer c) =
        (a == b && b != c) ? 1 :
        (a == c && a != b) ? 1 :
        (b == c && b != a) ? 1 : 0;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == condition_result(a, b, c);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result;

    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;

    if (a == b && a != c) {
        //@ assert condition_result(a, b, c) == 1;
        result = 1;
    } else if (a == c && a != b) {
        //@ assert condition_result(a, b, c) == 1;
        result = 1;
    } else if (b == c && b != a) {
        //@ assert condition_result(a, b, c) == 1;
        result = 1;
    } else {
        //@ assert condition_result(a, b, c) == 0;
        result = 0;
    }

    return result;
}
