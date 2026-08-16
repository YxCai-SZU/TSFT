/*@
    predicate valid_input(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer total(integer a, integer p) = a * 3 + p;

    lemma ans_nonnegative:
        \forall integer a, p;
        valid_input(a, p) ==>
        total(a, p) >= 0;
*/

/*@
    requires valid_input(a, p);
    ensures \result >= 0;
    ensures \result <= total(a, p);
    ensures \result == total(a, p) / 2;
    assigns \nothing;
*/
int func(int a, int p)
{
    int ans;
    int result;
    int count;

    //@ assert valid_input(a, p);
    ans = a * 3 + p;
    result = 0;
    count = 0;

    /*@
        loop invariant 0 <= a && a <= 100;
        loop invariant 0 <= p && p <= 100;
        loop invariant 0 <= ans && ans <= total(a, p);
        loop invariant 0 <= count && count <= total(a, p) / 2;
        loop invariant result == count;
        loop invariant ans == total(a, p) - 2 * count;
        loop assigns ans, result, count;
        loop variant ans;
    */
    while (ans >= 2)
    {
        ans -= 2;
        result += 1;
        count += 1;
        //@ assert ans == total(a, p) - 2 * count;
    }

    //@ assert result == total(a, p) / 2;
    return result;
}
