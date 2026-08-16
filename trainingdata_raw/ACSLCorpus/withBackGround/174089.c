/*@
    predicate less_than_or_equal(integer a, integer b) = a <= b;

    lemma less_than_or_equal_lemma:
        \forall integer a, b; less_than_or_equal(a, b) ==> a <= b;
*/

/*@
    requires a >= 0;
    ensures \result < a + 3;
*/
int calc_example_10(int a)
{
    //@ assert a >= 0;
    //@ assert a <= a + 3;
    //@ assert a < a + 3;
    return a;
}

int main()
{
    return 0;
}
