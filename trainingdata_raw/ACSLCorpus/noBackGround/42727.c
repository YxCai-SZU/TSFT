/*@
    requires (-16 <= (x1) && (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
signed char octuple(signed char x1)
{
    signed char x2;
    signed char x4;
    signed char result;

    x2 = x1 + x1;
    x4 = x2 + x2;
    result = x4 + x4;
    
    //@ assert result == (8 * (x1));
    return result;
}

/*@
    requires (-16 <= (x1) && (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
signed char func(signed char x1)
{
    signed char x2;
    signed char x4;
    signed char x8;

    x2 = x1 + x1;
    x4 = x2 + x2;
    x8 = x4 + x4;
    
    //@ assert x2 == 2 * x1;
    //@ assert x4 == 4 * x1;
    //@ assert x8 == 8 * x1;
    //@ assert x8 == (8 * (x1));
    
    return x8;
}

int main()
{
    return 0;
}
