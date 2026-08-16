#include <stdbool.h>

/*@
  requires (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20);
  requires \valid(p + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int a, int b, int *p)
{
    int count = 0;
    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
      loop assigns i, count;
    */
    while (i < n)
    {
        int pi = p[i];
        
        //@ assert 1 <= pi && pi <= 20;
        
        if (pi <= a)
        {
            count += 1;
        }
        else if (pi <= b)
        {
            count += 1;
        }
        else
        {
            count += 1;
        }
        
        i += 1;
        
        //@ assert 0 <= count <= i;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
