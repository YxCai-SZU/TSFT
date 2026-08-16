/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a - b) >= 0 ? c - (a - b) : 0;

    lemma result_property:
        \forall integer a, b, c;
        valid_range(a, b, c) ==>
            (compute_result(a, b, c) == c - (a - b) || compute_result(a, b, c) == 0);
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0 && \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int a_mod_2;
    int b_mod_2;
    int c_mod_2;
    int a_xor_b;
    int b_xor_c;
    int a_xor_c;
    int ans;

    result = c - (a - b);
    //@ assert result == c - (a - b);
    if (result < 0) {
        result = 0;
    }
    //@ assert result == compute_result(a, b, c);

    a_mod_2 = (a & 1) == 0 ? 0 : 1;
    b_mod_2 = (b & 1) == 0 ? 0 : 1;
    c_mod_2 = (c & 1) == 0 ? 0 : 1;

    a_xor_b = ((a_mod_2 == 1 && b_mod_2 == 0) || (a_mod_2 == 0 && b_mod_2 == 1)) ? 1 : 0;
    b_xor_c = ((b_mod_2 == 1 && c_mod_2 == 0) || (b_mod_2 == 0 && c_mod_2 == 1)) ? 1 : 0;
    a_xor_c = ((a_mod_2 == 1 && c_mod_2 == 0) || (a_mod_2 == 0 && c_mod_2 == 1)) ? 1 : 0;

    if (a_xor_b == b_xor_c) {
        if (a_xor_c == 0) {
            ans = result;
        } else {
            ans = 0;
        }
    } else if (a_xor_b == a_xor_c) {
        if (b_xor_c == 0) {
            ans = result;
        } else {
            ans = 0;
        }
    } else {
        if (a_xor_b == 0) {
            ans = result;
        } else {
            ans = 0;
        }
    }

    //@ assert ans == result || ans == 0;
    //@ assert ans == compute_result(a, b, c) || ans == 0;
    return ans;
}
