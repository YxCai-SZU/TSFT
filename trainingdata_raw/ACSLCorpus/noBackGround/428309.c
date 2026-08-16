/*@
requires ((x) == 50);
ensures ((\result) % 2 == 0);
*/
unsigned int f(unsigned int x);

/*@
requires ((50) == 50);
ensures \result % 2 == 0;
*/
unsigned int test_example_pass_by_value()
{
    //@ assert ((50) == 50);
    
    unsigned int ret = f(50);
    
    //@ assert ((ret) % 2 == 0);
    //@ assert ret % 2 == 0;
    
    return ret;
}
