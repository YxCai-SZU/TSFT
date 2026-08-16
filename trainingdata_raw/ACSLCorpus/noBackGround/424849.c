/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b) || (b == c) || (c == a));
    ensures \result == 3 ==> (a != b && b != c && c != a);
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);

    if ((a == b) && (b == c)) {
        ans = 1;
        //@ assert ans == 1;
        //@ assert (a == b) && (b == c);
    } else if ((a == b) || (b == c) || (c == a)) {
        ans = 2;
        //@ assert ans == 2;
        //@ assert (a == b) || (b == c) || (c == a);
    } else {
        ans = 3;
        //@ assert ans == 3;
        //@ assert (a != b) && (b != c) && (c != a);
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
