#include <limits.h>

/*@
    predicate is_above_min(integer i) = i > INT_MIN;
    predicate is_above_min_plus_one(integer i) = i > INT_MIN + 1;
*/

/*@
    requires is_above_min(i);
    ensures \result == i - 1;
    assigns \nothing;
*/
int subtract_one(int i)
{
    return i - 1;
}

/*@
    requires is_above_min_plus_one(i);
    ensures \result == i - 2;
    assigns \nothing;
*/
int subtract_two(int i)
{
    return i - 2;
}

/*@
    assigns \nothing;
*/
void print_result(int i)
{
    // External implementation
}

int main()
{
    int n1;
    int n2;
    int n3;
    int n4;

    n1 = subtract_one(100);
    //@ assert n1 == 99;

    n2 = subtract_two(100);
    //@ assert n2 == 98;

    n3 = subtract_one(n2);
    //@ assert n3 == 97;

    n4 = subtract_two(n3);
    //@ assert n4 == 95;

    print_result(n4);
    return 0;
}
