// Generated C + ACSL

/*@
    requires numbers_len > 0;
    requires numbers != \null;
    requires \valid(numbers + (0 .. numbers_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < numbers_len ==> \result >= numbers[i];
    ensures \exists integer i; 0 <= i < numbers_len && \result == numbers[i];
*/
int FindMax(int* numbers, int numbers_len)
{
  int max = numbers[0];
  /*@ assert max == numbers[0]; */
  /*@ assert \exists integer k; 0 <= k < 1 && max == numbers[k]; */
  int i = 1;
/*@
  loop invariant 1 <= i <= numbers_len;
  loop invariant \forall integer k; 0 <= k < i ==> max >= numbers[k];
  loop invariant \exists integer k; 0 <= k < i && max == numbers[k];
  loop invariant \valid_read(numbers + (0..numbers_len-1));
  loop invariant \forall integer k; 0 <= k < numbers_len ==> max >= numbers[k] || k >= i;
  loop assigns i, max;
  loop variant numbers_len - i;
*/
  while ((i < numbers_len))
    {
      /*@ assert max >= numbers[i] || numbers[i] > max; */
      if ((numbers[i] > max))
      {
        max = numbers[i];
        /*@ assert max == numbers[i]; */
        /*@ assert \exists integer k; 0 <= k <= i && max == numbers[k]; */
      }
      /*@ assert \forall integer k; 0 <= k <= i ==> max >= numbers[k]; */
      i = (i + 1);
    }
  /*@ assert i == numbers_len; */
  /*@ assert \forall integer k; 0 <= k < numbers_len ==> max >= numbers[k]; */
  /*@ assert \exists integer k; 0 <= k < numbers_len && max == numbers[k]; */
  return max;  // Dafny implicit return
}