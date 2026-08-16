/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    predicate is_valid_result(integer a, integer b, integer c, integer res) =
        res == expr1(a, b, c) ||
        res == expr2(a, b, c) ||
        res == expr3(a, b, c);

    lemma result_ge_11:
        \forall integer a, b, c, res;
        valid_input(a, b, c) && is_valid_result(a, b, c, res) ==> res >= 11;
*/

/*@
    requires valid_input(a, b, c);
    ensures is_valid_result(a, b, c, \result);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int max;
    int ans;
    int max_ans;

    //@ assert valid_input(a, b, c);

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    ans = a * 10 + b + c;
    max_ans = ans;

    if (a == max) {
        ans = a + b * 10 + c;
        //@ assert ans == expr2(a, b, c);
        if (ans > max_ans) {
            max_ans = ans;
        }
    }

    if (b == max) {
        ans = a + b + c * 10;
        //@ assert ans == expr3(a, b, c);
        if (ans > max_ans) {
            max_ans = ans;
        }
    }

    if (c == max) {
        ans = a * 10 + b + c;
        //@ assert ans == expr1(a, b, c);
        if (ans > max_ans) {
            max_ans = ans;
        }
    }

    //@ assert is_valid_result(a, b, c, max_ans);
    //@ assert max_ans >= 11;

    return max_ans;
}
