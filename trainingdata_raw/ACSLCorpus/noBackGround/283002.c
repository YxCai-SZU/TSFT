#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (m) && (m) <= 100);
  assigns \nothing;
  ensures \result <= n + m;
  ensures \result >= 0;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    if (n * 2 <= m)
    {
        //@ assert n + m / 4 <= n + m;
        result = n + m / 4;
    }
    else
    {
        //@ assert m / 2 <= n + m;
        result = m / 2;
    }
    
    return result;
}

int main()
{
    return 0;
}
