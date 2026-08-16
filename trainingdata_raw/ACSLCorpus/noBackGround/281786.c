#include <stdint.h>

/*@
    requires ((h1) >= 0 && (m1) >= 0 && (h1) < 24 && (m1) < 60) && ((h2) >= 0 && (m2) >= 0 && (h2) < 24 && (m2) < 60);
    requires k >= 0;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t start;
    int64_t end;
    int64_t result;

    //@ assert ((h1) >= 0 && (m1) >= 0 && (h1) < 24 && (m1) < 60) && ((h2) >= 0 && (m2) >= 0 && (h2) < 24 && (m2) < 60);
    //@ assert ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    
    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    
    //@ assert end >= start;
    //@ assert end - start <= 24 * 60;
    
    result = end - start - k;
    
    //@ assert result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    return result;
}

int main()
{
    return 0;
}
