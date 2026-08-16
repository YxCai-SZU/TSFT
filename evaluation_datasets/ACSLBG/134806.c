/*@
    predicate is_nonnegative(integer v) = v >= 0;
    predicate is_positive(integer v) = v > 0;
    predicate is_nonpositive(integer v) = v <= 0;
    predicate is_negative(integer v) = v < 0;
    predicate in_range(integer v, integer low, integer high) = low <= v <= high;
*/

/*@
    logic integer shifted(integer x) = x + 40;
    logic integer distance(integer x) = 70 - shifted(x);
*/

/*@
    lemma shift_preserves_range:
        \forall integer x; in_range(x, -40, 40) ==> in_range(shifted(x), 0, 80);
    lemma distance_equivalence:
        \forall integer x; (distance(x) <= 0) <==> (shifted(x) >= 70);
    lemma original_condition:
        \forall integer x; (distance(x) <= 0) <==> (x >= 30);
*/


int func(int x)
{
    int y;
    int z;
    int result;

    y = x + 40;
    //@ assert y == shifted(x);
    //@ assert in_range(y, 0, 80);

    z = 70 - y;
    //@ assert z == distance(x);

    //@ assert (z <= 0) ==> (y >= 70);
    //@ assert (z <= 0) <==> (x >= 30);

    result = (z <= 0);
    //@ assert result == (x >= 30);
    return result;
}
