/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);
    ensures \result >= ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    ensures \result <= a + c;
    ensures \result <= b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min1;
    int min2;
    int ans;

    //@ assert (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);

    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }
    //@ assert min1 == ((a) < (b) ? (a) : (b));

    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }
    //@ assert min2 == ((c) < (d) ? (c) : (d));

    ans = min1 + min2;
    //@ assert ans == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));

    //@ assert ans <= a + c;
    //@ assert ans <= b + d;

    return ans;
}
