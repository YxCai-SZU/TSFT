/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 100 && 1 <= b <= 2000;

    logic integer min_val(integer n, integer a, integer b) =
        n * a < b ? n * a : b;

    lemma product_bound:
        \forall integer n, integer a;
        1 <= n <= 20 && 1 <= a <= 100 ==> n * a <= 2000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int min_val;

    //@ assert n >= 1 && n <= 20;
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 2000;

    //@ assert n * a <= 2000;

    if (n * a < b) {
        min_val = n * a;
    } else {
        min_val = b;
    }

    //@ assert min_val == n * a || min_val == b;
    //@ assert min_val <= b;

    return min_val;
}
