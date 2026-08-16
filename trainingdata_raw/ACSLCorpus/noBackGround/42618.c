/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == a + b + 1 || \result == b + c + 1 || \result == c + a + 1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val = a;
    //@ assert max_val == a;
    
    if (b > max_val)
    {
        max_val = b;
        //@ assert max_val == b;
    }
    //@ assert max_val >= a && max_val >= b;
    
    if (c > max_val)
    {
        max_val = c;
        //@ assert max_val == c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;
    //@ assert ((max_val) == (a) || (max_val) == (b) || (max_val) == (c));
    
    if (max_val == a)
    {
        //@ assert max_val == a;
        return b + c + 1;
    }
    else if (max_val == b)
    {
        //@ assert max_val == b;
        return a + c + 1;
    }
    else
    {
        //@ assert max_val == c;
        return a + b + 1;
    }
}
