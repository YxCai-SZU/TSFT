/*@
    requires (1 <= (X) && (X) <= 100) && (1 <= (Y) && (Y) <= 100) && ((Y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == (X + Y / 2) * 2;
*/
int func(int X, int Y)
{
    int ans;
    int temp_y;
    int temp_x;
    int quotient;
    int remainder;
    int sum;

    ans = 0;
    temp_y = Y;
    temp_x = X;
    quotient = 0;
    remainder = temp_y;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= temp_y / 2;
        loop invariant remainder == temp_y - 2 * quotient;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
        quotient += 1;
    }
    temp_y = quotient;

    sum = temp_x + temp_y;
    ans = sum * 2;

    //@ assert ans >= 0;
    //@ assert ans == (X + Y / 2) * 2;

    return ans;
}
