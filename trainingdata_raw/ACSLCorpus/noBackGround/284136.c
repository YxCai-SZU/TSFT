/*@
requires \exists integer j; (((i) * (j)) % 2 == 0);
ensures (\true);
assigns \nothing;
*/
void test_g_proves_f(int i)
{
    // Declarations
    int j;
    
    //@ assert \exists integer j_val; (((i) * (j_val)) % 2 == 0);
    //@ assert (\true);
}

int main()
{
    // Declarations
    int i = 0;
    
    return 0;
}
