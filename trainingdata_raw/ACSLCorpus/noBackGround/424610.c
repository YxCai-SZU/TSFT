#include <stdint.h>

/*@
    requires (1 <= (n) <= 10);
    ensures \result == ((n) + (n)*(n) + (n)*(n)*(n));
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (n) <= 10);
    //@ assert ((n) + (n)*(n) + (n)*(n)*(n)) <= 10 + 10*10 + 10*10*10;
    
    result = n + n*n + n*n*n;
    
    //@ assert result == ((n) + (n)*(n) + (n)*(n)*(n));
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Variable declarations at top of scope
    int32_t test_cases[10][2] = {
        {1, 3},
        {2, 18},
        {3, 45},
        {4, 100},
        {5, 225},
        {6, 378},
        {7, 576},
        {8, 856},
        {9, 1260},
        {10, 1815}
    };
    int32_t i;
    int32_t input;
    int32_t expected;
    int32_t output;
    
    //@ loop invariant 0 <= i <= 10;
    //@ loop invariant \forall integer j; 0 <= j < i ==> func(test_cases[j][0]) == test_cases[j][1];
    //@ loop assigns i, input, expected, output;
    for (i = 0; i < 10; i++)
    {
        input = test_cases[i][0];
        expected = test_cases[i][1];
        output = func(input);
        assert(output == expected);
    }
    
    return 0;
}
#endif
