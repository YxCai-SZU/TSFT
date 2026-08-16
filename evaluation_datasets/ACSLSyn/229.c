#include <stdint.h>

/*@ predicate base_constant(integer base) = base == 234; */
/*@ predicate valid_range(integer x) = 1 <= x && x <= 10; */
/*@ logic integer product(integer x, integer y) = x * y; */

uint32_t add(uint32_t x)
{
    uint32_t base = 234;
    //@ assert base == 234;
    uint32_t result = x + base;
    //@ assert result > x;
    return result;
}

int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int max_val;
    unsigned int ab_product;
    unsigned int cd_product;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert product(a, b) <= 100;
    //@ assert product(c, d) <= 100;
    
    ab_product = a * b;
    cd_product = c * d;
    
    if (ab_product > cd_product) {
        max_val = ab_product;
        //@ assert max_val == product(a, b);
        //@ assert max_val >= product(c, d);
    } else {
        max_val = cd_product;
        //@ assert max_val == product(c, d);
        //@ assert max_val >= product(a, b);
    }
    
    //@ assert max_val == product(a, b) || max_val == product(c, d);
    //@ assert max_val >= product(a, b) && max_val >= product(c, d);
    
    return (int)max_val;
}

uint32_t process_products(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    int max_product;
    uint32_t result;
    
    max_product = func(a, b, c, d);
    
    //@ assert max_product == product(a, b) || max_product == product(c, d);
    //@ assert max_product >= product(a, b) && max_product >= product(c, d);
    
    result = add((uint32_t)max_product);
    
    //@ assert result > (uint32_t)max_product;
    //@ assert result > (uint32_t)product(a, b) && result > (uint32_t)product(c, d);
    
    return result;
}

int main()
{
    uint32_t final_result;
    final_result = process_products(2, 3, 4, 5);
    //@ assert final_result > 20;
    return 0;
}
