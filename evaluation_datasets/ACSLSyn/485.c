#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ===== Original Functions (adapted with ACSL specs) ===== */

/*@
    predicate hash_map_old(integer k1, integer v1, integer k2, integer v2) =
        k1 == 3 && v1 == 4 && k2 == 6 && v2 == 8;
    
    predicate hash_map_new(integer k, integer v) =
        k == 3 && v == 4;
*/

void func_remove_key(uint32_t* a) {
    uint32_t key_to_remove = 6;
    bool removed = false;
    
    //@ assert hash_map_old(3, 4, 6, 8);
    
    //@ assert hash_map_new(3, 4);
}

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer division_ceil(integer n) =
        n % 8 == 0 ? n / 8 : n / 8 + 1;

    lemma ceil_properties:
        \forall integer n; valid_n(n) ==>
            division_ceil(n) >= 1 &&
            division_ceil(n) * 8 >= n &&
            (division_ceil(n) - 1) * 8 < n;
*/

size_t func_ceil_div_8(size_t n)
{
    size_t ans;
    size_t temp_n;
    size_t count;

    ans = 0;
    temp_n = n;
    count = 0;

    while (temp_n >= 8)
    {
        //@ assert temp_n >= 8;
        temp_n = temp_n - 8;
        count = count + 1;
        //@ assert temp_n == n - 8 * count;
    }

    if (temp_n > 0)
    {
        ans = count + 1;
        //@ assert ans == division_ceil(n);
    }
    else
    {
        ans = count;
        //@ assert ans == division_ceil(n);
    }

    //@ assert ans >= 1;
    //@ assert ans * 8 >= n;
    //@ assert (ans - 1) * 8 < n;
    return ans;
}

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer speed, time;
        1 <= speed <= 10000 && 1 <= time <= 10000 ==>
        1 <= safe_product(speed, time) <= 10000 * 10000;
*/

bool func_can_reach(unsigned int d, unsigned int t, unsigned int s)
{
    long long dist;
    long long time;
    long long speed;
    long long product;
    bool result;

    dist = (long long)d;
    time = (long long)t;
    speed = (long long)s;

    //@ assert 1 <= dist && dist <= 10000;
    //@ assert 1 <= time && time <= 10000;
    //@ assert 1 <= speed && speed <= 10000;

    //@ assert 1 <= speed * time && speed * time <= 10000 * 10000;
    product = speed * time;

    //@ assert product == safe_product(speed, time);
    result = (product >= dist);
    return result;
}

/*@ predicate all_even_divisible_by_3_or_5{L}(size_t *v, size_t len) =
      \forall size_t x; 0 <= x < len ==> 
        (v[x] % 2 == 0 ==> (v[x] % 3 == 0 || v[x] % 5 == 0));
 */

bool func_check_even_divisible(size_t *v, size_t len) {
    size_t index;
    index = 0;
    
    while (index < len) {
        size_t value;
        value = v[index];
        
        //@ assert value >= 1 && value <= 1000;
        
        if (value % 2 == 0 && !(value % 3 == 0 || value % 5 == 0)) {
            return false;
        }
        index += 1;
    }
    return true;
}

/* ===== Synthesized Complex Function ===== */

size_t process_data_packets(
    uint32_t* a,
    size_t n,
    unsigned int d,
    unsigned int t,
    unsigned int s,
    size_t* v,
    size_t len
) {
    func_remove_key(a);
    //@ assert hash_map_new(3, 4);
    
    size_t num_chunks = func_ceil_div_8(n);
    //@ assert num_chunks >= 1;
    //@ assert num_chunks * 8 >= n;
    //@ assert (num_chunks - 1) * 8 < n;
    
    bool can_reach = func_can_reach(d, t, s);
    
    bool data_valid = func_check_even_divisible(v, len);
    
    return num_chunks;
}
