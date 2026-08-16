#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer calculate_result(integer r) = (2 * r * 3142) / 1000;

    lemma division_property:
        \forall integer r, temp, count;
        valid_range(r) && temp >= 0 && count * 1000 + temp == r * 2 * 3142 ==>
        count <= calculate_result(r);
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3142;
    int result = 0;
    int temp = r * 2 * pi;
    int count = 0;

    //@ assert valid_range(r);
    //@ assert pi == 3142;
    //@ assert temp >= 0;
    //@ assert count * 1000 + temp == r * 2 * pi;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant temp >= 0;
        loop invariant count * 1000 + temp == r * 2 * pi;
        loop invariant count >= 0;
        loop invariant count <= calculate_result(r);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
        //@ assert count * 1000 + temp == r * 2 * pi;
    }

    result = count;
    //@ assert result == calculate_result(r);
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
