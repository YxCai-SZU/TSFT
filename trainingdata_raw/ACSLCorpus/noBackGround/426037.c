/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= 200;
*/
int func(int a, int b, int c)
{
    int result;
    int max_ab;
    int min_ac;

    result = 0;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a > b)
        max_ab = a;
    else
        max_ab = b;

    result += max_ab - 1;

    //@ assert result == ((a) > (b) ? (a) : (b)) - 1;

    if (a > c)
        min_ac = c;
    else
        min_ac = a;

    result += min_ac;

    //@ assert result == (((a) > (b) ? (a) : (b)) - 1) + ((a) > (c) ? (c) : (a));

    if (max_ab > min_ac)
        result += 1;

    //@ assert result == (((a) > (b) ? (a) : (b)) - 1) + ((a) > (c) ? (c) : (a)) + (((a) > (b) ? (a) : (b)) > ((a) > (c) ? (c) : (a)) ? 1 : 0);
    //@ assert result >= 0 && result <= 200;

    return result;
}
