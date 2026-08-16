/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) * 2 + (b) * 1) / 2 + ((a) * 2 + (b) * 1) % 2;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    unsigned int expr_val;

    expr_val = a * 2 + b * 1;

    //@ assert expr_val == ((a) * 2 + (b) * 1);
    
    if (expr_val % 2 == 0)
    {
        result = expr_val / 2;
        //@ assert result == ((a) * 2 + (b) * 1) / 2 + ((a) * 2 + (b) * 1) % 2;
    }
    else
    {
        //@ assert expr_val / 2 + 1 == ((a) * 2 + (b) * 1) / 2 + ((a) * 2 + (b) * 1) % 2;
        result = expr_val / 2 + 1;
    }

    return result;
}
