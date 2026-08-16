/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
*/
int func(int a, int b, int c)
{
    int ab;
    int bc;
    int ca;
    int ans;

    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }
    if (b > c) {
        bc = b - c;
    } else {
        bc = c - b;
    }
    if (c > a) {
        ca = c - a;
    } else {
        ca = a - c;
    }

    ans = 0;
    if (ab + bc == ca || bc + ca == ab || ca + ab == bc) {
        ans = 1;
        //@ assert ans == 1;
    } else if (ab + bc > ca || bc + ca > ab || ca + ab > bc) {
        ans = 2;
        //@ assert ans == 2;
    } else {
        ans = 3;
        //@ assert ans == 3;
    }
    return ans;
}
