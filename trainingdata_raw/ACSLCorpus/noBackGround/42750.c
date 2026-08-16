/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result >= 0 && \result <= a;
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int count = k;
    int remaining_a = a;

    /*@
        loop invariant (0 <= (count) && (count) <= (k) &&
        0 <= (remaining_a) && (remaining_a) <= (a) &&
        (result) >= 0 && (result) <= (a) &&
        (result) == (k) - (count) &&
        (a) == (remaining_a) + (result));
        loop assigns result, count, remaining_a;
    */
    while (count > 0 && remaining_a > 0)
    {
        //@ assert count > 0 && remaining_a > 0;
        result += 1;
        count -= 1;
        remaining_a -= 1;
    }

    //@ assert result >= 0 && result <= a;
    return result;
}
