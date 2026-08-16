#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    logic integer quotient_relation(integer n, integer q) = n - q * 15;
    logic integer final_result(integer n) = n * 800 - (n / 15) * 200;
*/

int discount_calc(unsigned int n)
{
    int x;
    int res;
    unsigned int quotient;
    unsigned int remainder;

    x = 800 * (int)n;
    res = x;
    quotient = 0;
    remainder = n;

    while (remainder >= 15)
    {
        quotient = quotient + 1;
        remainder = remainder - 15;
    }

    res = res - ((int)quotient * 200);

    return res;
}

/*@ predicate seq_len(int *arr, integer len) = \valid(arr+(0..len-1)); */
/*@ predicate seq_eq(int *arr, integer len, integer idx, integer val) = (0 <= idx < len) ==> arr[idx] == val; */

int multiply(int a, int b)
{
    return a * b;
}

void init_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = 10 * i;
    }
}

typedef enum {
    TABLE,
    CHAIR,
    BED
} FurnitureTag;

typedef struct {
    FurnitureTag tag;
    union {
        unsigned int width;
        unsigned int height;
        unsigned int length;
    };
} Furniture;

/*@ predicate is_large_table(Furniture e) = 
      e.tag == TABLE && e.width > 100; */

/*@ logic integer furniture_dimension(Furniture e) =
      e.tag == TABLE ? e.width :
      e.tag == CHAIR ? e.height :
      e.length; */

/*@ lemma dimension_equality:
      \forall Furniture e1, Furniture e2, Furniture e3;
        furniture_dimension(e1) == furniture_dimension(e2) &&
        furniture_dimension(e2) == furniture_dimension(e3) ==>
        furniture_dimension(e1) == furniture_dimension(e3); */

bool all_furniture_sizes(Furniture e1, Furniture e2, Furniture e3) {
    return true;
}

int process_order(unsigned int n, int *arr, int len, Furniture e1, Furniture e2, Furniture e3)
{
    int price = discount_calc(n);
    
    init_array(arr, len);
    
    bool consistent = all_furniture_sizes(e1, e2, e3);
    
    return price;
}
