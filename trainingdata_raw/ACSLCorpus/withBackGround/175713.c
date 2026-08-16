#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_length(integer n) = 0 <= n <= 200000; */

/*@ predicate is_valid_array(int64_t* arr, integer len) = 
      \valid(arr + (0 .. len-1)); */

/*@ lemma ans_bounds: 
      \forall integer n, m, ans; 
      is_valid_length(n) && is_valid_length(m) && 
      0 <= ans <= m ==> 0 <= ans <= m; */

/*@ requires 
      is_valid_length(n) && 
      is_valid_length(m) && 
      is_valid_array(an, n) && 
      is_valid_array(bn, m); 
    ensures 
      0 <= \result <= m; 
*/
int64_t func(int64_t n, int64_t* an, int64_t m, int64_t* bn)
{
    int64_t ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= m;
        loop invariant 0 <= ans <= index;
        loop assigns ans, index; */
    while (index < (size_t)m) 
    {
        int64_t v = bn[index];
        bool found = false;
        size_t an_index = 0;
        
        /*@ loop invariant 0 <= an_index <= n;
            loop invariant found == false || 
              (\exists integer j; 0 <= j < an_index && an[j] == v);
            loop assigns found, an_index; */
        while (an_index < (size_t)n) 
        {
            if (an[an_index] == v) 
            {
                found = true;
                break;
            }
            an_index++;
        }
        
        if (found) 
        {
            ans++;
        }
        //@ assert 0 <= ans <= index + 1;
        index++;
    }
    //@ assert 0 <= ans <= m;
    return ans;
}
