/*@
    predicate is_nonnegative(integer value) = value >= 0;

    logic integer adder(integer x, integer y) = x + y;

    lemma adder_lemma_1:
        adder(10, 20) == 30;

    lemma adder_lemma_2:
        adder(10, 60) == 70;
*/

/*@
    requires 1 <= x && x <= 1000000;
    ensures \result == (x / 2) + (x % 2);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int half_x;
    int temp_x;
    int remainder;

    result = 0;
    half_x = 0;
    temp_x = x;

    /*@
        loop invariant 0 <= half_x;
        loop invariant half_x <= x / 2;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 2 * half_x;
        loop invariant half_x <= 500000;
        loop assigns temp_x, half_x;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x = temp_x - 2;
        half_x = half_x + 1;
    }

    if (temp_x == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }

    result = half_x + remainder;

    //@ assert result == (x / 2) + (x % 2);
    return result;
}
