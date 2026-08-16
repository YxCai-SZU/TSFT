#include <stdbool.h>

/*@
    requires \valid(a + (0..2)) && \valid(b + (0..2)) && \valid(c + (0..2));
    requires (\forall integer i; 0 <= i < (3) ==> 
            \at((a)[i], Pre) == \at((a)[i], Here) && 
            \at((b)[i], Pre) == \at((b)[i], Here) && 
            \at((c)[i], Pre) == \at((c)[i], Here));
    ensures \result <==> (\forall integer i; 0 <= i < (3) ==> (a)[i] < (b)[i] && (b)[i] < (c)[i]);
    assigns \nothing;
*/
bool func(int *a, int *b, int *c)
{
    bool answer = false;
    bool first;
    bool second;
    bool third;

    //@ assert (\forall integer i; 0 <= i < (3) ==>              \at((a)[i], Pre) == \at((a)[i], Here) &&              \at((b)[i], Pre) == \at((b)[i], Here) &&              \at((c)[i], Pre) == \at((c)[i], Here));
    
    first = a[0] < b[0] && b[0] < c[0];
    //@ assert first == (a[0] < b[0] && b[0] < c[0]);
    
    second = a[1] < b[1] && b[1] < c[1];
    //@ assert second == (a[1] < b[1] && b[1] < c[1]);
    
    third = a[2] < b[2] && b[2] < c[2];
    //@ assert third == (a[2] < b[2] && b[2] < c[2]);
    
    if (first && second && third)
    {
        answer = true;
    }
    
    //@ assert answer == (first && second && third);
    
    return answer;
}
