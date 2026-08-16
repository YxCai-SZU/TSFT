#include <stdbool.h>
/*@
    requires (3 <= (n) <= 100 &&
        1 <= (a) < (b) < 20);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= 20);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int a, int b, int *p)
{
    int count = 0;
    int group = 0;
    int index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (n) &&
        0 <= (count) <= (n) &&
        (group) >= 0 &&
        (group) <= (index) * 3 &&
        (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= 20) &&
        (3 <= ((n)) <= 100 &&
        1 <= ((a)) < ((b)) < 20));
        loop assigns index, count, group;
        loop variant n - index;
    */
    while (index < n && count < n)
    {
        int task = p[index];
        //@ assert 1 <= task <= 20;
        
        if (task <= a)
        {
            group += 1;
        }
        else if (task <= b)
        {
            group += 2;
        }
        else
        {
            group += 3;
        }
        
        if (group >= n)
        {
            count += 1;
            group = 0;
        }
        
        index += 1;
        //@ assert 0 <= count <= n;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
