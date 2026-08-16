/*@
    predicate is_odd(integer y) = y % 2 != 0;
    predicate in_range(integer v) = 1 <= v && v <= 100;
 */

/*@
    requires in_range(x) && in_range(y);
    ensures \result == (y % 2 != 0);
    assigns \nothing;
 */
int func(int x, int y)
{
    int is_odd = 0;
    int temp_y = y;
    
    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop assigns temp_y;
     */
    while (temp_y >= 2)
    {
        temp_y -= 2;
    }
    
    if (temp_y == 1)
    {
        is_odd = 1;
    }
    
    //@ assert is_odd == (y % 2 != 0);
    
    return is_odd;
}
