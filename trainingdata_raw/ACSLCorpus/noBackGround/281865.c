#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (b) == (c)) ==> \result == 1;
    ensures (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c))) ==> \result == 2;
    ensures ((a) != (b) && (b) != (c) && (a) != (c)) ==> \result == 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result = 0;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == 1;
    }
    else if (a != b && b != c && a != c)
    {
        result = 3;
        //@ assert result == 3;
    }
    else
    {
        result = 2;
        //@ assert result == 2;
    }

    return result;
}

/* Test functions (not for verification) */
#ifdef TESTING
#include <assert.h>

void test_eq(void)
{
    int a = 1;
    int b = 1;
    int c = 1;
    assert(func(a, b, c) == 1);
}

void test_diff(void)
{
    int a = 1;
    int b = 2;
    int c = 3;
    assert(func(a, b, c) == 3);
}

void test_one_two(void)
{
    int a = 1;
    int b = 1;
    int c = 2;
    assert(func(a, b, c) == 2);
}

int main(void)
{
    test_eq();
    test_diff();
    test_one_two();
    return 0;
}
#endif
