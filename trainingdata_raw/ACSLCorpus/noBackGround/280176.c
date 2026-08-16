/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)));
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int answer = 0;
    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if ((a == b) && (b == c))
    {
        answer = 0;
        //@ assert !(((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }
    else if ((a == b) || (b == c) || (c == a))
    {
        answer = 1;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }
    else
    {
        answer = 0;
        //@ assert !(((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    }

    //@ assert answer == 1 <==> (((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    return answer;
}
