// Generated C + ACSL

/*@ logic integer Sum(int* s, integer s_len) =
      (s_len == 0) ? 0 : s[0] + Sum(s + 1, s_len - 1);
*/

/*@
  requires s_len >= 0;
  requires \valid_read(s + (0 .. s_len - 1));
  decreases s_len;
  assigns \nothing;
*/
int Sum(int* s, int s_len)
{
  return ((s_len == 0)) ? (0) : ((s[0] + Sum(s + 1, s_len - 1)));
}

// ```c
// /*@
//   axiomatic Sum1_properties {
//     lemma Sum1_statement:
//       \forall integer* s, integer len;
//         len == 1 ==>
//         Sum(s, len) == s[0];
//   }
// */
// ```

// ```c
// /*@
//   axiomatic Sum2_properties {
//     lemma Sum2_statement:
//       \forall integer* s, integer len;
//         len == 2 ==>
//         Sum(s, len) == s[0] + s[1];
//   }
// */
// ```

// ```acsl
// /*@
//   axiomatic Sum3_properties {
//     lemma Sum3_statement:
//       \forall integer* s, integer len;
//         len == 3 ==>
//         Sum(s, len) == s[0] + s[1] + s[2];
//   }
// */
// ```