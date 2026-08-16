/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int sa;
    int sc;
    int res;

    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    //@ assert ((A) * (B)) <= 100000000;
    sa = A * B;

    //@ assert (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    //@ assert ((C) * (D)) <= 100000000;
    sc = C * D;

    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }

    //@ assert res == ((A) * (B)) || res == ((C) * (D));
    //@ assert res >= ((A) * (B));
    //@ assert res >= ((C) * (D));
    return res;
}
