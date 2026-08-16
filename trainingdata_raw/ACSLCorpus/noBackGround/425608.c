/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && a != c) || (a == c && a != b) || (b == c && a != b));
 */
int func(int a, int b, int c)
{
    int answer = 0;
    //@ assert answer == 0;

    if (a == b && a != c)
    {
        answer = 1;
    }
    //@ assert answer == (a == b && a != c);

    if (a == c && a != b)
    {
        answer = 1;
    }
    //@ assert answer == ((a == b && a != c) || (a == c && a != b));

    if (b == c && a != b)
    {
        answer = 1;
    }
    //@ assert answer == ((a == b && a != c) || (a == c && a != b) || (b == c && a != b));

    return answer;
}
