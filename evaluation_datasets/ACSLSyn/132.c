#include <stddef.h>
#include <stdint.h>

/*@
    predicate is_max(integer x, integer a, integer b, integer c) =
        (x == a || x == b || x == c) &&
        x >= a && x >= b && x >= c;
*/

/*@
    lemma max_property:
        \forall integer a, b, c, m;
            (m == a || m == b || m == c) &&
            m >= a && m >= b && m >= c ==>
            is_max(m, a, b, c);
*/

size_t longest_list_length(size_t list1_len, size_t list2_len, size_t list3_len) {
    size_t len1 = list1_len;
    size_t len2 = list2_len;
    size_t len3 = list3_len;
    size_t ret;

    if (len1 >= len2 && len1 >= len3) {
        //@ assert len1 >= len2 && len1 >= len3;
        ret = len1;
    } else if (len2 >= len1 && len2 >= len3) {
        //@ assert len2 >= len1 && len2 >= len3;
        ret = len2;
    } else {
        //@ assert len3 >= len1 && len3 >= len2;
        ret = len3;
    }

    //@ assert is_max(ret, len1, len2, len3);
    return ret;
}

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;
    
    logic integer half_plus_mod(integer n) = n / 2 + n % 2;
    
    lemma division_property: 
        \forall integer n; valid_range(n) ==> n == (n / 2) * 2 + n % 2;
*/

int func(int n)
{
    int result;
    int temp_n;
    int count;
    int modulus;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == n / 2;
    
    if (temp_n == 1)
    {
        modulus = 1;
    }
    else
    {
        modulus = 0;
    }
    
    //@ assert modulus == n % 2;
    
    result += modulus;
    
    //@ assert result == n / 2 + n % 2;
    
    return result;
}

/*@
    predicate valid_chunk_sizes(integer a, integer b, integer c) =
        valid_range(a) && valid_range(b) && valid_range(c);
    
    predicate balanced_chunk_processing(integer max_len, integer a, integer b, integer c) =
        is_max(max_len, a, b, c) && 
        max_len >= half_plus_mod(a) && 
        max_len >= half_plus_mod(b) && 
        max_len >= half_plus_mod(c);
*/

int process_chunks(int chunk1, int chunk2, int chunk3) {
    size_t max_chunk = longest_list_length((size_t)chunk1, (size_t)chunk2, (size_t)chunk3);
    
    int hpm1 = func(chunk1);
    int hpm2 = func(chunk2);
    int hpm3 = func(chunk3);
    
    int max_hpm;
    if (hpm1 >= hpm2 && hpm1 >= hpm3) {
        max_hpm = hpm1;
    } else if (hpm2 >= hpm1 && hpm2 >= hpm3) {
        max_hpm = hpm2;
    } else {
        max_hpm = hpm3;
    }
    
    //@ assert is_max((int)max_hpm, hpm1, hpm2, hpm3);
    //@ assert (int)max_chunk >= max_hpm;
    
    //@ assert balanced_chunk_processing((int)max_chunk, chunk1, chunk2, chunk3);
    return (int)max_chunk;
}
