#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ========== Original First Function (Adapted) ========== */
/*@
    predicate valid_range(int* arr, integer n) =
        n >= 1 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

int find_longest_non_increasing(int n, int* input_numbers) {
    int before = 0;
    int ans = 0;
    int now = 0;
    int index = 0;
    
    while (index < n) {
        int a = input_numbers[index];
        
        //@ assert a >= 1 && a <= 1000000000;
        
        if (before >= a) {
            now = now + 1;
            //@ assert now >= 1 && now <= index + 1;
            if (ans > now) {
                //@ assert ans >= now;
            } else {
                ans = now;
                //@ assert ans == now;
            }
            //@ assert ans >= now;
        } else {
            now = 0;
            //@ assert now == 0;
        }
        
        //@ assert ans >= -1;
        //@ assert ans <= index + 1;
        
        before = a;
        index = index + 1;
        
        //@ assert index <= n;
    }
    
    //@ assert index == n;
    //@ assert ans >= -1 && ans <= n;
    
    if (ans == 0) {
        return -1;
    } else {
        return ans;
    }
}

/* ========== Original Second Function (Adapted) ========== */
/*@
    predicate valid_range_2(integer x) = 1 <= x <= 3;

    logic integer multiply_mod(integer a, integer b) = (a * b * 2) % 2;

    lemma multiplication_bound: 
        \forall integer a, b; valid_range_2(a) && valid_range_2(b) ==> a * b <= 9;
*/

bool check_multiply_mod(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool result;

    //@ assert valid_range_2(a);
    //@ assert valid_range_2(b);
    //@ assert a * b <= 9;

    c = (a * b * 2) % 2;
    
    if (c == 0) {
        result = false;
    } else {
        result = true;
    }

    //@ assert result == (multiply_mod(a, b) != 0);
    return result;
}

/* ========== Original Third Function (Adapted) ========== */
/*@
    predicate valid_range_3(integer x) = 1 <= x <= 1000000000;
*/

int32_t check_triangle_approx(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t approx_c;
    uint32_t approx_a_b;
    int32_t result;

    if (c > a + b)
    {
        approx_c = (c + a + b) / 2;
        approx_a_b = (a + b) / 2;

        if (approx_c > approx_a_b)
        {
            //@ assert approx_c > approx_a_b;
            result = 0;
        }
        else
        {
            //@ assert approx_c <= approx_a_b;
            result = 1;
        }
    }
    else
    {
        //@ assert c <= a + b;
        result = 1;
    }

    return result;
}

/* ========== Original Fourth Function (Adapted) ========== */
typedef struct {
    int key;
    size_t len;
    size_t s_len;
    int* s;
} TestStruct;

typedef struct {
    size_t sub_struct_len;
    TestStruct* sub_struct;
    int key;
} AnotherTestStruct;

/*@
    predicate valid_TestStruct(TestStruct s) =
        s.s_len == s.len &&
        \forall integer i; 0 <= i < s.len ==> s.s[i] == i * s.key;

    predicate valid_AnotherTestStruct(AnotherTestStruct s) =
        \forall integer i; 0 <= i < s.sub_struct_len ==> 
            valid_TestStruct(s.sub_struct[i]);
*/

bool check_valid_TestStruct(TestStruct s) {
    //@ assert valid_TestStruct(s);
    return true;
}

bool check_valid_AnotherTestStruct(AnotherTestStruct s) {
    //@ assert valid_AnotherTestStruct(s);
    return true;
}

/* ========== Synthesized Complex Function ========== */
int process_data_chain(int n, int* input_numbers, 
                       unsigned int a, unsigned int b,
                       uint32_t x, uint32_t y, uint32_t z,
                       TestStruct s, AnotherTestStruct t)
{
    bool struct_valid = check_valid_TestStruct(s) && check_valid_AnotherTestStruct(t);
    //@ assert struct_valid == true;
    
    bool mult_check = check_multiply_mod(a, b);
    
    int32_t tri_check = check_triangle_approx(x, y, z);
    
    int longest = find_longest_non_increasing(n, input_numbers);
    
    int result;
    if (struct_valid && mult_check && (tri_check == 1) && (longest >= 0)) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) <==> (struct_valid && mult_check && (tri_check == 1) && (longest >= 0));
    
    return result;
}

int main() {
    return 0;
}
