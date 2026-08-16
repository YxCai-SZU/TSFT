#include <stdbool.h>

/* ========== First underlying function: range check ========== */
/*@ predicate is_valid_range(integer k, integer x) =
      1 <= k <= 100 && 1 <= x <= 100000;
*/
/*@ logic integer calculate_sum(integer k) = 500 * k; */
/*@ lemma sum_bounds: 
      \forall integer k; 1 <= k <= 100 ==> 
      500 <= calculate_sum(k) <= 50000;
*/
bool func1(int k, int x) {
    int sum;
    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    //@ assert 500 <= calculate_sum(k) <= 50000;
    sum = 500 * k;
    if (sum >= x) {
        //@ assert calculate_sum(k) >= x;
        return true;
    } else {
        //@ assert calculate_sum(k) < x;
        return false;
    }
}

/* ========== Second underlying function: condition check ========== */
/*@
    predicate in_range(integer x) = 0 <= x <= 100;
    predicate condition_holds(integer x, integer y) =
        y >= x * 2 && y <= x * 4 && y % 2 == 0;
    lemma mult_bound_2: \forall integer x; in_range(x) ==> x * 2 <= 200;
    lemma mult_bound_4: \forall integer x; in_range(x) ==> x * 4 <= 400;
*/
int func2(unsigned int x, unsigned int y) {
    unsigned int a;
    unsigned int b;
    int result;
    //@ assert 0 <= x <= 100;
    //@ assert 0 <= y <= 100;
    //@ assert x * 2 <= 200;
    //@ assert x * 4 <= 400;
    a = x * 2;
    b = x * 4;
    result = (y >= a && y <= b && y % 2 == 0);
    //@ assert result == (y >= x * 2 && y <= x * 4 && y % 2 == 0);
    return result;
}

/* ========== Third underlying function: parity check ========== */
/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        a >= 1 && a <= 10000 &&
        b >= 1 && b <= 10000 &&
        c >= 1 && c <= 10000 &&
        d >= 1 && d <= 10000;
    lemma product_bound: \forall integer a, b, c, d;
        bounds(a, b, c, d) ==> a * b <= 100000000 && c * d <= 100000000;
    lemma mod_preservation: \forall integer x;
        x >= 2 ==> (x - 2) % 2 == x % 2;
*/
bool func3(unsigned long long a, unsigned long long b,
           unsigned long long c, unsigned long long d) {
    unsigned long long product1;
    unsigned long long product2;
    bool is_even1;
    bool is_even2;
    unsigned long long temp1;
    unsigned long long temp2;
    //@ assert a * b <= 100000000;
    product1 = a * b;
    //@ assert c * d <= 100000000;
    product2 = c * d;
    is_even1 = false;
    temp1 = product1;
    while (temp1 >= 2) {
        //@ assert (temp1 - 2) % 2 == temp1 % 2;
        temp1 -= 2;
    }
    if (temp1 == 0) {
        is_even1 = true;
    }
    is_even2 = false;
    temp2 = product2;
    while (temp2 >= 2) {
        //@ assert (temp2 - 2) % 2 == temp2 % 2;
        temp2 -= 2;
    }
    if (temp2 == 0) {
        is_even2 = true;
    }
    //@ assert is_even1 == (product1 % 2 == 0);
    //@ assert is_even2 == (product2 % 2 == 0);
    return is_even1 || is_even2;
}

/* ========== Synthesized complex function: resource allocation validator ========== */
/* 
   Scenario: A resource allocation system validates a request.
   Data flow:
     - Input: request_id (1..100), amount (1..100000), 
               resource_type (0..100), resource_count (0..100),
               four resource block IDs (each 1..10000).
     - Step 1: func1 checks if the request amount is within the allowed sum for the given request_id.
     - Step 2: func2 checks if the resource_count satisfies the condition for the resource_type.
     - Step 3: func3 checks if at least one pair of resource block IDs has an even product.
     - Final decision: request is valid if all three checks pass.
*/

/*@ 
    predicate valid_request(integer request_id, integer amount,
                            integer resource_type, integer resource_count,
                            integer block1_a, integer block1_b,
                            integer block2_c, integer block2_d) =
        (calculate_sum(request_id) >= amount) &&
        (resource_count >= resource_type * 2 && 
         resource_count <= resource_type * 4 && 
         resource_count % 2 == 0) &&
        ((block1_a * block1_b) % 2 == 0 || (block2_c * block2_d) % 2 == 0);
*/

bool validate_resource_allocation(int request_id, int amount,
                                  unsigned int resource_type, unsigned int resource_count,
                                  unsigned long long block1_a, unsigned long long block1_b,
                                  unsigned long long block2_c, unsigned long long block2_d) {
    bool step1_result;
    int step2_result;
    bool step3_result;
    bool final_result;

    step1_result = func1(request_id, amount);
    //@ assert step1_result == (calculate_sum(request_id) >= amount);

    step2_result = func2(resource_type, resource_count);
    //@ assert step2_result == (resource_count >= resource_type * 2 && resource_count <= resource_type * 4 && resource_count % 2 == 0);

    step3_result = func3(block1_a, block1_b, block2_c, block2_d);
    //@ assert step3_result == ((block1_a * block1_b) % 2 == 0 || (block2_c * block2_d) % 2 == 0);

    final_result = step1_result && (step2_result != 0) && step3_result;

    //@ assert final_result <==> (calculate_sum(request_id) >= amount && (resource_count >= resource_type * 2 && resource_count <= resource_type * 4 && resource_count % 2 == 0) && ((block1_a * block1_b) % 2 == 0 || (block2_c * block2_d) % 2 == 0));
    //@ assert final_result <==> valid_request(request_id, amount, resource_type, resource_count, block1_a, block1_b, block2_c, block2_d);

    return final_result;
}

int main(void) {
    return 0;
}
