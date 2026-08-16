#include <stdbool.h>

/*@
    requires (3 <= (n) && (n) <= 100 && (a) > 0 && (b) > 0 && (b) < (a));
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int a, int b, int *p)
{
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n)
    {
        int pi = p[index];
        
        //@ assert 1 <= pi && pi <= 20;
        
        if ((pi <= a && pi <= b) || (a < pi && pi < b))
        {
            //@ assert count + 1 <= index + 1;
            count += 1;
        }
        
        //@ assert count <= index + 1;
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
