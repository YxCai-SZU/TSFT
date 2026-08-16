#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_params(integer N, integer A, integer B) =
      3 <= N && N <= 10000 &&
      1 <= A && A < 10000 &&
      1 <= B && B < 10000;
*/

/*@ predicate valid_array(integer N, int *arr) =
      \valid(arr + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> 1 <= arr[i] && arr[i] <= 10000;
*/

/*@ predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
*/

/*@ lemma ans_bounds:
      \forall integer index, integer ans;
      0 <= index && ans >= 0 && ans <= index ==> ans >= 0;
*/

/*@ lemma index_bounds:
      \forall integer index, integer N;
      0 <= index && index <= N ==> 0 <= index;
*/

int func(size_t N, size_t A, size_t B, int *arr) {
    int ans = 0;
    size_t index = 0;
    
    //@ assert valid_params(N, A, B);
    //@ assert valid_array(N, arr);
    
    while (index < N) {
        int i = arr[index];
        if (i <= (int)A) {
            ans += 1;
        } else if (i <= (int)B) {
            ans += 1;
        }
        index += 1;
    }
    
    if (ans == (int)N) {
        return 0;
    } else {
        index = 0;
        while (index < N) {
            int i = arr[index];
            if (i > (int)B) {
                //@ assert index + 1 <= N;
                return (int)(index + 1);
            }
            index += 1;
        }
    }
    return -1;
}

int invert_bit(int x)
{
    int result;
    //@ assert x == 0 || x == 1;
    
    if (x == 0) {
        result = 1;
        //@ assert x == 0 && result == 1;
    } else {
        result = 0;
        //@ assert x == 1 && result == 0;
    }
    
    return result;
}

/*@ predicate valid_bit_array(integer N, int *arr) =
      \valid(arr + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> (arr[i] == 0 || arr[i] == 1);
*/

int process_data_validation(size_t N, size_t A, size_t B, int *arr) {
    int result = func(N, A, B, arr);
    
    //@ assert result >= -1 && result <= (int)N;
    
    if (result == 0) {
        int bit_status = 0;
        size_t i = 0;
        
        while (i < N) {
            if (arr[i] <= (int)B) {
                bit_status = invert_bit(bit_status);
                //@ assert bit_status == 0 || bit_status == 1;
            }
            i++;
        }
        
        //@ assert bit_status == 0 || bit_status == 1;
        
        if (bit_status == 1) {
            return -1;
        }
        return 0;
    }
    
    return result;
}
