/*@
    requires 1 <= x && x <= 10;
    ensures \result >= x;
    ensures \result <= 100;
    ensures \result >= 1;
*/
int nonlinear_arith_example(int x)
{
    //@ assert (1 <= (x) && (x) <= 10);
    
    int result = x * x;
    
    //@ assert result == ((x) * (x));
    //@ assert ((x) * (x)) >= x;
    //@ assert ((x) * (x)) <= 100;
    //@ assert ((x) * (x)) >= 1;
    
    return result;
}

/*@
    requires 1 <= x && x <= 10;
    ensures \result >= x;
    ensures \result <= 100;
    ensures \result >= 1;
*/
int nonlinear_arith_example2(int x)
{
    //@ assert (1 <= (x) && (x) <= 10);
    
    int result = x * x;
    
    //@ assert result == ((x) * (x));
    //@ assert ((x) * (x)) >= x;
    //@ assert ((x) * (x)) <= 100;
    //@ assert ((x) * (x)) >= 1;
    
    return result;
}

int main()
{
    return 0;
}
