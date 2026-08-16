/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c <= b ? a + c : a + b + 1 + b - c);
*/
int func(int a, int b, int c)
{
    int min_val;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    min_val = c < b ? c : b;
    //@ assert min_val == ((c) < (b) ? (c) : (b));
    
    result = a + min_val;
    
    if (c > b)
    {
        //@ assert c > b;
        //@ assert min_val == b;
        return result + 1 + b - c;
    }
    else
    {
        //@ assert c <= b;
        //@ assert min_val == c;
        return result;
    }
}
