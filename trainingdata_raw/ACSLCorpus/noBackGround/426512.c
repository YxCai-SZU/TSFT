#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == true <==> 
        (((a) * 2 - 1) <= b && b <= ((a) * 2 + 1));
    assigns \nothing;
*/
bool func(int a, int b)
{
    int left;
    int right;
    bool result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    left = a * 2 - 1;
    right = a * 2 + 1;
    
    //@ assert left == ((a) * 2 - 1);
    //@ assert right == ((a) * 2 + 1);
    
    result = (b >= left) && (b <= right);
    
    //@ assert result == ((((a) * 2 - 1) <= b) && (b <= ((a) * 2 + 1)));
    return result;
}
