// Generated C + ACSL

/*@
    logic integer Sum(int* s, integer s_len) =
        (s_len == 0) ? 0 : s[0] + Sum(s + 1, s_len - 1);
*/

/*@
    requires s_len >= 0;
    requires \valid_read(s + (0 .. s_len - 1));
    decreases s_len;
    ensures \result == Sum(s, s_len);
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
// Lemma: Sum3
// Property: For any sequence of exactly 3 natural numbers, the sum equals 
//           the first element plus the second element plus the third element.
// Proof hint: This is a direct unfolding of the Sum definition for sequences 
//             of length 3. The recursive Sum function expands to 
//             s[0] + Sum(s[1..]) = s[0] + s[1] + Sum(s[2..]) = s[0] + s[1] + s[2].
// ```