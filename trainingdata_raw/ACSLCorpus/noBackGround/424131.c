/*@
requires \exists integer j; ((((i)) % 2 == 0) && (i) + (j) == 5);
ensures ((((i)) % 2 == 0));
*/
void test_g_proves_f(int i)
{
    //@ assert \exists integer j; ((((i)) % 2 == 0) && (i) + (j) == 5);
    //@ assert ((((i)) % 2 == 0));
}

int main()
{
    return 0;
}
