#include <stdbool.h>

/* ===== Original function 1: func (n - m) with range checks ===== */
/*@ predicate is_valid_input(integer n, integer m) = 
      1 <= n && n <= 100 && 0 <= m && m <= n; */

/*@ logic integer func_spec(integer n, integer m) = n - m; */

/*@ lemma func_lemma: 
      \forall integer n, integer m; 
      is_valid_input(n, m) ==> func_spec(n, m) == n - m; */

int func(int n, int m)
{
  int result;
  //@ assert is_valid_input(n, m);
  result = n - m;
  //@ assert result == func_spec(n, m);
  return result;
}

/* ===== Original function 2: func2 (deficit calculation) ===== */
/*@ predicate is_valid_input2(integer A, integer B, integer C) = 
      1 <= B && B <= A && A <= 100 && 1 <= C && C <= 100; */

/*@ logic integer func2_spec(integer A, integer B, integer C) = 
      (A - B >= C) ? 0 : C - (A - B); */

/*@ lemma func2_lemma1: 
      \forall integer A, integer B, integer C; 
      is_valid_input2(A, B, C) ==> func2_spec(A, B, C) >= 0; */

/*@ lemma func2_lemma2: 
      \forall integer A, integer B, integer C; 
      is_valid_input2(A, B, C) ==> func2_spec(A, B, C) <= C; */

/*@ lemma func2_lemma3: 
      \forall integer A, integer B, integer C; 
      is_valid_input2(A, B, C) && (A - B >= C) ==> func2_spec(A, B, C) == 0; */

/*@ lemma func2_lemma4: 
      \forall integer A, integer B, integer C; 
      is_valid_input2(A, B, C) && (A - B < C) ==> func2_spec(A, B, C) == C - (A - B); */

int func2(int A, int B, int C)
{
  int diff;
  int result;
  //@ assert is_valid_input2(A, B, C);
  diff = A - B;
  if (diff >= C) {
    //@ assert diff >= C;
    result = 0;
    //@ assert result == 0;
  } else {
    //@ assert diff < C;
    result = C - diff;
    //@ assert result == C - diff;
  }
  //@ assert result == func2_spec(A, B, C);
  return result;
}

/* ===== Original function 3: func3 (excess over threshold) ===== */
/*@ predicate is_valid_input3(integer a, integer b) = 
      1 <= a && a <= 100 && 1 <= b && b <= 100; */

/*@ logic integer func3_spec(integer a, integer b) = 
      (a > b * 2) ? a - b * 2 : 0; */

/*@ lemma func3_lemma1: 
      \forall integer a, integer b; 
      is_valid_input3(a, b) ==> func3_spec(a, b) >= 0; */

/*@ lemma func3_lemma2: 
      \forall integer a, integer b; 
      is_valid_input3(a, b) && (a > b * 2) ==> func3_spec(a, b) == a - b * 2; */

/*@ lemma func3_lemma3: 
      \forall integer a, integer b; 
      is_valid_input3(a, b) && (a <= b * 2) ==> func3_spec(a, b) == 0; */

int func3(int a, int b)
{
  int result;
  //@ assert is_valid_input3(a, b);
  if (a > b * 2) {
    //@ assert a > b * 2;
    result = a - b * 2;
    //@ assert result == a - b * 2;
  } else {
    //@ assert a <= b * 2;
    result = 0;
    //@ assert result == 0;
  }
  //@ assert result == func3_spec(a, b);
  return result;
}

/* ===== Original function 4: func4 (binary inversion) ===== */
/*@ predicate is_valid_input4(integer x) = 
      0 <= x && x <= 1; */

/*@ logic integer func4_spec(integer x) = (x == 0) ? 1 : 0; */

/*@ lemma func4_lemma1: 
      \forall integer x; 
      is_valid_input4(x) && (x == 0) ==> func4_spec(x) == 1; */

/*@ lemma func4_lemma2: 
      \forall integer x; 
      is_valid_input4(x) && (x == 1) ==> func4_spec(x) == 0; */

int func4(int x)
{
  int result;
  //@ assert is_valid_input4(x);
  if (x == 0) {
    //@ assert x == 0;
    result = 1;
    //@ assert result == 1;
  } else {
    //@ assert x == 1;
    result = 0;
    //@ assert result == 0;
  }
  //@ assert result == func4_spec(x);
  return result;
}

/* ===== New synthesized function: ResourceAllocator ===== */
/* Real-world scenario: 
   A resource allocator that determines how many additional resources to grant 
   to a process based on its current usage and remaining budget. 
   Data flow:
   1. Compute current resource usage: func(n, m) = n - m (resources used out of n)
   2. Compute deficit if trying to allocate C more resources: func2(A, B, C) 
      (how many more needed if A-B < C, else 0)
   3. Compute excess capacity: func3(a, b) = max(0, a - 2*b) (spare resources)
   4. Invert a flag: func4(x) to indicate if allocation should proceed (1) or not (0)
*/

/*@
  predicate valid_allocation(integer n, integer m, integer A, integer B, integer C,
                              integer a, integer b, integer x) =
    is_valid_input(n, m) && is_valid_input2(A, B, C) && 
    is_valid_input3(a, b) && is_valid_input4(x) &&
    n == A && m == B;  // consistency: n,m and A,B represent same resource state

  logic integer alloc_spec(integer n, integer m, integer C, integer a, integer b, integer x) =
    (func_spec(n, m) + func2_spec(n, m, C) + func3_spec(a, b)) * func4_spec(x);
*/

int resource_allocator(int n, int m, int A, int B, int C, int a, int b, int x)
{
  int usage;
  int deficit;
  int excess;
  int proceed_flag;
  int total;

  usage = func(n, m);
  //@ assert usage == func_spec(n, m);

  deficit = func2(A, B, C);
  //@ assert deficit == func2_spec(A, B, C);

  excess = func3(a, b);
  //@ assert excess == func3_spec(a, b);

  proceed_flag = func4(x);
  //@ assert proceed_flag == func4_spec(x);

  total = (usage + deficit + excess) * proceed_flag;

  //@ assert total >= 0 && total == alloc_spec(n, m, C, a, b, x);

  return total;
}
