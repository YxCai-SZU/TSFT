/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    lemma min_in_range:
        \forall integer x, y;
            is_valid_range(x) && is_valid_range(y) ==> 
            is_valid_range(min(x, y));

    lemma sum_ge_two:
        \forall integer x, y;
            is_valid_range(x) && is_valid_range(y) ==> 
            x + y >= 2;

    lemma sum_possible_values:
        \forall integer a, b, c, d, res;
            is_valid_range(a) && is_valid_range(b) && 
            is_valid_range(c) && is_valid_range(d) &&
            res == min(a, b) + min(c, d) ==>
            res == a + c || res == a + d || res == b + c || res == b + d;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && 
             is_valid_range(c) && is_valid_range(d);
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
    ensures \result >= 2;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int ans;

    //@ assert is_valid_range(a) && is_valid_range(b);
    //@ assert is_valid_range(c) && is_valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == min(a, b);

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == min(c, d);

    //@ assert is_valid_range(min_ab);
    //@ assert is_valid_range(min_cd);

    ans = min_ab + min_cd;
    //@ assert ans >= 2;
    //@ assert ans <= 20000;

    return ans;
}
