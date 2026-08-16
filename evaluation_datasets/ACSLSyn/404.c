#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ====== Underlying functions (adapted from snippets) ====== */

/* --- Function 1: search (binary search with distinct valid elements) --- */
/*@ predicate distinct_elements(int *arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@ predicate valid_elements(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> (arr[i] == i + 1 || arr[i] == -1);
*/

int search(int *arr, size_t len) {
    size_t low = 0;
    size_t high = len - 1;
    
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (arr[mid] == -1) {
            low = mid + 1;
            //@ assert low > mid;
        } else {
            high = mid;
            //@ assert high <= mid;
        }
    }
    
    if (low < len && arr[low] == -1) {
        return -1;
    } else {
        return (int)low;
    }
}

/* --- Function 2: check if one number equals sum of other two (sorted) --- */
/*@ predicate sorted(integer a, integer b, integer c) = a <= b && b <= c; */

bool func(int a, int b, int c) {
    int aa = a;
    int bb = b;
    int cc = c;
    int temp;

    if (aa > bb) {
        temp = aa;
        aa = bb;
        bb = temp;
    }
    if (bb > cc) {
        temp = bb;
        bb = cc;
        cc = temp;
    }
    if (aa > bb) {
        temp = aa;
        aa = bb;
        bb = temp;
    }

    //@ assert sorted(aa, bb, cc);

    return aa == bb + cc || bb == cc + aa || cc == aa + bb;
}

/* --- Function 3: count numbers not divisible by any 1..b (simplified) --- */
/*@
    predicate valid_params(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
*/

unsigned int func_count(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    unsigned int i = 0;
    
    while (i < a) {
        bool is_divisible = false;
        unsigned int j = 0;
        
        while (j < b) {
            if ((i + 1) % (j + 1) == 0) {
                is_divisible = true;
                break;
            }
            j++;
        }
        
        if (!is_divisible) {
            result++;
        }
        
        i++;
    }
    
    //@ assert result <= a;
    return result;
}

/* --- Function 4: non-negative difference --- */
/*@
    logic integer difference(integer x, integer y) =
        x >= y ? x - y : y - x;
*/

int32_t non_negative_diff_is_diff(int32_t a, int32_t b)
{
    //@ assert difference(a, b) >= 0;
    return a >= b ? a - b : b - a;
}

/* ====== Synthesized function ====== */

/* Scenario: In a data validation pipeline, we process an array of distinct elements
   (each either its index+1 or -1). We search for the first valid position (the index
   where arr[low] is not -1), then use the found index as parameters to three checks:
   (1) a sum-check on three derived values, (2) a count of numbers not divisible, and
   (3) a difference computation. The core property: the final computed value is
   bounded and consistent with the search result.
*/

unsigned int process_pipeline(int *arr, size_t len) {
    int pos = search(arr, len);
    
    if (pos == -1) {
        return 0;
    }
    
    int a = (pos % 100) + 1;
    int b = ((pos + 1) % 100) + 1;
    int c = ((pos + 2) % 100) + 1;
    
    bool sum_ok = func(a, b, c);
    
    unsigned int count = func_count((unsigned int)a, (unsigned int)b);
    
    int32_t diff = non_negative_diff_is_diff((int32_t)count, (int32_t)a);
    
    //@ assert diff >= 0 && (unsigned int)diff <= (unsigned int)a;
    
    return (unsigned int)diff;
}
