/*@
    predicate min_of_two(integer x, integer y, integer m) =
        (x < y ==> m == x) && (x >= y ==> m == y);

    logic integer min_sum(integer a, integer b, integer c, integer d) =
        (a < b ? a : b) + (c < d ? c : d);

    lemma min_sum_bounds:
        \forall integer a, b, c, d;
        1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 && 1 <= d <= 5000 ==>
        min_sum(a,b,c,d) >= (a < b ? a : b) + (c < d ? c : d) &&
        min_sum(a,b,c,d) <= a + b + c + d;
*/

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >= (a < b ? a : b) + (c < d ? c : d);
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_sum_val;
    int max_sum;

    //@ assert 1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 && 1 <= d <= 5000;

    if (a < b) {
        min_ab = a;
        //@ assert min_of_two(a, b, min_ab);
    } else {
        min_ab = b;
        //@ assert min_of_two(a, b, min_ab);
    }

    if (c < d) {
        min_cd = c;
        //@ assert min_of_two(c, d, min_cd);
    } else {
        min_cd = d;
        //@ assert min_of_two(c, d, min_cd);
    }

    min_sum_val = min_ab + min_cd;
    max_sum = a + b + c + d;

    //@ assert min_sum_val == min_sum(a, b, c, d);
    //@ assert min_sum_val >= min_ab + min_cd;
    //@ assert max_sum == a + b + c + d;
    //@ assert min_sum_val <= max_sum;

    return min_sum_val;
}
