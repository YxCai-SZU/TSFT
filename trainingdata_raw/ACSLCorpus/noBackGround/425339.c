#include <stdbool.h>

/*@
  requires 1 <= n <= 9;
  ensures \result == (n == 7 || n == 5 || n == 3);
  assigns \nothing;
*/
bool func(int n)
{
    int allowed_values[3] = {7, 5, 3};
    int i = 0;
    
    if (n == 7 || n == 5 || n == 3)
    {
        //@ assert ((n) == 7 || (n) == 5 || (n) == 3);
        return true;
    }
    
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \forall integer k; 0 <= k < i ==> n != allowed_values[k];
      loop invariant \forall integer k; 0 <= k < 3 ==> (n != allowed_values[k] || ((n) == 7 || (n) == 5 || (n) == 3));
      loop assigns i;
      loop variant 3 - i;
    */
    while (i < 3)
    {
        if (n == allowed_values[i])
        {
            //@ assert ((n) == 7 || (n) == 5 || (n) == 3);
            return true;
        }
        i = i + 1;
    }
    
    //@ assert !((n) == 7 || (n) == 5 || (n) == 3);
    return false;
}
