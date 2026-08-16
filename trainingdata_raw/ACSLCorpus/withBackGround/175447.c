/*@
    predicate example_2_pre(integer a, integer b, integer c) =
        a * b == c;

    predicate example_2_post(integer a, integer b, integer c) =
        a * b * 2 <= c * 2;

    lemma example_2_lemma:
        \forall integer a, b, c;
        example_2_pre(a, b, c) ==> example_2_post(a, b, c);
*/

/*@
    requires example_2_pre(a, b, c);
    ensures example_2_post(a, b, c);
*/
void example_2(int a, int b, int c)
{
    //@ assert a * b == c;
    //@ assert a * b * 2 == c * 2;
    //@ assert a * b * 2 <= c * 2;
}

int main()
{
    return 0;
}
