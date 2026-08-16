#include <stdint.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n && n <= 100 && 0 <= r && r <= 4111;

    logic integer compute_ans(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_ans(n, r);
    ensures \result == r || \result == r + 100 * (10 - n);
*/
int64_t func(int64_t n, int64_t r)
{
    int64_t ans;
    //@ assert valid_params(n, r);
    
    if (n >= 10) {
        ans = r;
        //@ assert ans == r;
    } else {
        ans = r + 100 * (10 - n);
        //@ assert ans == r + 100 * (10 - n);
    }
    
    //@ assert ans == compute_ans(n, r);
    return ans;
}

/* Test functions */
#ifdef TESTING
#include <assert.h>

void test_input(void)
{
    int64_t n = 10;
    int64_t r = 1000;
    int64_t result = func(n, r);
    assert(result == 1000);
}

void test_input2(void)
{
    int64_t n = 8;
    int64_t r = 1000;
    int64_t result = func(n, r);
    assert(result == 1200);
}

void test_input3(void)
{
    int64_t n = 5;
    int64_t r = 500;
    int64_t result = func(n, r);
    assert(result == 1000);
}

void test_input4(void)
{
    int64_t n = 5;
    int64_t r = 0;
    int64_t result = func(n, r);
    assert(result == 500);
}

int main(void)
{
    test_input();
    test_input2();
    test_input3();
    test_input4();
    return 0;
}
#endif
