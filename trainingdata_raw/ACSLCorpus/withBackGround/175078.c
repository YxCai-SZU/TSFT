/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_y_value(integer i) = i / 2;

    lemma half_y_correct: \forall integer i;
        i % 2 == 0 ==> half_y_value(i) * 2 == i;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= y;
        loop invariant i % 2 == 0;
        loop invariant half_y == i / 2;
        loop assigns half_y, i;
    */
    while (i < y)
    {
        //@ assert half_y == i / 2;
        half_y += 1;
        i += 2;
    }
    
    //@ assert half_y == y / 2;
    return x + half_y;
}
