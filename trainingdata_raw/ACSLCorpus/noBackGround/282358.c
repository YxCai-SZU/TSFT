/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
*/
int func(int a, int b, int c)
{
    int i;
    int result;

    i = 0;
    /*@
        loop invariant 0 <= i && i <= 3;
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant 1 <= c && c <= 100;
        loop invariant i >= 3 || (i == 0 || i == 1 || i == 2);
        loop assigns i;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert i < 3;
        i = i + 1;
    }
    //@ assert i == 3;

    result = (a < b && b < c) ? 1 : 0;
    //@ assert result == 1 <==> ((a) < (b) && (b) < (c));
    return result;
}

int main(void)
{
    return 0;
}
