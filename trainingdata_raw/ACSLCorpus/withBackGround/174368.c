/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer multiply(integer n, integer a) = n * a;

    logic integer half_of(integer b) = b / 2;

    lemma multiplication_bounds:
        \forall integer n, integer a;
        valid_params(n, a, 1) ==> multiply(n, a) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result >= 0;
    ensures \result <= n * a;
*/
int func(int n, int a, int b)
{
    int train;
    int bus;
    int temp_b;
    int count;
    int min_val;

    //@ assert valid_params(n, a, b);
    //@ assert n * a <= 1000;

    train = n * a;

    bus = 0;
    temp_b = b;
    count = 0;

    /*@
        loop invariant 1 <= n && n <= 20;
        loop invariant 1 <= a && a <= 50;
        loop invariant 1 <= b && b <= 50;
        loop invariant temp_b >= 0;
        loop invariant count >= 0;
        loop invariant count * 2 + temp_b == b;
        loop assigns temp_b, count;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
        count += 1;
    }

    bus = count;

    if (train < bus)
    {
        min_val = train;
    }
    else
    {
        min_val = bus;
    }

    //@ assert min_val >= 0;
    //@ assert min_val <= n * a;

    return min_val;
}
