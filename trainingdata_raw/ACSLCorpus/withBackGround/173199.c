/*@
    predicate example_7_pre(integer a, integer b, integer c, integer d) =
        1 <= a && a <= 2 &&
        3 <= b && b <= 4 &&
        5 <= c && c <= 6 &&
        7 <= d && d <= 8;

    predicate example_7_post(integer a, integer b, integer c, integer d) =
        a + c <= 8;

    predicate example_8_pre(integer a, integer b) =
        1 <= a && a <= 2 &&
        3 <= b && b <= 4;

    predicate example_8_post(integer a, integer b) =
        a + b <= 6;

    lemma example_7_lemma:
        \forall integer a, b, c, d;
        example_7_pre(a, b, c, d) ==> example_7_post(a, b, c, d);

    lemma example_8_lemma:
        \forall integer a, b;
        example_8_pre(a, b) ==> example_8_post(a, b);
*/

/*@
    requires example_7_pre(a, b, c, d);
    ensures example_7_post(a, b, c, d);
*/
void example_7(int a, int b, int c, int d)
{
    /*@ assert 1 <= a && a <= 2; */
    /*@ assert 3 <= b && b <= 4; */
    /*@ assert 5 <= c && c <= 6; */
    /*@ assert 7 <= d && d <= 8; */
    /*@ assert 1 + 5 <= 2 + 6; */
    /*@ assert a + c <= 8; */
}

/*@
    requires example_8_pre(a, b);
    ensures example_8_post(a, b);
*/
void example_8(int a, int b)
{
    /*@ assert 1 <= a && a <= 2; */
    /*@ assert 3 <= b && b <= 4; */
    /*@ assert 1 + 3 <= 2 + 4; */
    /*@ assert a + b <= 6; */
}

int main()
{
    return 0;
}
