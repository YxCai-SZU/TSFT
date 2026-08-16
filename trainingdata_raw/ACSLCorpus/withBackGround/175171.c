/*@
    predicate is_even(integer v) = v % 2 == 0;
    logic integer half(integer v) = v / 2;
    lemma half_lemma: \forall integer y; is_even(y) ==> 2 * half(y) == y;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires is_even(y);
    ensures \result == x + half(y);
*/
int func(int x, int y)
{
    int half_y;
    int temp_y;
    
    half_y = 0;
    temp_y = y;
    
    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant half_y <= half(y);
        loop invariant temp_y == y - 2 * half_y;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant is_even(y);
        loop assigns temp_y, half_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        half_y += 1;
    }
    
    //@ assert half_y == half(y);
    //@ assert x + half_y <= 150;
    
    return x + half_y;
}
