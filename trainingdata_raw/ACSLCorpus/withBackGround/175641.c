/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer total_value(integer k, integer high) = (k - high) * 500;

    lemma total_calculation:
        \forall integer k, high;
        0 <= high <= k ==> total_value(k, high) <= k * 500;

    lemma loop_maintains_total:
        \forall integer k, high;
        0 <= high <= k ==> high + (total_value(k, high) / 500) == k;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (k * 500 >= x);
*/
_Bool func(int k, int x)
{
    int en = 500;
    int high = k;
    int total = 0;

    /*@
        loop invariant 0 <= high <= k;
        loop invariant total == (k - high) * 500;
        loop invariant total <= k * 500;
        loop invariant high + (total / 500) == k;
        loop assigns total, high;
    */
    while (high > 0)
    {
        total += en;
        high -= 1;
    }

    //@ assert total == k * 500;
    //@ assert total >= x ==> k * 500 >= x;

    return total >= x;
}
