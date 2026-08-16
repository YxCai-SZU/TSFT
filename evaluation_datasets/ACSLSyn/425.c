#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/* ========== Original Functions (adapted for scenario) ========== */

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/
unsigned int func_max_code(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max_ab;
    unsigned int max_bc;
    unsigned int max_ac;
    unsigned int max;
    unsigned int max_final;
    unsigned int result;

    max_ab = (a > b) ? a : b;
    max_bc = (b > c) ? b : c;
    max_ac = (a > c) ? a : c;
    max = (max_ab > max_bc) ? max_ab : max_bc;
    max_final = (max > max_ac) ? max : max_ac;

    if (max_final == a)
    {
        if (b == c)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        if (max_final == b)
        {
            if (a == c)
            {
                result = 1;
            }
            else
            {
                result = 2;
            }
        }
        else
        {
            if (a == b)
            {
                result = 1;
            }
            else
            {
                result = 2;
            }
        }
    }

    return result;
}

int func_compare(unsigned int n, unsigned int m, bool *result) {
    bool tmp_result;
    
    tmp_result = (n == m);
    
    *result = tmp_result;
    return 0;
}

/*@ predicate is_valid_array(int64_t* a, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
*/
int32_t func_check_array(int64_t n, int64_t* a) {
    int32_t count;
    int64_t index;
    int64_t half_n;
    int32_t result;

    count = 0;
    index = 0;

    while (index < n) {
        if ((a[index] & 1) == 1) {
            return -1;
        }
        index += 1;
        count += 1;
    }

    half_n = (n + 1) / 2;
    
    if (count > half_n) {
        result = count;
    } else {
        result = -1;
    }

    return result;
}

/*@
    predicate is_multiple_of_200(integer x) = x % 200 == 0;
    predicate is_not_multiple_of_200(integer x) = x % 200 != 0;
*/
int32_t func_check_multiple(uint32_t x) {
    int32_t result;
    uint32_t i;

    if (x % 200 == 0) {
        i = 0;
        while (i < 200) {
            i++;
        }
        result = 1;
    } else {
        i = 0;
        while (i < 1000) {
            i++;
        }
        result = 0;
    }
    return result;
}

/* ========== Synthesized Function ========== */


int32_t process_batch(int64_t n, int64_t* a, unsigned int id1, unsigned int id2, unsigned int id3, unsigned int threshold) {
    int32_t array_status;
    bool ids_equal;
    unsigned int max_code;
    int32_t threshold_flag;
    int32_t final_result;
    
    array_status = func_check_array(n, a);
    
    //@ assert 1 <= id1 <= 100 && 1 <= id2 <= 100;
    if (id1 >= id2) {
        func_compare(id1, id2, &ids_equal);
    } else {
        func_compare(id2, id1, &ids_equal);
    }
    
    //@ assert valid_range(id1) && valid_range(id2) && valid_range(id3);
    max_code = func_max_code(id1, id2, id3);
    
    //@ assert 1 <= threshold <= 100000;
    threshold_flag = func_check_multiple(threshold);
    
    if (array_status == -1) {
        final_result = -1;
    } else if (ids_equal && threshold_flag == 1) {
        final_result = max_code;
    } else {
        final_result = 0;
    }
    
    //@ assert final_result == -1 || (final_result >= 0 && final_result <= 3);
    
    return final_result;
}
