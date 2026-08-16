#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 7;

    logic integer func_res(integer a, integer b, integer c, integer k) =
        (a < b && b < c) && (1 <= k <= 7) ? 1 : 0;

    lemma ans_one_implies_ordered:
        \forall integer a, b, c, k;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k) &&
            func_res(a, b, c, k) == 1 ==> a < b && b < c;

    lemma ans_zero_implies_condition:
        \forall integer a, b, c, k;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k) &&
            func_res(a, b, c, k) == 0 ==> !(a < b && b < c) || k < 1 || k > 7;
*/

int func(int a, int b, int c, int k)
{
    int ans = 1;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k);

    if (!(a < b && b < c))
    {
        ans = 0;
    }

    //@ assert ans == 0 ==> !(a < b && b < c);

    if (k < 1 || k > 7)
    {
        ans = 0;
    }

    //@ assert ans == 0 ==> !(a < b && b < c) || k < 1 || k > 7;
    //@ assert ans == 1 ==> a < b && b < c;

    return ans;
}

/*@ predicate valid_range(int* arr, integer len) =
      \forall integer i; 0 <= i < len ==> 0 <= arr[i] <= 100;
*/

bool test(int* arr, size_t len) {
    size_t i = 0;
    bool result = false;
    
    if (len == 0) {
        result = true;
        return result;
    }
    
    while (i < len) {
        //@ assert 0 <= arr[i] <= 100;
        i++;
    }
    
    result = true;
    return result;
}

int score_sequence_validator(int* arr, size_t len) {
    bool valid = test(arr, len);
    //@ assert valid == (len == 0 || len > 0);
    
    int result = 0;
    
    if (valid && len >= 3) {
        int a = arr[0];
        int b = arr[1];
        int c = arr[2];
        int k = arr[2];
        
        //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k);
        
        int func_result = func(a, b, c, k);
        //@ assert func_result == 1 ==> a < b && b < c;
        //@ assert func_result == 0 ==> !(a < b && b < c) || k < 1 || k > 7;
        
        if (func_result == 1) {
            result = 1;
        }
    }
    
    //@ assert result == 1 ==> (len >= 3 && arr[0] < arr[1] && arr[1] < arr[2] && 1 <= arr[2] <= 7);
    
    return result;
}
