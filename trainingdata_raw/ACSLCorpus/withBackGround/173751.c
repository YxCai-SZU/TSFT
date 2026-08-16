#include <limits.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 9;
*/

/*@
    requires in_range(x);
    requires in_range(a);
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
    assigns \nothing;
*/
int func(int x, int a)
{
    // Variable declarations at top of scope
    int result;

    if (x < a) {
        result = 0;
    } else {
        //@ assert x >= a;
        //@ assert 10 <= 10 && 10 >= 10;
        result = 10;
    }

    return result;
}

#ifdef TESTING
#include <assert.h>

int main() {
    // Test case 1
    int result1 = func(5, 8);
    //@ assert result1 == 0;
    assert(result1 == 0);

    // Test case 2
    int result2 = func(9, 5);
    //@ assert result2 == 10;
    assert(result2 == 10);

    // Test case 3
    int result3 = func(0, 0);
    //@ assert result3 == 10;
    assert(result3 == 10);

    // Test case 4
    int result4 = func(2, 2);
    //@ assert result4 == 10;
    assert(result4 == 10);

    // Test case 5
    int result5 = func(5, 5);
    //@ assert result5 == 10;
    assert(result5 == 10);

    return 0;
}
#endif
