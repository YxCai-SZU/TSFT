#include <stdbool.h>

/*@
  requires (1 <= (A) && (A) <= 1000 &&
      1 <= (B) && (B) <= 1000 &&
      (A) + (B) <= (X) && (X) <= 10000 &&
      (X) % 1 == 0 &&
      (A) % 1 == 0 &&
      (B) % 1 == 0);
  ensures \result >= 0 && \result <= X;
  ensures \result == X - A || \result == B;
*/
int func(int X, int A, int B)
{
    int ans;
    
    ans = X - A;
    
    //@ assert ans == X - A;
    
    if (ans < B)
    {
        ans = B;
        //@ assert ans == B;
    }
    
    //@ assert ans == X - A || ans == B;
    
    return ans;
}
