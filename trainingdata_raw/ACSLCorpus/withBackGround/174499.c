#include <stdbool.h>

/*@
    predicate valid_polygon(integer n) = n >= 3 && n <= 100;
    
    logic integer sum_interior_angles_formula(integer n) = 180 * n - 360;
*/

/*@
    requires valid_polygon(n);
    ensures \result == sum_interior_angles_formula(n);
    assigns \nothing;
*/
int sum_interior_angles(int n)
{
    //@ assert valid_polygon(n);
    int ret = 180 * n - 360;
    //@ assert ret == sum_interior_angles_formula(n);
    return ret;
}

int main()
{
    return 0;
}
