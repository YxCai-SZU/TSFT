/*@
    predicate bounds(integer x, integer y) =
        1 <= x <= 8 && 1 <= y <= 8;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y; bounds(x, y) ==> product(x, y) <= 64;
*/

/*@
    requires bounds(x, y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert bounds(x, y);
    //@ assert product(x, y) <= 64;

    result = x * y;
    return result;
}
