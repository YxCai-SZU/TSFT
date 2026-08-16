/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min;
    int answer;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    if (min > c) {
        min = c;
    }

    //@ assert min == (((a) <= (b) && (a) <= (c)) ? (a) : (((b) <= (a) && (b) <= (c)) ? (b) : (c)));

    answer = 0;

    if (b - min >= 0) {
        answer += 1;
    }
    if (a - min >= 0) {
        answer += 1;
    }
    if (c - min >= 0) {
        answer += 1;
    }

    //@ assert answer >= 0 && answer <= 3;

    return answer;
}
