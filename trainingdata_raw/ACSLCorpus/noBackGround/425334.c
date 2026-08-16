/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == a + b + c || \result == 10 * a + b + c || \result == 10 * b + c + a;
*/
int func(int a, int b, int c)
{
    int min_val;
    int max_val;
    int sum;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    sum = min_val * 10 + max_val + c;

    //@ assert sum == a + b + c || sum == 10 * a + b + c || sum == 10 * b + c + a;

    return sum;
}
