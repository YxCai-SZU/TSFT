/*@
requires \exists integer j; ((j) * 3) == i;
ensures i % 3 == 0;
*/
void test_exists_g_impl(int i)
{
    //@ assert \exists integer j; ((j) * 3) == i;
    //@ assert i % 3 == 0;
}

int main()
{
    return 0;
}
