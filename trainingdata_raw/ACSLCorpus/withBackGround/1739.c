#include <limits.h>

/*@
    predicate is_valid_input(integer no) = no == 0 || no == 1;

    logic integer func_spec(integer no) =
        no == 0 ? 1 :
        no == 1 ? 0 :
        0;
*/

/*@
    requires is_valid_input(no);
    ensures \result == func_spec(no);
    assigns \nothing;
*/
int func(int no)
{
    int ret;

    //@ assert is_valid_input(no);
    if (no == 0) {
        //@ assert no == 0;
        ret = 1;
    } else if (no == 1) {
        //@ assert no == 1;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}
