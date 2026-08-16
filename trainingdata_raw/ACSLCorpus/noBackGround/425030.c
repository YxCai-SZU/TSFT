/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures (1 <= (\result) && (\result) <= 3);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int answer;

    result = -1;
    answer = 0;

    if (a == b && b == c) {
        answer = 1;
    } else if (a != b && b != c && c != a) {
        answer = 3;
    } else {
        answer = 2;
    }

    result = answer;

    //@ assert result >= 1;
    //@ assert result <= 3;

    return result;
}
