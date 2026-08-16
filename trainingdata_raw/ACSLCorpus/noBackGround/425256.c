#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(a + (0..4));
    requires \valid(b + (0..4));
    requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
    requires (\forall integer i; 0 <= i < (5)-1 ==> (b)[i] < (b)[i+1]);
    requires (\forall integer i; 0 <= i < (5) ==> (a)[i] <= (5));
    requires (\forall integer i; 0 <= i < (5) ==> (b)[i] <= (5));
    ensures \result == (a[0] < b[4] && b[0] < a[4]);
*/
bool func(int *a, int *b)
{
    bool answer = false;
    
    //@ assert a[0] < a[4];
    //@ assert b[0] < b[4];
    
    if (a[0] < b[4] && b[0] < a[4])
    {
        answer = true;
    }
    
    //@ assert answer == (a[0] < b[4] && b[0] < a[4]);
    
    return answer;
}
