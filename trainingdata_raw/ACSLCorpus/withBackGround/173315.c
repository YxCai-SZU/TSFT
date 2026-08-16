#include <stdbool.h>

/*@ predicate valid_array(int *a, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] <= 13;
    predicate result_condition(int *a) =
        a[1] == a[0] + a[2] ||
        a[2] == a[1] + a[0] ||
        a[0] == a[1] + a[2];
*/

/*@
    requires valid_array(a, 3);
    ensures \result == 1 <==> result_condition(a);
    assigns \nothing;
*/
bool func(int *a)
{
    bool flag = false;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    //@ assert valid_array(a, 3);
    sum1 = a[0] + a[1];
    sum2 = a[1] + a[2];
    sum3 = a[0] + a[2];

    if (sum1 == a[2] || sum2 == a[0] || sum3 == a[1])
    {
        flag = true;
    }

    //@ assert flag == 1 <==> result_condition(a);
    return flag;
}
