// Generated C + ACSL

// ```c
// /*@
//   axiomatic MergeLShift_properties {
//     lemma MergeLShift_statement:
//       \forall integer v, integer i, integer j;
//         (0 <= i <= 128 && 0 <= j <= 128 && i + j <= 128) ==>
//         ((v << i) << j) == (v << (i + j));
//   }
// */
// ```

void MergeLShift(unsigned long long v, int i, int j);

/*@
    requires 0 <= i <= 64;
    assigns \nothing;
*/
void M2(int i)
{
  unsigned long long half = 18446744073709551615ULL;
  MergeLShift(half, 64, 64 - i);;
  /*@ assert (((half << (64 - i)) << 64) == (half << (128 - i))); */
}