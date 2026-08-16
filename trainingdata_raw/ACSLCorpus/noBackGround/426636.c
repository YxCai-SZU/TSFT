#include <stdbool.h>

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool res;
    
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if (a < b && b < c) {
        //@ assert ((a) < (b) && (b) < (c));
        res = true;
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        res = false;
    }
    
    //@ assert res == true <==> ((a) < (b) && (b) < (c));
    return res;
}

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func2(unsigned long a, unsigned long b, unsigned long c)
{
    bool ans;
    
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if (a < b && b < c) {
        //@ assert ((a) < (b) && (b) < (c));
        ans = true;
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        ans = false;
    }
    
    //@ assert ans == true || ans == false;
    
    if (a < b && b < c) {
        //@ assert ans == true;
    } else {
        //@ assert ans == false;
    }
    
    //@ assert ans == true <==> ((a) < (b) && (b) < (c));
    return ans;
}
