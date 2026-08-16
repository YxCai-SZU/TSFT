/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == a * b;
*/
int func(int a, int b)
{
    int result;
    int i;
    int a_plus;
    int b_plus;

    result = 1;
    i = 0;
    a_plus = a;
    b_plus = b;

    if (a > b) {
        a_plus = a - 1;
        b_plus = b - 1;
    } else {
        a_plus = a;
        b_plus = b - 1;
    }

    /*@
        loop invariant 0 <= i <= a_plus;
        loop invariant result == 1;
        loop assigns i;
        loop variant a_plus - i;
    */
    while (i < a_plus) {
        i = i + 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= b_plus;
        loop invariant result == 1;
        loop assigns i;
        loop variant b_plus - i;
    */
    while (i < b_plus) {
        i = i + 1;
    }

    //@ assert a * b <= 10000;
    //@ assert a * b >= 1;
    //@ assert a * b == a * b;

    result = a * b;
    return result;
}

int main(void)
{
    return 0;
}
