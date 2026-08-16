/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a) * 10 + (b) + (c)) || \result == ((a) + (b) * 10 + (c)) || \result == ((a) + (b) + (c) * 10);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int ans;
    int tmp;

    ans = -2147483648;
    tmp = a * 10 + b + c;
    //@ assert tmp == ((a) * 10 + (b) + (c));
    if (tmp > ans) {
        ans = tmp;
    }
    //@ assert ans == ((a) * 10 + (b) + (c)) || ans == -2147483648;

    tmp = a + b * 10 + c;
    //@ assert tmp == ((a) + (b) * 10 + (c));
    if (tmp > ans) {
        ans = tmp;
    }
    //@ assert ans == ((a) * 10 + (b) + (c)) || ans == ((a) + (b) * 10 + (c)) || ans == -2147483648;

    tmp = a + b + c * 10;
    //@ assert tmp == ((a) + (b) + (c) * 10);
    if (tmp > ans) {
        ans = tmp;
    }
    //@ assert ans == ((a) * 10 + (b) + (c)) || ans == ((a) + (b) * 10 + (c)) || ans == ((a) + (b) + (c) * 10);

    //@ assert ans >= 11;
    return ans;
}
