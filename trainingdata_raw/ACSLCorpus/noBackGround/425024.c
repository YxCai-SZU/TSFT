/*@
    requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    ensures \result >= 0;
    ensures \result <= c;
    ensures a - b >= c ==> \result == 0;
    ensures a - b < c ==> \result == c - (a - b);
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;
    
    if (a - b >= c)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = c - (a - b);
        //@ assert result == c - (a - b);
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert a - b >= c ==> result == 0;
    //@ assert a - b < c ==> result == c - (a - b);
    return result;
}

int main()
{
    return 0;
}
