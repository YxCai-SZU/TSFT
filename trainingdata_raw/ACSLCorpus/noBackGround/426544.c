#include <stdint.h>

/*@
  requires (1 <= (N) && (N) <= 100000 &&
      1 <= (K) && (K) <= (N));
  ensures \result >= 0 && \result <= N;
*/
int64_t func(int64_t N, int64_t K)
{
    int64_t result = 0;
    int64_t x = 1;
    
    //@ assert (1 <= (N) && (N) <= 100000 &&       1 <= (K) && (K) <= (N) &&       1 <= (x) && (x) <= (N) + 1 &&       (result) >= 0 &&       (result) <= (x) - 1 &&       (x) - 1 <= (N));
    
    /*@ loop invariant (1 <= (N) && (N) <= 100000 &&
      1 <= (K) && (K) <= (N) &&
      1 <= (x) && (x) <= (N) + 1 &&
      (result) >= 0 &&
      (result) <= (x) - 1 &&
      (x) - 1 <= (N));
        loop assigns result, x;
        loop variant ((N) - (x) + 1);
    */
    while (x <= N)
    {
        int64_t remainder = x;
        
        //@ assert (1 <= (N) && (N) <= 100000 &&       1 <= (K) && (K) <= (N) &&       1 <= (x) && (x) <= (N) + 1 &&       (remainder) >= 0 &&       (remainder) <= (x) &&       (x) - 1 <= (N) &&       0 <= (remainder) && (remainder) < (K) + (x));
        
        /*@ loop invariant (1 <= (N) && (N) <= 100000 &&
      1 <= (K) && (K) <= (N) &&
      1 <= (x) && (x) <= (N) + 1 &&
      (remainder) >= 0 &&
      (remainder) <= (x) &&
      (x) - 1 <= (N) &&
      0 <= (remainder) && (remainder) < (K) + (x));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= K)
        {
            remainder -= K;
            //@ assert (1 <= (N) && (N) <= 100000 &&       1 <= (K) && (K) <= (N) &&       1 <= (x) && (x) <= (N) + 1 &&       (remainder) >= 0 &&       (remainder) <= (x) &&       (x) - 1 <= (N) &&       0 <= (remainder) && (remainder) < (K) + (x));
        }
        
        int64_t modulo_result = remainder;
        
        if (modulo_result == 0)
        {
            result += 1;
        }
        
        x += 1;
        //@ assert (1 <= (N) && (N) <= 100000 &&       1 <= (K) && (K) <= (N) &&       1 <= (x) && (x) <= (N) + 1 &&       (result) >= 0 &&       (result) <= (x) - 1 &&       (x) - 1 <= (N));
    }
    
    //@ assert result <= N;
    return result;
}
