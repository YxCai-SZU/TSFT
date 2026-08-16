/*@
    requires n >= 0;
    ensures \exists integer x; ((x) + 1) > n;
*/
void lemma_exists_f_greater_than_n(int n)
{
    //@ assert ((n) + 1) > n;
    //@ assert \exists integer x; ((x) + 1) > n;
}

int main()
{
    return 0;
}
