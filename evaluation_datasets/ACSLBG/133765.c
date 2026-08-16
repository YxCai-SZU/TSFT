#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5(integer n, int *f) =
       \forall integer i; 0 <= i < n ==> 
           (f[i] % 2 == 0 ==> f[i] % 3 == 0 || f[i] % 5 == 0);
 */

/*@ predicate valid_params(integer n, int *f) =
       n > 0 && n <= 100 &&
       \valid(f + (0 .. n-1)) &&
       \forall integer i; 0 <= i < n ==> f[i] > 0 && f[i] <= 1000;
 */

/*@ lemma even_divisible_lemma:
       \forall integer x; x > 0 && x <= 1000 && x % 2 == 0 ==>
           (x % 3 == 0 || x % 5 == 0) ==>
           \true;
 */


bool func(size_t n, int *f)
{
    size_t i = 0;
    
    
    while (i < n)
    {
        int value = f[i];
        
        if (value % 2 == 0)
        {
            if (value % 3 != 0 && value % 5 != 0)
            {
                //@ assert !(value % 3 == 0 || value % 5 == 0);
                return false;
            }
        }
        i++;
    }
    //@ assert \forall integer j; 0 <= j < n ==> (f[j] % 2 == 0 ==> f[j] % 3 == 0 || f[j] % 5 == 0);
    return true;
}
