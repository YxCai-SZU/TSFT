/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a + c || \result == b + c || \result == b + d || \result == a + d;
    ensures 2 <= \result <= 202;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    res = a + c;

    //@ assert 2 <= a + c <= 200;
    if (b + c > res) {
        res = b + c;
        //@ assert 2 <= b + c <= 200;
    }

    if (b + d > res) {
        res = b + d;
        //@ assert 2 <= b + d <= 200;
    }

    if (a + d > res) {
        res = a + d;
        //@ assert 2 <= a + d <= 200;
    }

    //@ assert res == a + c || res == b + c || res == b + d || res == a + d;
    return res;
}
