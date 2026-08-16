/*@
    requires ((x) >= 1 && (x) <= 100 &&
        (y) >= 0 && (y) <= 100);
    ensures ((\result) >= 0 && (\result) <= 100 &&
        ((\result) == ((x) + (y)) / 2 + 1 || (\result) == ((x) + (y)) / 2));
    assigns \nothing;
*/
int func(int x, int y)
{
    int sum;
    int average;
    int remainder;

    sum = x + y;
    average = 0;
    remainder = sum;

    /*@
        loop invariant 0 <= remainder <= sum;
        loop invariant sum == x + y;
        loop invariant 0 <= average <= sum / 2;
        loop invariant remainder == sum - 2 * average;
        loop assigns average, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        average += 1;
        remainder -= 2;
        //@ assert remainder == sum - 2 * average;
    }

    if (remainder > 0)
    {
        average += 1;
    }

    //@ assert ((average) >= 0 && (average) <= 100 &&         ((average) == ((x) + (y)) / 2 + 1 || (average) == ((x) + (y)) / 2));
    return average;
}
