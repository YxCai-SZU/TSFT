/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) = y / 2;

    lemma half_correct: \forall integer y; y % 2 == 0 ==> 2 * half_of(y) == y;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == x + half_of(y);
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y;
    int temp_y;
    int count;
    
    half_y = 0;
    temp_y = y;
    count = 0;

    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant half_y >= 0;
        loop invariant temp_y == y - 2 * half_y;
        loop invariant y % 2 == 0;
        loop assigns temp_y, half_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        //@ assert temp_y >= 2;
        temp_y = temp_y - 2;
        half_y = half_y + 1;
        //@ assert temp_y == y - 2 * half_y;
    }

    //@ assert half_y == half_of(y);
    int ans = x + half_y;
    //@ assert ans == x + half_of(y);
    return ans;
}
