/*@
    predicate leq(integer a, integer b) = a <= b;

    lemma calc_example_8: \forall integer x, y; x == y ==> x * 2 == y * 2;
    lemma lemma2: \forall integer a, b, c, d; leq(a, b) && leq(b, c) && leq(c, d) ==> leq(a, d);
    lemma lemma4: \forall integer a, b, c; leq(a, b) && leq(b, c) ==> leq(a, c);
    lemma lemma6: \forall integer a, b, c; leq(a, b) && leq(b, c) ==> leq(a, c);
    lemma lemma8: \forall integer a, b, c, d, e; leq(a, b) && leq(b, c) && leq(c, d) && leq(d, e) ==> leq(a, e);
    lemma lemma10: \forall integer a, b, c, d, e, f; leq(a, b) && leq(b, c) && leq(c, d) && leq(d, e) && leq(e, f) ==> leq(a, f);
    lemma lemma12: \forall integer a, b, c, d, e, f, g; leq(a, b) && leq(b, c) && leq(c, d) && leq(d, e) && leq(e, f) && leq(f, g) ==> leq(a, g);
*/

/*@
    requires x == y;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_8(int x, int y)
{
    //@ assert x * 2 == y * 2;
    return 0;
}

/*@
    requires a <= b && b <= c && c <= d;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma2(int a, int b, int c, int d)
{
    //@ assert a <= d;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma4(int a, int b, int c)
{
    //@ assert a <= c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma6(int a, int b, int c)
{
    //@ assert a <= c;
    return 0;
}

/*@
    requires a <= b && b <= c && c <= d && d <= e;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma8(int a, int b, int c, int d, int e)
{
    //@ assert a <= e;
    return 0;
}

/*@
    requires a <= b && b <= c && c <= d && d <= e && e <= f;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma10(int a, int b, int c, int d, int e, int f)
{
    //@ assert a <= f;
    return 0;
}

/*@
    requires a <= b && b <= c && c <= d && d <= e && e <= f && f <= g;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma12(int a, int b, int c, int d, int e, int f, int g)
{
    //@ assert a <= g;
    return 0;
}

int main()
{
    return 0;
}
