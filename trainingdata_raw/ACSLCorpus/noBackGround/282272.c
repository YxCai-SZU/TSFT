/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result <= b / a;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int res;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert b / a >= 0;

    if (c < b / a) {
        res = c;
        //@ assert res == c;
    } else {
        res = b / a;
        //@ assert res == b / a;
    }

    //@ assert res <= c;
    //@ assert res <= b / a;
    return res;
}
