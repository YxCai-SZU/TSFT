/*@
requires \exists integer j; ((i) > 0 && (j) > 0);
ensures ((i) > 0);
assigns \nothing;
*/
void test_g_proves_f(int i)
{
    //@ assert \exists integer j; ((i) > 0 && (j) > 0);
    //@ assert ((i) > 0);
}

/*@
assigns \nothing;
*/
int main()
{
    return 0;
}
