#include <limits.h>

/*@
    requires (-1290 <= (a) && (a) <= 1290);
    ensures \result == ((a) * (a) * (a));
    ensures INT_MIN <= \result <= INT_MAX;
*/
int func(int a)
{
    // Variable declarations at top
    int a_squared;
    int a_cubed;
    
    //@ assert (-1290 <= (a) && (a) <= 1290);
    
    //@ assert -1290*1290 <= a*a <= 1290*1290;
    
    a_squared = a * a;
    
    //@ assert -1290*1290*1290 <= a*a_squared <= 1290*1290*1290;
    
    a_cubed = a * a_squared;
    
    //@ assert INT_MIN <= a_cubed <= INT_MAX;
    
    return a_cubed;
}
