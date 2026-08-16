/*@
    requires \true;
    ensures \result == (-(x));
*/
int test_neg_postconditions(int x)
{
    //@ assert (-(x)) == -x;
    return -x;
}

/*@
    requires \true;
    ensures \result == ((x) * (x));
*/
int test_square_postconditions(int x)
{
    //@ assert ((x) * (x)) == x * x;
    return x * x;
}

int main()
{
    int x;
    int y;
    
    // Test neg function
    x = 5;
    //@ assert (-(x)) == -5;
    y = -5;
    //@ assert (-(y)) == 5;
    
    // Test square function
    x = 3;
    //@ assert ((x) * (x)) == 9;
    y = -3;
    //@ assert ((y) * (y)) == 9;
    
    return 0;
}
