#include <stdbool.h>

/* ========== First underlying function ========== */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    predicate result_range(integer r) = 1 <= r && r <= 3;
*/

int func1(int a, int b, int c)
{
    int result = -1;
    int i = 0;

    if (a == b && b == c)
    {
        result = 1;
    }
    else if (a == b || b == c || a == c)
    {
        result = 2;
    }
    else
    {
        result = 3;
    }

    //@ assert result_range(result);

    while (i < 5)
    {
        i = i + 1;
    }

    //@ assert result_range(result);
    return result;
}

/* ========== Second underlying function ========== */
/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= a && a <= n && n <= 1000000 &&
        1 <= b && b <= n &&
        a != b;

    logic integer func_result(integer a, integer b) =
        (a - 1 < b - 1) ? 1 : ((b - 1 < a - 1) ? 1 : 0);

    lemma func_lemma:
        \forall integer n, a, b;
        valid_params(n, a, b) ==>
        func_result(a, b) == ((a - 1 < b - 1) || (b - 1 < a - 1));
*/

bool func2(unsigned int n, unsigned int a, unsigned int b)
{
    bool result;

    //@ assert n > 0;
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert a != b;
    //@ assert n <= 1000000;
    //@ assert a <= n;
    //@ assert b <= n;

    result = (a - 1 < b - 1) || (b - 1 < a - 1);
    return result;
}

/* ========== Third underlying function ========== */
/*@ predicate numbers_positive(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ predicate valid_range(integer n, integer len) =
      n > 0 && n <= len;
*/

int func3(int n, int *arr, int len) {
    int counter = 0;
    int index = 0;
    
    while (index < len && index < n) {
        int i = arr[index];
        if (i == 1) {
            counter += 1;
        } else {
            if (i - 2 > 0) {
                counter += 1;
            }
        }
        index += 1;
        
        //@ assert index <= n;
        //@ assert counter <= n;
    }
    return counter;
}

/* ========== Synthesized function: Data packet classification and processing ========== */
/* Scenario: Network packet processing system.
   A packet classifier (func1) categorizes a packet based on three priority fields (a,b,c) into
   class 1, 2, or 3. Then a validation function (func2) checks if two packet IDs (a,b) are distinct
   within a valid range (simulating duplicate detection). Finally, a packet processor (func3) counts
   how many of the first n packets in an array arr have special flags (value 1 or value >2).
   
   Data flow: 
   - func1 output (class) indicates the packet type. 
   - func2 validates that two IDs are distinct (true if distinct).
   - func3 counts special packets, returning a count <= n.
   
   The synthesized function returns:
   - -1 if the class is 1 and IDs are not distinct (invalid state).
   - Otherwise, returns the count from func3 (which is the number of special packets).
   
   The core high-level property: the output is either -1 or a valid count in [0, n].
*/

int synthesize(int a, int b, int c, int n, int *arr, int len)
{
    int class = func1(a, b, c);
    bool distinct = func2((unsigned int)len, (unsigned int)a, (unsigned int)b);
    int count = 0;
    
    if (class == 1 && !distinct) {
        //@ assert class == 1 && !distinct;
        return -1;
    } else {
        count = func3(n, arr, len);
        //@ assert 0 <= count <= n;
        return count;
    }
}
