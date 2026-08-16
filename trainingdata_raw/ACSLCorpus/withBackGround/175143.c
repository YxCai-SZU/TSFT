/*@
    predicate is_between(integer a, integer b, integer c) =
        a <= b && b <= c;

    lemma between_x_c:
        \forall integer a, integer c; is_between(a, a, c) ==> is_between(a, a, c);
*/

/*@
    requires \exists integer x; is_between(0, x, 5);
    ensures is_between(0, 5, 5);
*/
void test_between()
{
    //@ assert is_between(0, 0, 5);
}

int main()
{
    return 0;
}
