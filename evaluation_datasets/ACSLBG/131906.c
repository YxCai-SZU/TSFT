#include <stdbool.h>

/*@ predicate contains_spec(int *lst, integer len, int target, bool ret) =
      ret ==>
        (\exists integer i; 0 <= i < len && lst[i] == target) &&
      !ret ==>
        (\forall integer i; 0 <= i < len ==> lst[i] != target);
*/


bool contains(const int *lst, int len, int target)
{
    int i = 0;
    
    while (i < len)
    {
        if (lst[i] == target)
        {
            //@ assert \exists integer j; 0 <= j < len && lst[j] == target;
            return true;
        }
        i = i + 1;
        //@ assert \forall integer j; 0 <= j < i ==> lst[j] != target;
    }
    //@ assert \forall integer j; 0 <= j < len ==> lst[j] != target;
    return false;
}
