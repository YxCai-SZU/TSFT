#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bound:
        \forall integer a, b;
        valid_params(a, b, 1) ==> a + b <= 200;

    lemma product_bound:
        \forall integer a, b, h;
        valid_params(a, b, h) ==> (a + b) * h <= 20000;
*/

uint64_t func_trapezoid(uint64_t a, uint64_t b, uint64_t h)
{
    //@ assert a + b <= 200;
    //@ assert (a + b) * h <= 20000;
    uint64_t ans = ((a + b) * h / 2);
    return ans;
}

/*@
    predicate valid_vector(int *v, integer len) =
        len >= 1 && len <= 100 &&
        \forall integer i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000;
*/

/*@
    lemma vector_properties:
        \forall int *v, integer len; valid_vector(v, len) ==> len >= 1 && len <= 100;
*/

int func_count_even_diff(int *v, int n) {
    int res = 0;
    int index = 0;
    
    while (index < n) {
        int value = v[index];
        int diff = value - (index + 1);
        
        //@ assert value >= 1 && value <= 1000;
        
        if ((diff & 1) == 0) {
            res += 1;
        }
        
        index += 1;
    }
    
    return res;
}

/*@
    predicate contains{L}(int *s, size_t len, integer e) =
        \exists size_t i; 0 <= i < len && s[i] == e;

    predicate contains_all{L}(int *s, size_t len, int *others, size_t olen) =
        \forall size_t i; 0 <= i < olen ==> contains(s, len, others[i]);

    predicate no_common_elements{L}(int *s1, size_t len1, int *s2, size_t len2) =
        \forall size_t i, j; 0 <= i < len1 && 0 <= j < len2 ==> s1[i] != s2[j];

    predicate subset_of{L}(int *s1, size_t len1, int *s2, size_t len2) =
        \forall size_t i; 0 <= i < len1 ==> contains(s2, len2, s1[i]);

    predicate disjoint{L}(int *s1, size_t len1, int *s2, size_t len2) =
        \forall size_t i, j; 0 <= i < len1 && 0 <= j < len2 ==> s1[i] != s2[j];

    lemma subset_of_lemma{L}:
        \forall int *s1, size_t len1, int *s2, size_t len2;
        subset_of(s1, len1, s2, len2) ==>
        (\forall size_t i; 0 <= i < len1 ==> contains(s2, len2, s1[i]));

    lemma disjoint_lemma{L}:
        \forall int *s1, size_t len1, int *s2, size_t len2;
        disjoint(s1, len1, s2, len2) ==>
        (\forall size_t i, j; 0 <= i < len1 && 0 <= j < len2 ==> s1[i] != s2[j]);
*/

int func_process_areas(int *v, int n, uint64_t *areas) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        uint64_t a = (uint64_t)v[i];
        uint64_t b = (uint64_t)v[i];
        uint64_t h = (uint64_t)(2 * (i + 1));
        areas[i] = func_trapezoid(a, b, h);
        //@ assert areas[i] == trapezoid_area(a, b, h);
    }
    
    count = func_count_even_diff(v, n);
    
    //@ assert count >= 0 && count <= n;
    //@ assert \forall integer i; 0 <= i < n ==> areas[i] == trapezoid_area((uint64_t)v[i], (uint64_t)v[i], (uint64_t)(2 * (i+1)));
    
    return count;
}

/*@
    predicate valid_scenario(int *v, int n, uint64_t *areas) =
        n >= 1 && n <= 100 &&
        \valid(v + (0 .. n-1)) &&
        \valid(areas + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000 &&
        \forall integer i; 0 <= i < n ==> areas[i] == trapezoid_area((uint64_t)v[i], (uint64_t)v[i], (uint64_t)(2 * (i+1)));
*/

int synthesized_function(int *v, int n, uint64_t *areas) {
    int result = func_process_areas(v, n, areas);
    
    //@ assert \forall integer i; 0 <= i < n ==> areas[i] == trapezoid_area((uint64_t)v[i], (uint64_t)v[i], (uint64_t)(2 * (i+1)));
    
    return result;
}
