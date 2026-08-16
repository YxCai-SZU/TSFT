#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> (a - (b - c) > 0 || d - (a - b - c) > 0);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int expr1_val;
    int expr2_val;
    bool result;

    expr1_val = a - (b - c);
    expr2_val = d - (a - b - c);

    //@ assert expr1_val == a - (b - c);
    //@ assert expr2_val == d - (a - b - c);

    if (expr1_val > 0 || expr2_val > 0)
    {
        //@ assert expr1_val > 0 || expr2_val > 0;
        result = true;
    }
    else
    {
        //@ assert expr1_val <= 0 && expr2_val <= 0;
        result = false;
    }

    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    bool result;

    result = func(3, 2, 2, 1);
    //@ assert result == true;

    result = func(4, 3, 3, 2);
    //@ assert result == true;

    result = func(5, 5, 5, 5);
    //@ assert result == true;

    return 0;
}
#endif
