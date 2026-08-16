/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 100 &&
        1 <= b && b <= 2000;

    logic integer min_val(integer n, integer a, integer b) =
        n * a < b ? n * a : b;

    lemma min_val_bounds:
        \forall integer n, a, b;
        valid_params(n, a, b) ==> 0 <= min_val(n, a, b) && min_val(n, a, b) <= b;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result <= b;
    ensures \result >= 0;
*/
int func(int n, int a, int b)
{
    int min_val;
    int result = 0;
    int temp;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 2000;

    /*@ assert 1 <= n * a && n * a <= 2000; */
    if (n * a < b) {
        min_val = n * a;
    } else {
        min_val = b;
    }

    temp = min_val;
    /*@
        loop invariant 1 <= n && n <= 20;
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 2000;
        loop invariant result >= 0;
        loop invariant temp >= 0;
        loop invariant temp + 2 * result == min_val;
        loop assigns result, temp;
    */
    while (temp >= 2)
    {
        result += 1;
        temp -= 2;
    }

    return result;
}
