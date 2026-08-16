#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/*@ predicate is_valid_array(int *a, integer n) =
      n > 0 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

/*@ logic integer answer(integer n, integer k) = n - k + 1; */

/*@ lemma answer_bounds: 
      \forall integer n, k; 
      1 <= k <= n+1 && n > 0 ==> -1 <= answer(n,k) <= n;
*/

struct AnotherStruct {
    int int_1;
    char* string_1;
    int* list_1;
    int list_1_len;
};

/*@ predicate equal_AnotherStruct{L}(struct AnotherStruct s1, struct AnotherStruct s2) =
       s1.int_1 == s2.int_1 &&
       s1.string_1 == s2.string_1 &&
       s1.list_1_len == s2.list_1_len &&
       (\forall integer i; 0 <= i < s1.list_1_len ==> s1.list_1[i] == s2.list_1[i]);
*/

int func(size_t n, int *a) {
    size_t i = 0;
    int k = 1;
    
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] == k) {
            k = k + 1;
        }
        i = i + 1;
    }
    
    int ans = (int)n - k + 1;
    //@ assert ans == answer(n, k);
    
    if (ans == (int)n) {
        return -1;
    } else {
        return ans;
    }
}

int is_permutation_of_range(size_t n, int *a) {
    int result = func(n, a);
    return (result == -1) ? 1 : 0;
}

int check_struct_permutation(struct AnotherStruct *s) {
    return is_permutation_of_range((size_t)s->list_1_len, s->list_1);
}

int validate_and_check_permutation(struct AnotherStruct *s) {
    int perm_check = check_struct_permutation(s);
    
    //@ assert perm_check == 1 || perm_check == 0;
    
    if (perm_check == 1) {
        //@ assert is_valid_array(s->list_1, s->list_1_len);
        //@ assert \forall integer i; 0 <= i < s->list_1_len ==> 1 <= s->list_1[i] <= s->list_1_len;
        //@ assert \forall integer i, j; 0 <= i < j < s->list_1_len ==> s->list_1[i] != s->list_1[j];
    }
    
    return perm_check;
}

int main() {
    return 0;
}
