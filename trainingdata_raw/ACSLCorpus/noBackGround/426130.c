/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
*/
int func(int a, int b)
{
    int answer = 0;

    if (a == b)
    {
        answer = a + b;
        //@ assert answer == a + b;
    }
    else if (a > b)
    {
        answer = 2 * a - 1;
        //@ assert answer == 2 * a - 1;
    }
    else
    {
        answer = 2 * b - 1;
        //@ assert answer == 2 * b - 1;
    }

    //@ assert answer >= 0;
    //@ assert answer == a + b || answer == 2 * a - 1 || answer == 2 * b - 1;
    return answer;
}
