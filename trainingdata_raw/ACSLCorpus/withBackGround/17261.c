/*@
    predicate is_one(integer a, integer b, integer c, integer res) =
        res == 1 ==> (a == b && b == c);
    predicate is_two(integer a, integer b, integer c, integer res) =
        res == 2 ==> ((a == b && b != c) || (a == c && b != a) || (b == c && a != b));
    predicate is_three(integer a, integer b, integer c, integer res) =
        res == 3 ==> (a != b && b != c && a != c);
    predicate in_range(integer res) =
        res >= 1 && res <= 3;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (a == c && b != a) || (b == c && a != b));
    ensures \result == 3 ==> (a != b && b != c && a != c);
*/
int func(int a, int b, int c)
{
    int res;

    if (a == b && b == c) {
        res = 1;
        //@ assert is_one(a, b, c, res);
    } else if (a != b && b != c && c != a) {
        res = 3;
        //@ assert is_three(a, b, c, res);
    } else {
        res = 2;
        //@ assert is_two(a, b, c, res);
    }

    //@ assert in_range(res);
    return res;
}
