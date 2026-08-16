/*@
requires ((x) > 0);
ensures \result > 0;
assigns \nothing;
*/
int lemma_g_ensures_positive(int x)
{
    //@ assert ((x) > 0);
    return x;
}

/*@
ensures \result == 1;
assigns \nothing;
*/
int test()
{
    int x;
    int result = 1;
    
    /*@
    loop invariant 0 <= x <= 10;
    loop invariant result == 1;
    loop assigns x;
    */
    for (x = 0; x < 10; x++)
    {
        //@ assert x >= 0;
    }
    
    return result;
}

/*@
assigns \nothing;
*/
int main()
{
    test();
    return 0;
}
