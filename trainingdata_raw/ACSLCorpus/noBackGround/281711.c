/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (a == c && c != b) || (b == c && c != a));
    ensures \result == 3 ==> (a != b && b != c && c != a);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    if (a == b && b == c) {
        ans = 1;
    } else if (a == b || b == c || c == a) {
        ans = 2;
    } else {
        ans = 3;
    }

    //@ assert ans == 1 || ans == 2 || ans == 3;
    //@ assert ans == 1 ==> (a == b && b == c);
    //@ assert ans == 2 ==> ((a == b && b != c) || (a == c && c != b) || (b == c && c != a));
    //@ assert ans == 3 ==> (a != b && b != c && c != a);

    return ans;
}
