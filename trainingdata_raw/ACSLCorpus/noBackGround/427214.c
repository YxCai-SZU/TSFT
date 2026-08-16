/*@
    requires (1 <= (x) && (x) <= 10000 &&
        1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000);
    ensures \result == (((a) + (b)) > (x) ? (a) + (b) - (x) : 0);
    ensures \result >= 0;
    ensures \result <= a + b;
*/
int func(int x, int a, int b)
{
    int result;
    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    
    if (a + b > x)
    {
        //@ assert a + b >= x;
        //@ assert a + b <= 20000;
        result = a + b - x;
    }
    else
    {
        //@ assert 0 <= a + b;
        //@ assert a + b <= 20000;
        result = 0;
    }
    
    //@ assert result == (((a) + (b)) > (x) ? (a) + (b) - (x) : 0);
    //@ assert result >= 0;
    //@ assert result <= a + b;
    return result;
}
