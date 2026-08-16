#include <stdbool.h>
#include <limits.h>

/*@
  requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
  requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
  ensures \result == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
*/
bool func(int a, int b, int c)
{
    int state = 0;
    //@ assert state == 0;
    
    if (a == b) {
        state = 1;
    }
    //@ assert (a == b) ==> (state == 1);
    
    if (b == c) {
        state = 1;
    }
    //@ assert (b == c) ==> (state == 1);
    
    if (a == c) {
        state = 1;
    }
    //@ assert (a == c) ==> (state == 1);
    
    if ((a < b && b < c) || (a > b && b > c)) {
        state = 2;
    }
    //@ assert ((a < b && b < c) || (a > b && b > c)) ==> (state == 2);
    
    //@ assert state == 2 <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    return state == 2;
}
