// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < a_len ==> a[i] <= \result;
    ensures \exists integer i; 0 <= i < a_len && a[i] == \result;
*/
int MaxArray(int* a, int a_len)
{
  int i = 1;
  int max = a[0];
  /*@ assert max == a[0]; */
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] <= max;
  loop invariant \exists integer j; 0 <= j < i && a[j] == max;
  loop invariant \forall integer j; 0 <= j < a_len ==> (a[j] <= max || i <= j);
  loop assigns i, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > max))
      {
        max = a[i];
        /*@ assert max == a[i]; */
        /*@ assert \forall integer j; 0 <= j < i ==> a[j] <= max; */
      }
      else
      {
        /*@ assert a[i] <= max; */
      }
      /*@ assert \forall integer j; 0 <= j <= i ==> a[j] <= max; */
      /*@ assert \exists integer j; 0 <= j <= i && a[j] == max; */
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \forall integer j; 0 <= j < a_len ==> a[j] <= max; */
  /*@ assert \exists integer j; 0 <= j < a_len && a[j] == max; */
  return max;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int arr_vals[] = {-11, 2, 42, -4};
  int* arr = arr_vals;
  int arr_len = 4;
  int res = MaxArray(arr, arr_len);
  /*@ assert ((((arr[0] == -11) && (arr[1] == 2)) && (arr[2] == 42)) && (arr[3] == -4)); */
  /*@ assert (res == 42); */
}