/*@
    requires a > 0 && b > 0 && c > 0;
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
 */
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result;
    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a <= 100 && b <= 100 && c <= 100;
    
    if (a < b)
    {
        if (b < c)
        {
            //@ assert ((a) < (b) && (b) < (c));
            result = 1;
        }
        else
        {
            //@ assert !((a) < (b) && (b) < (c));
            result = 0;
        }
    }
    else
    {
        //@ assert !((a) < (b) && (b) < (c));
        result = 0;
    }
    
    //@ assert result == 1 <==> ((a) < (b) && (b) < (c));
    return result;
}

int main()
{
    // Example usage:
    //@ assert 1 == 1;
    //@ assert !(0 == 1);
    return 0;
}
