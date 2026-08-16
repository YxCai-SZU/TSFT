/*@
    predicate valid_range(integer n) =
        1 <= n && n <= 10000;

    logic integer division_result(integer n) =
        n / 1000;

    lemma division_bounds:
        \forall integer n; valid_range(n) ==>
            division_result(n) >= 0 &&
            division_result(n) <= 10;
*/

/*@
    requires valid_range(n);
    ensures \result >= division_result(n);
    ensures \result <= division_result(n) + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int count;
    unsigned int rest;

    count = 0;
    rest = n;

    /*@
        loop invariant 0 <= count <= division_result(n);
        loop invariant rest == n - count * 1000;
        loop invariant valid_range(n);
        loop assigns count, rest;
        loop variant rest;
    */
    while (rest >= 1000)
    {
        //@ assert count < division_result(n) + 1;
        count = count + 1;
        rest = rest - 1000;
    }

    if (rest > 0)
    {
        //@ assert count == division_result(n);
        count = count + 1;
    }

    //@ assert count >= division_result(n);
    //@ assert count <= division_result(n) + 1;
    return count;
}
