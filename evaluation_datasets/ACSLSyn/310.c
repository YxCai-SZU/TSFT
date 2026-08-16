#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_greater_than_5(integer n) = n > 5; */
/*@ predicate valid_range(integer a) = 1 <= a && a <= 100; */
/*@ predicate valid_range_product(integer r) = 1 <= r && r <= 10000; */
/*@ predicate valid_range_wide(integer x) = 1 <= x <= 10000; */

/*@ logic integer multiply(integer a, integer b) = a * b; */
/*@ logic integer final_result(integer a, integer b, integer c, integer d) = a + b + c + d - b; */

/*@ lemma product_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> valid_range_product(multiply(a, b)); */

bool is_even_func(unsigned int n) {
    bool even;
    even = (n % 2 == 0);
    return even;
}

bool is_greater_than_5_func(unsigned int n) {
    bool gt_5;
    gt_5 = (n > 5);
    return gt_5;
}

int func(int a, int b)
{
    int result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range_product(a * b);
    result = a * b;
    return result;
}

int* procon_read(int* input, int len)
{
    return input;
}

int64_t func2(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t result = 0;
    //@ assert result == 0;
    
    result += a;
    //@ assert result == a;
    
    result += b;
    //@ assert result == a + b;
    
    result += c;
    //@ assert result == a + b + c;
    
    result += d;
    //@ assert result == a + b + c + d;
    
    result -= b;
    //@ assert result == a + b + c + d - b;
    
    return result;
}

int process_data(int* data, int len) {
    int* safe_data;
    int product;
    int64_t combined;
    bool even_check;
    bool gt_5_check;
    
    safe_data = procon_read(data, len);
    
    product = func(safe_data[0], safe_data[1]);
    //@ assert valid_range_product(product);
    
    combined = func2((int64_t)safe_data[0], (int64_t)safe_data[1], (int64_t)safe_data[2], (int64_t)safe_data[3]);
    //@ assert combined == final_result((int64_t)safe_data[0], (int64_t)safe_data[1], (int64_t)safe_data[2], (int64_t)safe_data[3]);
    
    even_check = is_even_func((unsigned int)product);
    gt_5_check = is_greater_than_5_func((unsigned int)product);
    
    //@ assert even_check == (product % 2 == 0);
    //@ assert gt_5_check == (product > 5);
    
    //@ assert (even_check && gt_5_check) ==> (combined > 0);
    
    return (even_check && gt_5_check) ? 1 : 0;
}
