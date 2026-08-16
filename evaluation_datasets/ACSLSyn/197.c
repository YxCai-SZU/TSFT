#include <limits.h>

/*@ predicate is_valid_range(integer v) = -100 <= v <= 100; */
/*@ predicate is_valid_int(integer x) = INT_MIN <= x <= INT_MAX; */

/*@
  lemma min_property:
    \forall integer a, b, r;
      is_valid_int(a) && is_valid_int(b) && (r == a || r == b) && r <= a && r <= b ==>
      (r == a <==> a <= b) && (r == b <==> b <= a);
*/

/*@
  lemma max_property:
    \forall integer a, b, r;
      is_valid_int(a) && is_valid_int(b) && (r == a || r == b) && r >= a && r >= b ==>
      (r == a <==> a >= b) && (r == b <==> b >= a);
*/

int min_tuple(int a, int b)
{
    int ret;
    //@ assert is_valid_int(a) && is_valid_int(b);
    if (a < b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert ret == a || ret == b;
    //@ assert ret <= a && ret <= b;
    return ret;
}

int max_tuple(int a, int b)
{
    int ret;
    //@ assert is_valid_int(a) && is_valid_int(b);
    if (a > b) {
        ret = a;
    } else {
        ret = b;
    }
    //@ assert ret == a || ret == b;
    //@ assert ret >= a && ret >= b;
    return ret;
}

struct Tuple { int first; int second; };

struct Tuple min_tuple_list(int list1_0, int list1_1, int list2_0, int list2_1)
{
    struct Tuple ret;
    int tmp0;
    int tmp1;
    //@ assert is_valid_int(list1_0) && is_valid_int(list2_0);
    tmp0 = min_tuple(list1_0, list2_0);
    //@ assert tmp0 <= list1_0 && tmp0 <= list2_0;
    //@ assert is_valid_int(list1_1) && is_valid_int(list2_1);
    tmp1 = min_tuple(list1_1, list2_1);
    //@ assert tmp1 <= list1_1 && tmp1 <= list2_1;
    ret.first = tmp0;
    ret.second = tmp1;
    //@ assert ret.first <= list1_0 && ret.first <= list2_0;
    //@ assert ret.second <= list1_1 && ret.second <= list2_1;
    return ret;
}

struct Tuple max_tuple_list(int list1_0, int list1_1, int list2_0, int list2_1)
{
    struct Tuple ret;
    int tmp0;
    int tmp1;
    //@ assert is_valid_int(list1_0) && is_valid_int(list2_0);
    tmp0 = max_tuple(list1_0, list2_0);
    //@ assert tmp0 >= list1_0 && tmp0 >= list2_0;
    //@ assert is_valid_int(list1_1) && is_valid_int(list2_1);
    tmp1 = max_tuple(list1_1, list2_1);
    //@ assert tmp1 >= list1_1 && tmp1 >= list2_1;
    ret.first = tmp0;
    ret.second = tmp1;
    //@ assert ret.first >= list1_0 && ret.first >= list2_0;
    //@ assert ret.second >= list1_1 && ret.second >= list2_1;
    return ret;
}

/* Original func1: compute max of four sums */
int func(int A, int B, int C, int D)
{
    int max1;
    int max2;
    int result;
    
    max1 = (A + C > B + C) ? (A + C) : (B + C);
    max2 = (A + D > B + D) ? (A + D) : (B + D);
    
    if (max1 > max2)
    {
        //@ assert max1 >= A + C;
        //@ assert max1 >= B + C;
        //@ assert max1 >= A + D;
        //@ assert max1 >= B + D;
        result = max1;
    }
    else
    {
        //@ assert max2 >= A + C;
        //@ assert max2 >= B + C;
        //@ assert max2 >= A + D;
        //@ assert max2 >= B + D;
        result = max2;
    }
    
    return result;
}

struct SignalEnvelope {
    int max_envelope;
    struct Tuple min_components;
};

struct SignalEnvelope process_signal_envelope(int A, int B, int C, int D)
{
    struct SignalEnvelope result;
    int max_val;
    struct Tuple min_comp;
    
    max_val = func(A, B, C, D);
    //@ assert max_val >= A + C && max_val >= B + C && max_val >= A + D && max_val >= B + D;
    
    min_comp = min_tuple_list(A, B, C, D);
    //@ assert min_comp.first <= A && min_comp.first <= C;
    //@ assert min_comp.second <= B && min_comp.second <= D;
    
    result.max_envelope = max_val;
    result.min_components = min_comp;
    
    //@ assert result.max_envelope >= result.min_components.first + result.min_components.second;
    
    return result;
}

int main() {
    return 0;
}
