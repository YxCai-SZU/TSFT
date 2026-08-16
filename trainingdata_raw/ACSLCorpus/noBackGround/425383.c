/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (b) != (a)));
    ensures \result == 0 <==> !(((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (b) != (a)));
    assigns \nothing;
 */
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int ans;

    ans = 0;

    if (a == b && a != c) {
        ans = 1;
    } else if (a == c && a != b) {
        ans = 1;
    } else if (b == c && b != a) {
        ans = 1;
    } else {
        ans = 0;
    }

    //@ assert ans == 1 <==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (b) != (a)));

    return ans;
}
