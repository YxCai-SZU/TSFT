/*@
    requires \exists integer j; ((i) == (j));
    ensures (\true);
*/
void test_g_proves_f(int i)
{
    //@ assert \exists integer j; ((i) == (j));
    //@ assert (\true);
}

int main()
{
    return 0;
}
