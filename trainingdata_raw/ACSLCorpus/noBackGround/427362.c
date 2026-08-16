/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires y % 2 == 0;
    ensures \result == x + (y / 2);
*/
int func(int x, int y)
{
    int result;
    int half_y;
    int temp_y;
    int count;
    
    result = 0;
    half_y = 0;
    temp_y = y;
    count = 0;
    
    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant temp_y >= 0;
        loop invariant temp_y + 2 * count == y;
        loop invariant count >= 0;
        loop invariant count <= y / 2;
        loop assigns temp_y, count;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        count += 1;
    }
    half_y = count;
    
    //@ assert 0 <= half_y * 2 <= y;
    
    result = x + half_y;
    
    //@ assert result == x + (y / 2);
    
    return result;
}
