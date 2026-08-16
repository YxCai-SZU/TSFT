/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result >= 10 && \result <= 999;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;

    max = a;
    //@ assert max == a;
    //@ assert (1 <= (max) && (max) <= 9);

    if (b > max)
    {
        max = b;
        //@ assert max == b;
    }
    //@ assert max == (((a) >= (b) && (a) >= (max)) ? (a) :         ((b) >= (a) && (b) >= (max)) ? (b) : (max));

    if (c > max)
    {
        max = c;
        //@ assert max == c;
    }
    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) : (c));

    //@ assert (1 <= (max) && (max) <= 9);
    //@ assert 10 <= max * 111 && max * 111 <= 999;

    return max * 111;
}
