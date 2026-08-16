#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* ====== Original functions with their specifications ====== */

/* First code snippet */
/*@
    predicate is_odd(integer n) = (n % 2) != 0;
*/

unsigned int func1(unsigned int r)
{
    unsigned int pi;
    unsigned int ans;
    
    pi = 3;
    
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    ans = pi * r * r;
    return ans;
}

bool is_odd_func(unsigned int n)
{
    bool ret;
    
    ret = (n % 2) != 0;
    return ret;
}

/* Second code snippet */
/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 100000;

    logic integer sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_bounds: \forall integer a, b, c;
        is_valid_params(a, b, c) ==> 3 <= sum(a, b, c) && sum(a, b, c) <= 150000;
*/

bool func2(int a, int b, int c)
{
    int sum_ab;
    int total;
    bool result;

    sum_ab = a + b;
    total = sum_ab + c;

    //@ assert sum_ab == a + b;
    //@ assert total == a + b + c;

    if (c < sum_ab)
    {
        result = false;
        //@ assert !(c >= a + b);
        return result;
    }

    //@ assert c >= a + b;
    result = total <= 10000;
    //@ assert result == (c >= a + b && a + b + c <= 10000);
    return result;
}

/* Third code snippet */
/*@ predicate valid_vector(integer n, int *v) =
      n > 0 && n <= 100000 &&
      \forall integer i; 0 <= i < n ==> v[i] > 0 && v[i] <= 1000000000;
*/



/*@ lemma count_bounds: \forall integer n, count; 0 <= count <= n ==> count >= 0 && count <= n; */

size_t func3(size_t n, int *v) {
    size_t count = 0;
    size_t w = 0;
    
    while (w < n) {
        int x = v[w];
        
        if (w > 0) {
            size_t i = 0;
            
            while (i < w) {
                //@ assert 0 <= i < n;
                if (v[i] > x) {
                    x = v[i];
                }
                i++;
            }
        }
        
        if (x == v[w]) {
            count++;
        }
        
        w++;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}

/* Fourth code snippet */
/*@
    predicate bounds(integer x) = 1 <= x <= 10;

    lemma mul_nonlinear:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> x * y <= 100;

    lemma mul_nonlinear_triple:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) && x * y <= 100 ==> x * y * z <= 1000;

    lemma mul_nonlinear_distributive_left:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> x * (y + z) <= 200;

    lemma mul_nonlinear_distributive_right:
        \forall integer x, y, z;
            bounds(x) && bounds(y) && bounds(z) ==> x * y + x * z <= 200;
*/

int verify_mul_nonlinear(uint32_t x, uint32_t y, uint32_t z)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    
    //@ assert x * y <= 100;
    //@ assert x * y * z <= 1000;
    
    return 1;
}

int verify_mul_nonlinear_distributive(uint32_t x, uint32_t y, uint32_t z)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    
    //@ assert x * (y + z) <= 200;
    //@ assert x * y + x * z <= 200;
    
    return 1;
}

/* ====== Synthesized complex function ====== */

/*@
    predicate data_item_valid(integer value) = 
        1 <= value <= 10;
    
    predicate buffer_valid(integer n, int *buf) =
        n > 0 && n <= 100 && 
        \valid(buf + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> data_item_valid(buf[i]);
    
    predicate processing_result(integer count, integer total_sum, integer buffer_size) =
        0 <= count <= buffer_size &&
        total_sum == 3 * buffer_size * buffer_size;
*/

int process_dataflow(
    size_t n,
    int *buffer,
    int *area,
    uint32_t *params,
    size_t *count_out,
    unsigned int *sum_out
)
{
    size_t count = func3(n, buffer);
    
    bool area_valid = func2(area[0], area[1], area[2]);
    
    unsigned int sum = func1((unsigned int)n);
    
    int verify_result = verify_mul_nonlinear(params[0], params[1], params[2]);
    
    //@ assert 0 <= count <= n;
    //@ assert sum == 3 * n * n;
    //@ assert verify_result == 1;
    
    *count_out = count;
    *sum_out = sum;
    
    //@ assert processing_result(count, sum, n);
    
    return 1;
}

int main()
{
    int buffer[5] = {3, 5, 2, 7, 1};
    int area[3] = {10, 20, 30};
    uint32_t params[3] = {3, 4, 5};
    size_t count_result;
    unsigned int sum_result;
    
    int ret = process_dataflow(5, buffer, area, params, &count_result, &sum_result);
    
    return ret;
}
