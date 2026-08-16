/*@
    predicate is_ordered(integer x, integer y, integer z) =
        x < y && y < z;

    lemma order_implication:
        \forall integer x, y, z;
            -100 <= x <= 100 && -100 <= y <= 100 && -100 <= z <= 100 &&
            x < y && y < z ==> is_ordered(x, y, z);
*/

/*@
    requires -100 <= x <= 100;
    requires -100 <= y <= 100;
    requires -100 <= z <= 100;
    ensures \result == (x < y && y < z);
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int result;
    int a;
    int b;
    int c;

    result = (x < y) && (y < z);
    a = x + y;
    b = y + z;
    c = a + b;

    //@ assert result == (x < y && y < z);

    return result;
}
