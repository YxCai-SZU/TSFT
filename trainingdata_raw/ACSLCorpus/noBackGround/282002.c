#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        0 <= (A) && (A) <= (N) * (N));
    ensures \result == ((N) * (N) - (A));
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A)
{
    //@ assert (1 <= (N) && (N) <= 100 &&         0 <= (A) && (A) <= (N) * (N));
    uint32_t result;
    //@ ghost uint32_t n_sq = N * N;
    
    //@ assert n_sq <= 10000;
    result = N * N - A;
    
    //@ assert result == ((N) * (N) - (A));
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    uint32_t res1 = func(5, 3);
    //@ assert res1 == 22;
    assert(res1 == 22);
    
    uint32_t res2 = func(10, 0);
    //@ assert res2 == 100;
    assert(res2 == 100);
    
    uint32_t res3 = func(1, 1);
    //@ assert res3 == 0;
    assert(res3 == 0);
    
    uint32_t res4 = func(100, 99);
    //@ assert res4 == 99;
    assert(res4 == 99);
    
    return 0;
}
#endif
