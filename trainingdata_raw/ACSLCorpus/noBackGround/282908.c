#include <stdbool.h>

/*@
    requires (0 <= (A) <= 100) && (0 <= (B) <= 100) && (0 <= (X) <= 100);
    ensures \result == (A <= X && (X - A) <= B);
    assigns \nothing;
*/
bool func(unsigned long long A, unsigned long long B, unsigned long long X)
{
    // Variable declarations at scope top
    bool result;
    unsigned long long Y;

    //@ assert (0 <= (A) <= 100) && (0 <= (B) <= 100) && (0 <= (X) <= 100);

    if (A > X)
    {
        //@ assert A > X;
        result = false;
    }
    else
    {
        //@ assert A <= X;
        Y = X - A;
        //@ assert Y == ((X) - (A));
        
        if (Y <= B)
        {
            //@ assert Y <= B;
            result = true;
        }
        else
        {
            //@ assert Y > B;
            result = false;
        }
    }
    
    //@ assert result == (A <= X && (X - A) <= B);
    return result;
}
