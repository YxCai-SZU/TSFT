/*@
    predicate example_7_pre(integer a, integer b, integer c) =
        a + b == c;

    predicate example_7_post(integer a, integer b, integer c) =
        a + b <= c + 1;

    lemma example_7:
        \forall integer a, b, c;
        example_7_pre(a, b, c) ==> example_7_post(a, b, c);
*/

/*@
    predicate example_8_pre(integer a, integer b) =
        1 <= a <= 10 && 1 <= b <= 10;

    predicate example_8_post(integer a, integer b) =
        1 <= a * b <= 100;

    lemma example_8:
        \forall integer a, b;
        example_8_pre(a, b) ==> example_8_post(a, b);
*/

/*@
    predicate example_9_pre(integer a, integer b, integer c) =
        1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10;

    predicate example_9_post(integer a, integer b, integer c) =
        1 <= a * b * c <= 1000;

    lemma example_9:
        \forall integer a, b, c;
        example_9_pre(a, b, c) ==> example_9_post(a, b, c);
*/

int main()
{
    return 0;
}
