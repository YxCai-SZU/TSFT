/*@
requires d == 3;
requires e == 2 * d;
ensures \result >= 6;
*/
int func(int d, int e)
{
    //@ assert e == 2 * d;
    //@ assert e == 6;
    //@ assert e >= 6;
    return e;
}

int main()
{
    int d;
    int e;
    
    d = 3;
    e = 2 * d;
    
    int result = func(d, e);
    
    return 0;
}
