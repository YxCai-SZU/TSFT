#include <stdbool.h>

/*@
    predicate condition_holds(integer x, integer y) =
        x + y >= 9 || x * 2 >= y || y * 2 >= x;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> condition_holds(x, y);
    assigns \nothing;
*/
bool func(int x, int y)
{
    //@ assert 1 <= x <= 100 && 1 <= y <= 100;
    
    if (x + y >= 9) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    if (x * 2 >= y) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    if (y * 2 >= x) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    //@ assert !condition_holds(x, y);
    return false;
}

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> condition_holds(x, y);
    assigns \nothing;
*/
bool func2(int x, int y)
{
    //@ assert 1 <= x <= 100 && 1 <= y <= 100;
    
    if (x + y >= 9) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    if (x * 2 >= y) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    if (y * 2 >= x) {
        //@ assert condition_holds(x, y);
        return true;
    }
    
    //@ assert !condition_holds(x, y);
    return false;
}

int main() {
    return 0;
}
