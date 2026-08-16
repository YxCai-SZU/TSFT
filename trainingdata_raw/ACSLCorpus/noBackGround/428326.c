/*@
requires x >= 0;
ensures \result >= x + 3;
assigns \nothing;
*/
int verify_linear_arithmetic(int x)
{
    int result;
    int intermediate;

    //@ assert 2*x >= x;
    result = 2 * x + 3;
    
    //@ assert result >= x + 3;
    intermediate = x + x + 3;
    
    //@ assert x <= x + 3;
    //@ assert intermediate >= x + 3;
    
    return result;
}

int main()
{
    return 0;
}
