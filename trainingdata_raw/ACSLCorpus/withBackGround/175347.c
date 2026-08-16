/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    logic integer expected_result(integer a, integer b) =
        6 - a - b;
*/

/*@
    requires valid_input(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert valid_input(a, b);
    
    if (a == 1) {
        if (b == 2) {
            result = 3;
        } else {
            result = 2;
        }
    } else if (a == 2) {
        if (b == 1) {
            result = 3;
        } else {
            result = 1;
        }
    } else {
        if (b == 1) {
            result = 2;
        } else {
            result = 1;
        }
    }

    //@ assert result == expected_result(a, b);
    
    return result;
}
