// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures \result != -1 ==> a[\result] == key;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < a_len ==> a[i] != key);
*/
int Find(int* a, int a_len, int key)
{
  int index = 0;
  /*@ assert index >= 0 && index <= 2147483647; */
/*@
  loop invariant 0 <= index <= a_len;
  loop invariant \forall integer i; 0 <= i < index ==> a[i] != key;
  loop assigns index;
  loop variant a_len - index;
*/
  while ((index < a_len))
    {
      if (a[index] == key)
      {
        return index;
      }
      index = (index + 1);
    }
  if ((index >= a_len))
  {
    index = -1;
  }
  return index;  // Dafny implicit return
}

/*@
    requires \true;
    assigns \nothing;
*/
void TestMethod(void)
{
  int a1_vals[] = {1, 2, 3, 4, 5};
  int* a1 = a1_vals;
  int a1_len = 5;
  int test1 = Find(a1, a1_len, 3);
  /* unsupported stmt: print ("Test 1: Find(...) = ", test1, "\n"); */
  int a2_vals[] = {5, 4, 3, 2, 1};
  int* a2 = a2_vals;
  int a2_len = 5;
  int test2 = Find(a2, a2_len, 1);
  /* unsupported stmt: print ("Test 2: Find(...) = ", test2, "\n"); */
  int a3_vals[] = {-2, -4, -6, -8, -10};
  int* a3 = a3_vals;
  int a3_len = 5;
  int test3 = Find(a3, a3_len, -8);
  /* unsupported stmt: print ("Test 3: Find(...) = ", test3, "\n"); */
  int a4_vals[] = {0, 10, 20, 30, 40};
  int* a4 = a4_vals;
  int a4_len = 5;
  int test4 = Find(a4, a4_len, 60);
  /* unsupported stmt: print ("Test 4: Find(...) = ", test4, "\n"); */
  int a5_vals[10] = {0};
  int* a5 = a5_vals;
  int test5 = Find(a5, 10, 0);
  /* unsupported stmt: print ("Test 5: Find(...) = ", test5, "\n"); */
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  TestMethod();;
}