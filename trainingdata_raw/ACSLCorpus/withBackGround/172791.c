/*@
    predicate no_overflow(integer x, integer y) =
        x + y >= -2147483648 && x + y <= 2147483647;
*/

/*@
    logic integer sum(integer x, integer y) = x + y;
*/

/*@
    lemma sum_no_overflow:
        \forall integer x, y;
        no_overflow(x, y) ==> sum(x, y) >= -2147483648 && sum(x, y) <= 2147483647;
*/

/*@
    requires no_overflow(x, y);
    ensures \result == sum(x, y);
*/
int func(int x, int y)
{
    //@ assert no_overflow(x, y);
    int result = x + y;
    //@ assert result == sum(x, y);
    return result;
}
