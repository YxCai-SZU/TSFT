#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 13 &&
        1 <= (b) && (b) <= 13 &&
        1 <= (c) && (c) <= 13);
    ensures \result == true <==> ((((a)) + ((b)) + ((c))) >= 22 ||
        ((a) == 5 && (b) == 5 && (c) == 5));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at the top of the scope
    bool result;

    //@ assert (1 <= (a) && (a) <= 13 &&         1 <= (b) && (b) <= 13 &&         1 <= (c) && (c) <= 13);
    
    if (a + b + c >= 22 || (a == 5 && b == 5 && c == 5))
    {
        //@ assert ((((a)) + ((b)) + ((c))) >= 22 ||         ((a) == 5 && (b) == 5 && (c) == 5));
        result = true;
    }
    else
    {
        //@ assert !((((a)) + ((b)) + ((c))) >= 22 ||         ((a) == 5 && (b) == 5 && (c) == 5));
        result = false;
    }
    
    //@ assert result == true <==> ((((a)) + ((b)) + ((c))) >= 22 ||         ((a) == 5 && (b) == 5 && (c) == 5));
    return result;
}
