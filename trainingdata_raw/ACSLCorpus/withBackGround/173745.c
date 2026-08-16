/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) = y / 2;

    lemma half_y_correct: \forall integer y; y % 2 == 0 ==> half_of(y) * 2 == y;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == x + half_of(y);
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= y;
        loop invariant half_y == i / 2;
        loop invariant y % 2 == 0;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant half_y * 2 == i;
        loop assigns half_y, i;
        loop variant y - i;
    */
    while (i < y)
    {
        //@ assert half_y * 2 == i;
        half_y += 1;
        i += 2;
        //@ assert half_y * 2 == i;
    }

    //@ assert half_y == y / 2;
    return x + half_y;
}
