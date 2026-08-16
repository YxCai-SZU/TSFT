/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min;
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a < b)
    {
        if (a < c)
        {
            min = a;
        }
        else
        {
            min = c;
        }
    }
    else
    {
        if (b < c)
        {
            min = b;
        }
        else
        {
            min = c;
        }
    }
    
    //@ assert min == (((a) < (b)) ?             (((a) < (c)) ? (a) : (c))         :             (((b) < (c)) ? (b) : (c)));
    //@ assert 1 <= min <= 100;
    
    if ((b - min == 0) || (a - min == 0) || (c - min == 0))
    {
        //@ assert (b - min == 0) || (a - min == 0) || (c - min == 0);
        result = 1;
    }
    else
    {
        //@ assert (b - min != 0) && (a - min != 0) && (c - min != 0);
        result = 2;
    }
    
    //@ assert result >= 1 && result <= 3;
    return result;
}
