/*@
    requires (0 <= (a) && (a) <= 50 &&
        0 <= (b) && (b) <= 50 &&
        0 <= (c) && (c) <= 50);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
long func(long a, long b, long c)
{
    long ret = 0;
    //@ assert ret == 0;

    if (c > 0)
    {
        if (b < c)
        {
            ret += b * 2 + 1;
            //@ assert ret == b * 2 + 1;
            
            long c_temp = c - (b + 1);
            long a_temp = (a > 1) ? (a - 1) : 0;
            
            //@ assert a_temp >= 0;
            //@ assert c_temp >= 0;
            
            if (a_temp + 1 < c_temp)
            {
                ret += a_temp + 1;
                //@ assert ret == b * 2 + 1 + a_temp + 1;
            }
            else
            {
                ret += c_temp;
                //@ assert ret == b * 2 + 1 + c_temp;
            }
        }
        else
        {
            ret += c * 2;
            //@ assert ret == c * 2;
        }
    }
    
    //@ assert ret >= 0;
    //@ assert ret <= a + b + c;
    
    return ret;
}
