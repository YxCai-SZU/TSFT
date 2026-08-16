#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 1000000000 &&
        2 <= k && k <= 10;

    lemma mod_range: \forall integer n, k; valid_params(n, k) ==> 0 <= n % k < k;
*/

uint32_t func1(uint32_t n, uint32_t k)
{
    uint32_t r;
    
    r = n % k;
    
    if (r == 0U)
    {
        return 0U;
    }
    else
    {
        //@ assert 1 <= n;
        //@ assert k <= 10;
        return 1U;
    }
}

/*@
predicate positive(integer a) = a > 0;

lemma non_linear_arith_example12: \forall integer a, integer b; positive(a) && positive(b) ==> (a + b) * b == a * b + b * b;

lemma non_linear_arith_example13: \forall integer a, integer b; positive(a) && positive(b) ==> (a - b) * b == a * b - b * b;

lemma non_linear_arith_example14: \forall integer a, integer b; positive(a) && positive(b) ==> 
        (a + b) * b == a * b + b * b &&
        (a - b) * b == a * b - b * b;
*/

int non_linear_arith_example12_func(int a, int b) {
    int result;
    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert (a + b) * b == a * b + b * b;
    result = (a + b) * b;
    return result;
}

int non_linear_arith_example13_func(int a, int b) {
    int result;
    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert (a - b) * b == a * b - b * b;
    result = (a - b) * b;
    return result;
}

int non_linear_arith_example14_func(int a, int b) {
    int result;
    int tmp1;
    int tmp2;
    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert (a + b) * b == a * b + b * b;
    tmp1 = (a + b) * b;
    //@ assert (a - b) * b == a * b - b * b;
    tmp2 = (a - b) * b;
    result = tmp1 + tmp2;
    return result;
}

/*@ predicate valid_array(int *arr, size_t n) =
      n > 0 && n <= 200 &&
      \forall size_t i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;
*/

/*@ predicate array_length(int *arr, size_t n) =
      \forall size_t i; 0 <= i < n ==> \valid(arr + i);
*/

int func_array(size_t n, int *a) {
    size_t i = 0;
    size_t count = 0;
    size_t count2 = 0;
    int result = 0;

    while (i < n) {
        int value = a[i];
        
        //@ assert value > 0 && value <= 1000000000;
        
        if ((value & 1) == 0) {
            count++;
        } else {
            count2++;
        }
        i++;
    }

    //@ assert count >= 0 && count <= n;
    //@ assert count2 >= 0 && count2 <= n;
    
    if (count >= 3) {
        result += 1;
    }
    if (count2 >= 2) {
        result += 1;
    }
    if (count >= 1 && count2 >= 1) {
        result += 1;
    }
    
    //@ assert result >= 0 && result <= 30;
    return result;
}

struct Student {
    char* name;
    unsigned int age;
};

/*@ predicate is_adult(struct Student* s) = s->age >= 18; */

int func_small(int a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 10 * 10;
    //@ assert a * a * a >= 1 * 1 * 1;
    //@ assert a * a * a <= 10 * 10 * 10;
    return a + a * a + a * a * a;
}

struct Student change_name(struct Student* s, char* new_name)
{
    struct Student ret;
    //@ assert is_adult(s);
    ret.name = new_name;
    ret.age = s->age;
    //@ assert ret.age == s->age;
    return ret;
}

int process_student_data(uint32_t n, uint32_t k, size_t arr_len, int *arr, int small_val, struct Student* s, char* new_name)
{
    uint32_t mod_result = func1(n, k);
    //@ assert mod_result <= n;
    
    int arith_result = 0;
    if (mod_result == 0) {
        int a = small_val + 1;  // Ensure a > 0
        int b = small_val;      // Ensure b > 0
        //@ assert a > 0 && b > 0;
        arith_result = non_linear_arith_example14_func(a, b);
        //@ assert arith_result == ((a + b) * b) + ((a - b) * b);
    } else {
        int a = small_val + 2;  // Ensure a > 0
        int b = small_val + 1;  // Ensure b > 0
        //@ assert a > 0 && b > 0;
        int tmp1 = non_linear_arith_example12_func(a, b);
        int tmp2 = non_linear_arith_example13_func(a, b);
        arith_result = tmp1 + tmp2;
        //@ assert arith_result == ((a + b) * b) + ((a - b) * b);
    }
    
    int array_result = func_array(arr_len, arr);
    //@ assert array_result >= 0 && array_result <= 30;
    
    struct Student updated_student = change_name(s, new_name);
    //@ assert updated_student.age == s->age;
    
    int small_result = func_small(small_val);
    //@ assert small_result == small_val + small_val * small_val + small_val * small_val * small_val;
    
    //@ assert array_result >= 0 && array_result <= 30;
    
    return array_result;
}

int main()
{
    return 0;
}
