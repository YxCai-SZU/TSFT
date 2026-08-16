/*@
predicate f(integer i) = \true;

lemma lemma_even_f:
    \forall integer i; i % 2 == 0 ==> f(i);

lemma test_even_f:
    \forall integer i; i % 2 == 0 ==> f(i);
*/

/*@
requires i % 2 == 0;
ensures f(i);
*/
void lemma_even_f(int i)
{
    //@ assert f(i);
}

/*@
ensures \forall integer i; i % 2 == 0 ==> f(i);
*/
void test_even_f()
{
    //@ assert \forall integer i; i % 2 == 0 ==> f(i);
}

int main()
{
    return 0;
}
