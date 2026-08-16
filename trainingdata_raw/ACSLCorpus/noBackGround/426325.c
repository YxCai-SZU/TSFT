/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) >= (b) + 1 ? (a) + (a) - 1 :
        (b) >= (a) + 1 ? (b) + (b) - 1 :
        (a) + (b));
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int result = 0;

    if (a >= b + 1)
    {
        result = a + a - 1;
    }
    else if (b >= a + 1)
    {
        result = b + b - 1;
    }
    else
    {
        result = a + b;
    }

    //@ assert result == a + a - 1 || result == a + b || result == b + b - 1;
    //@ assert result >= 0;

    return result;
}
