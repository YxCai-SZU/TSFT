/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    lemma even_lemma: \forall integer i; is_even(i) ==> \true;
*/

/*@
    requires i % 2 == 0;
    ensures \true;
*/
void lemma_even_f(int i)
{
    //@ assert \true;
}

/*@
    ensures \true;
*/
void test_even_f()
{
    //@ assert \true;
}

int main()
{
    return 0;
}
