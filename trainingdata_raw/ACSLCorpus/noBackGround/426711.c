/*@
    requires ((m) == (n)) && ((n) < (p));
    ensures ((m) <= (p));
*/
void func_example_3(int m, int n, int p)
{
    /*@ assert ((m) == (n)); */
    /*@ assert ((n) < (p)); */
    /*@ assert ((m) <= (p)); */
}

int main()
{
    return 0;
}
