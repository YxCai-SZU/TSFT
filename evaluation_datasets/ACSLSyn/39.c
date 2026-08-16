#include <stdbool.h>
#include <limits.h>

/*@ predicate is_increasing(integer a, integer b, integer c) = 
      a < b && b < c;
*/

bool is_increasing_sequence(int *arr) {
    bool result;
    //@ assert arr[0] >= 1 && arr[0] <= 9;
    //@ assert arr[1] >= 1 && arr[1] <= 9;
    //@ assert arr[2] >= 1 && arr[2] <= 9;
    if (arr[0] < arr[1] && arr[1] < arr[2]) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == true <==> is_increasing(arr[0], arr[1], arr[2]);
    return result;
}

bool check_long_long_ordering(long long a, long long b, long long c)
{
    int state = 0;
    /*@ assert state == 0; */
    
    if (a < b)
    {
        state += 1;
    }
    
    if (b < c)
    {
        state += 2;
    }
    
    /*@ assert state == 3 <==> (a < b && b < c); */
    
    if (state == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate_sequence_ordering(int A, int B, int C) {
    int arr[3];
    arr[0] = A;
    arr[1] = B;
    arr[2] = C;
    
    //@ assert arr[0] >= 1 && arr[0] <= 9;
    //@ assert arr[1] >= 1 && arr[1] <= 9;
    //@ assert arr[2] >= 1 && arr[2] <= 9;
    
    bool int_result = is_increasing_sequence(arr);
    
    long long a = (long long)A;
    long long b = (long long)B;
    long long c = (long long)C;
    
    bool long_result = check_long_long_ordering(a, b, c);
    
    //@ assert int_result == long_result;
    
    return int_result;
}
