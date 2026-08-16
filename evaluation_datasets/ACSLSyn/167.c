#include <stddef.h>

/*@ predicate arr_valid(size_t n, unsigned long *arr) =
      n > 0 &&
      \forall integer i; 0 <= i < n ==> 0 < arr[i] && arr[i] <= 1000000000;
*/

/*@ predicate count_in_range(size_t n, size_t i, size_t count) =
      0 <= i <= n && 0 <= count <= i;
*/

size_t count_multiples(size_t n, size_t k, unsigned long *arr) {
    size_t count = 0;
    size_t i = 0;

    while (i < n) {
        //@ assert arr_valid(n, arr);
        if (arr[i] % k == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

/*@
    predicate in_range(integer n) = 1 <= n && n <= 100;
    
    logic integer func_spec(integer n) = n * 800 - (n / 15) * 200;
    
    lemma no_overflow1: \forall integer n; in_range(n) ==> 800 * n <= 800 * 100;
    lemma no_overflow2: \forall integer n; in_range(n) ==> (n / 15) * 200 <= 100 * 200;
    lemma non_negative: \forall integer n; in_range(n) ==> 800 * n >= (n / 15) * 200;
*/

int calculate_discount(unsigned int n) {
    unsigned int x;
    
    //@ assert in_range(n);
    
    //@ assert 800 * n <= 800 * 100;
    //@ assert (n / 15) * 200 <= 100 * 200;
    //@ assert 800 * n >= (n / 15) * 200;
    
    x = n * 800 - (n / 15) * 200;
    return (int)x;
}

int process_pricing_data(size_t n, size_t k, unsigned long *arr) {
    size_t eligible_count = count_multiples(n, k, arr);
    
    //@ assert eligible_count <= n;
    
    //@ assert eligible_count >= 0;
    
    int total_discount;
    if (eligible_count > 0 && eligible_count <= 100) {
        total_discount = calculate_discount((unsigned int)eligible_count);
    } else {
        total_discount = 0;
    }
    
    //@ assert (eligible_count > 0 && eligible_count <= 100) ==> (total_discount == func_spec((unsigned int)eligible_count));
    //@ assert (eligible_count == 0 || eligible_count > 100) ==> total_discount == 0;
    
    //@ assert total_discount >= 0 && total_discount <= 80000;
    
    return total_discount;
}
