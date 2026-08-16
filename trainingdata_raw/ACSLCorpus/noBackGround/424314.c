/*@
    requires x >= 1 && x <= 1000;
    ensures \result >= 0;
    ensures \result * 3 <= x;
    ensures x < \result * 3 + 3;
*/
int func(int x)
{
    int result;
    int temp_x;
    int count;

    result = 0;
    temp_x = x;
    count = 0;

    /*@
        loop invariant temp_x >= 0;
        loop invariant count >= 0;
        loop invariant x == temp_x + count * 3;
        loop assigns temp_x, count;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        count += 1;
    }

    result = count;
    //@ assert result >= 0;
    //@ assert result * 3 <= x;
    //@ assert x < result * 3 + 3;
    return result;
}
