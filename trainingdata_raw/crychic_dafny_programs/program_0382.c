// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || a[\result] == e;
    ensures \result == a_len ==>
        (\forall integer i; 0 <= i < a_len ==> a[i] != e);
*/
int LinearSearch(int* a, int a_len, int e)
{
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i; 0 <= i < n ==> e != a[i];
  loop assigns n;
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      if ((e == a[n]))
      {
        return n;
      }
      n = (n + 1);
    }
  return n;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void TestLinearSearch(void)
{
  int a_vals[] = {1, 2, 3, 4, 5};
  int* a = a_vals;
  int a_len = 5;
  int test = LinearSearch(a, a_len, 3);
  /* unsupported stmt: print ("Test 1: LinearSearch(...) = ", test, "\n"); */
  /* unsupported stmt: a := new int[] [10, 15, 20, 25, 30, 35, 40]; */
  test = LinearSearch(a, a_len, 30);
  /* unsupported stmt: print ("Test 2: LinearSearch(...) = ", test, "\n"); */
  /* unsupported stmt: a := new int[] [0]; */
  test = LinearSearch(a, a_len, 0);
  /* unsupported stmt: print ("Test 3: LinearSearch(...) = ", test, "\n"); */
  /* unsupported stmt: a := new int[] [-10, -20, -30]; */
  test = LinearSearch(a, a_len, -20);
  /* unsupported stmt: print ("Test 4: LinearSearch(...) = ", test, "\n"); */
  /* unsupported stmt: a := new int[] [321, 123, 456, 654]; */
  test = LinearSearch(a, a_len, 5);
  /* unsupported stmt: print ("Test 5: LinearSearch(...) = ", test, "\n"); */
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  TestLinearSearch();;
}