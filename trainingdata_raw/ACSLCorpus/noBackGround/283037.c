#include <stdbool.h>

/*@
  requires (1 <= (n) && (n) <= 9);
  ensures \result == (n == 3 || n == 5 || n == 7);
  assigns \nothing;
*/
bool func(int n)
{
    //@ assert (1 <= (n) && (n) <= 9);
    //@ assert n == (int)n;
    
    bool result;
    
    if (n == 3 || n == 5 || n == 7) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

/*@
  requires (1 <= (n) && (n) <= 9);
  ensures \result == (n == 3 || n == 5 || n == 7);
  assigns \nothing;
*/
bool func2(int n)
{
    //@ assert (1 <= (n) && (n) <= 9);
    //@ assert n == (int)n;
    
    int i = 1;
    
    /*@
      loop invariant 1 <= i <= 10;
      loop invariant (1 <= (n) && (n) <= 9);
      loop invariant n == (int)n;
      loop assigns i;
      loop variant 10 - i;
    */
    while (i < 10) {
        //@ assert 1 <= i && i <= 10;
        i = i + 1;
    }
    
    bool result;
    
    if (n == 3 || n == 5 || n == 7) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
