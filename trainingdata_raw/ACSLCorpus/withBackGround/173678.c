/*@
    predicate f(integer i) = \true;

    lemma lemma_even_f:
        \forall integer i;
            0 <= i < 10 && i % 2 == 0 ==> f(i);

    lemma test_even_f:
        \forall integer i;
            0 <= i < 10 ==> (i % 2 == 0 ==> f(i));
*/

/*@
    requires 0 <= i < 10;
    requires i % 2 == 0;
    ensures f(i);
*/
void lemma_even_f_impl(int i)
{
    //@ assert f(i);
}

/*@
    requires \forall integer i; 0 <= i < 10 ==> (i % 2 == 0 ==> f(i));
*/
void test_even_f_impl()
{
    //@ assert \forall integer i; 0 <= i < 10 ==> (i % 2 == 0 ==> f(i));
}

int main()
{
    return 0;
}
