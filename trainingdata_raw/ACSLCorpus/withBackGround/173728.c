/*@
    predicate is_in_range(integer v) = -100 <= v && v <= 100;

    logic integer min_of_three(integer a, integer b, integer c) =
        (a <= b && a <= c) ? a :
        (b <= a && b <= c) ? b : c;

    lemma min_is_one_of:
        \forall integer a, b, c;
        is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
        (min_of_three(a,b,c) == a || min_of_three(a,b,c) == b || min_of_three(a,b,c) == c);
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a != b && a != c && b != c) ==> \result == min_of_three(a,b,c);
*/
int func(int a, int b, int c)
{
    int result;
    int x;
    int y;
    int z;
    int temp;

    if (a == b) {
        result = c;
        //@ assert (a == b && a != c) ==> result == c;
        return result;
    } else if (a == c) {
        result = b;
        //@ assert (a == c && a != b) ==> result == b;
        return result;
    } else if (b == c) {
        result = a;
        //@ assert (b == c && a != b) ==> result == a;
        return result;
    } else {
        x = a;
        y = b;
        z = c;

        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }
        //@ assert x <= y;

        if (y > z) {
            temp = y;
            y = z;
            z = temp;
        }
        //@ assert y <= z;

        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }
        //@ assert x <= y && y <= z;

        //@ assert x == a || x == b || x == c;
        result = x;
        //@ assert result == min_of_three(a,b,c);
        return result;
    }
}
