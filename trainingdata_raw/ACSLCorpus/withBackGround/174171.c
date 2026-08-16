/*@
    predicate bounds(integer x, integer y) =
        1 <= x && x <= 100 &&
        1 <= y && y <= 100;

    logic integer product(integer x, integer y) = x * y + 99;

    logic integer target(integer x, integer y) = (x * y + 99) / 100;

    lemma product_bound: \forall integer x, y; bounds(x, y) ==> product(x, y) <= 100 * 100 + 99;
*/

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result == (x * y + 99) / 100;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    unsigned int product;
    unsigned int result = 0;
    unsigned int remainder;

    //@ assert bounds(x, y);
    //@ assert product(x, y) <= 100 * 100 + 99;

    product = x * y + 99;
    remainder = product;

    /*@
        loop invariant bounds(x, y);
        loop invariant result <= target(x, y);
        loop invariant remainder == product - result * 100;
        loop invariant product <= 100 * 100 + 99;
        loop invariant result <= (100 * 100 + 99) / 100;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        result += 1;
        remainder -= 100;
    }

    //@ assert result == target(x, y);
    return result;
}
