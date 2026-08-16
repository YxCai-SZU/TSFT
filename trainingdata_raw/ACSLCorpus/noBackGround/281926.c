/*@
    requires ((x) + 2 == (y) && (y) + 3 == (z));
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_3(int x, int y, int z)
{
    //@ assert x + 2 == y;
    return 0;
}

/*@
    requires ((x) + 2 == (y) && (y) + 3 == (z) && (z) + 4 == (w));
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_4(int x, int y, int z, int w)
{
    //@ assert x + 2 == y;
    return 0;
}

/*@
    assigns \nothing;
*/
int main()
{
    int x = 0;
    int y = 2;
    int z = 5;
    int w = 9;
    
    //@ assert ((x) + 2 == (y) && (y) + 3 == (z));
    calc_example_3(x, y, z);
    
    //@ assert ((x) + 2 == (y) && (y) + 3 == (z) && (z) + 4 == (w));
    calc_example_4(x, y, z, w);
    
    return 0;
}
