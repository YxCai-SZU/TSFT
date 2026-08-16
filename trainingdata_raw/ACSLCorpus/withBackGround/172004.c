/*@
    predicate X_in_range(integer X) = 1 <= X && X <= 100;
    predicate Y_in_range(integer Y) = 1 <= Y && Y <= 100;
    predicate Y_even(integer Y) = Y % 2 == 0;
    predicate temp_y_nonneg(integer temp_y) = temp_y >= 0;
    predicate count_bound(integer count) = count <= 50;
    predicate temp_y_relation(integer temp_y, integer Y, integer count) = temp_y == Y - 2 * count;
*/

/*@
    logic integer half_Y(integer Y) = Y / 2;
*/

/*@
    lemma loop_invariant_maintained:
        \forall integer X, Y, temp_y, count;
        X_in_range(X) && Y_in_range(Y) && Y_even(Y) &&
        temp_y_nonneg(temp_y) && count_bound(count) &&
        temp_y_relation(temp_y, Y, count) &&
        temp_y >= 2 && count < 50 ==>
        temp_y_nonneg(temp_y - 2) &&
        count_bound(count + 1) &&
        temp_y_relation(temp_y - 2, Y, count + 1);
*/

/*@
    requires X_in_range(X) && Y_in_range(Y) && Y_even(Y);
    ensures \result == X + half_Y(Y);
*/
int func(int X, int Y)
{
    int ans;
    int temp_y;
    int count;
    
    ans = X;
    temp_y = Y;
    count = 0;
    
    /*@
        loop invariant temp_y_nonneg(temp_y);
        loop invariant count_bound(count);
        loop invariant temp_y_relation(temp_y, Y, count);
        loop assigns temp_y, count;
    */
    while (temp_y >= 2 && count < 50) {
        //@ assert temp_y >= 2 && count < 50;
        temp_y = temp_y - 2;
        count = count + 1;
    }
    
    ans = ans + count;
    //@ assert ans == X + half_Y(Y);
    return ans;
}
