/*@
    requires (1 <= (X) && (X) <= 100 &&
        1 <= (Y) && (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == ((X) + (((Y)) / 2));
    assigns \nothing;
*/
int func(int X, int Y)
{
    int ans;
    int temp_Y;
    int count;

    ans = X;
    temp_Y = Y;
    count = 0;

    /*@
        loop invariant 1 <= X && X <= 100;
        loop invariant 1 <= Y && Y <= 100;
        loop invariant Y % 2 == 0;
        loop invariant 0 <= temp_Y && temp_Y <= Y;
        loop invariant 0 <= count;
        loop invariant count * 2 == Y - temp_Y;
        loop assigns temp_Y, count;
        loop variant temp_Y;
    */
    while (temp_Y >= 2)
    {
        //@ assert temp_Y >= 2;
        temp_Y -= 2;
        count += 1;
    }

    //@ assert count == ((Y) / 2);
    ans += count;
    //@ assert ans == ((X) + (((Y)) / 2));
    return ans;
}
