/*@
    requires (1 <= (a) && 1 <= (b) && 1 <= (c) &&
        (a) <= 100 && (b) <= 100 && (c) <= 100);
    ensures \result == ((a) + (b)) || \result == ((b) + (c)) || \result == ((c) + (a));
    ensures \result >= 0;
    ensures \result <= 200;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int answer = 0;
    int max = 0;

    //@ assert (1 <= (a) && 1 <= (b) && 1 <= (c) &&         (a) <= 100 && (b) <= 100 && (c) <= 100);
    //@ assert ((a) + (b)) >= 0 && ((a) + (b)) <= 200;
    //@ assert ((b) + (c)) >= 0 && ((b) + (c)) <= 200;
    //@ assert ((c) + (a)) >= 0 && ((c) + (a)) <= 200;

    max = a + b;
    //@ assert max == ((a) + (b));

    if (b + c > max)
    {
        max = b + c;
        //@ assert max == ((b) + (c));
    }
    //@ assert max == ((a) + (b)) || max == ((b) + (c));

    if (c + a > max)
    {
        max = c + a;
        //@ assert max == ((c) + (a));
    }
    //@ assert max == ((a) + (b)) || max == ((b) + (c)) || max == ((c) + (a));

    answer = max;
    //@ assert answer == ((a) + (b)) || answer == ((b) + (c)) || answer == ((c) + (a));
    //@ assert answer >= 0;
    //@ assert answer <= 200;

    return answer;
}
