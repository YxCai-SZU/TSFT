#include <limits.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    lemma square_bound: \forall integer n; is_valid_n(n) ==> square(n) <= 10000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    
    result = n * n;
    return result;
}

#ifdef TESTING
#include <assert.h>

void test_input_1(void)
{
    int expected = 1;
    int actual = func(1);
    assert(expected == actual);
}

void test_input_2(void)
{
    int expected = 4;
    int actual = func(2);
    assert(expected == actual);
}

void test_input_3(void)
{
    int expected = 9;
    int actual = func(3);
    assert(expected == actual);
}

void test_input_100(void)
{
    int expected = 10000;
    int actual = func(100);
    assert(expected == actual);
}

int main(void)
{
    test_input_1();
    test_input_2();
    test_input_3();
    test_input_100();
    return 0;
}
#endif
