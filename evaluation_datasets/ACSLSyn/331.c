#include <stdbool.h>
#include <stdint.h>

/* ============================================================
   Function 1: Check if three numbers can form a valid triangle
   ============================================================ */

/*@ predicate is_triangle(integer a, integer b, integer c) =
      a + b > c && a + c > b && b + c > a;
*/

bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sorted[3];
    unsigned int temp;

    if (a <= b && a <= c)
    {
        sorted[0] = a;
        if (b <= c)
        {
            sorted[1] = b;
            sorted[2] = c;
        }
        else
        {
            sorted[1] = c;
            sorted[2] = b;
        }
    }
    else if (b <= a && b <= c)
    {
        sorted[0] = b;
        if (a <= c)
        {
            sorted[1] = a;
            sorted[2] = c;
        }
        else
        {
            sorted[1] = c;
            sorted[2] = a;
        }
    }
    else
    {
        sorted[0] = c;
        if (a <= b)
        {
            sorted[1] = a;
            sorted[2] = b;
        }
        else
        {
            sorted[1] = b;
            sorted[2] = a;
        }
    }

    //@ assert sorted[0] <= sorted[1] && sorted[1] <= sorted[2];

    if (sorted[0] + sorted[1] > sorted[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* ============================================================
   Function 2: Compute count of valid positions in a range
   ============================================================ */

/*@ predicate valid_params(integer x, integer y, integer z) =
      1 <= x <= 100000 &&
      1 <= y <= 100000 &&
      1 <= z <= 100000 &&
      y + z <= x;
*/

/*@ lemma param_bounds:
      \forall integer x, y, z;
        valid_params(x, y, z) ==>
        x >= 1 && x <= 100000 &&
        y >= 1 && y <= 100000 &&
        z >= 1 && z <= 100000 &&
        y + z <= x;
*/

/*@ logic integer compute_n(integer x, integer z) = x - z; */

/*@ lemma n_nonnegative:
      \forall integer x, z;
        valid_params(x, 1, z) ==> compute_n(x, z) >= 0;
*/

int32_t func2(uint32_t x, uint32_t y, uint32_t z)
{
    int32_t n;
    int32_t result;
    uint32_t i;
    
    //@ assert x >= 1 && x <= 100000;
    //@ assert y >= 1 && y <= 100000;
    //@ assert z >= 1 && z <= 100000;
    //@ assert y + z <= x;
    
    n = (int32_t)x - (int32_t)z;
    //@ assert n == compute_n(x, z);
    
    result = 0;
    i = 0;
    
    while (i < y) {
        //@ assert i < y;
        if (i + z < x) {
            //@ assert i + z < x;
            result += 1;
        }
        i += 1;
    }
    
    //@ assert i == y;
    //@ assert result >= 0;
    //@ assert result <= x;
    return result;
}

/* ============================================================
   Function 3: Compute division by two (ceiling)
   ============================================================ */

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;
    logic integer target_value(integer n) = (n + 1) / 2;
    lemma division_property: \forall integer n; is_valid_range(n) ==> target_value(n) >= 0;
*/

int func3(int n)
{
    int result = 0;
    int temp_n = n + 1;
    
    while (temp_n > 1)
    {
        //@ assert temp_n > 1;
        result += 1;
        temp_n -= 2;
        //@ assert temp_n == n + 1 - 2 * result;
    }
    //@ assert temp_n <= 1;
    //@ assert result == target_value(n);
    return result;
}

/* ============================================================
   Synthesized Function: Triangle-based resource allocation
   ============================================================ */

int synthesized_func(unsigned int a, unsigned int b, unsigned int c)
{
    bool is_stable;
    int32_t alloc_count;
    int redundant_paths;
    
    is_stable = func1(a, b, c);
    
    if (is_stable) {
        //@ assert is_triangle(a, b, c);
        alloc_count = func2(a, b, c);
        //@ assert alloc_count >= 0 && alloc_count <= a;
    } else {
        alloc_count = 0;
    }
    
    redundant_paths = func3((int)b);
    //@ assert redundant_paths == target_value((int)b);
    
    int final_result = (int)alloc_count + redundant_paths;
    
    //@ assert final_result >= redundant_paths && final_result <= (int)a + redundant_paths;
    //@ assert final_result >= 0;
    
    return final_result;
}
