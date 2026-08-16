/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result <= a * b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert (1 <= (a) * (b) && (a) * (b) <= 10000);
    
    int x;
    x = a * b;
    
    if (x < c)
    {
        //@ assert x >= 0;
        //@ assert x <= c;
        //@ assert x <= a * b;
        return x;
    }
    else
    {
        //@ assert c >= 0;
        //@ assert c <= c;
        //@ assert c <= a * b;
        return c;
    }
}

int main()
{
    return 0;
}
