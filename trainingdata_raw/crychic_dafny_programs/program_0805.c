// Generated C + ACSL

/*@
    requires treatmentNames != \null;
    requires nIndividuals != \null;
    requires treatmentNames_len > 0;
    requires nIndividuals_len > 0;
    requires \valid_read(treatmentNames + (0 .. treatmentNames_len-1));
    requires \valid_read(nIndividuals + (0 .. nIndividuals_len-1));
    assigns \nothing;
    ensures \result == 1 ==> treatmentNames_len == nIndividuals_len;
    ensures \result == 1 ==>
        (\forall integer i; 0 <= i < nIndividuals_len ==> nIndividuals[i] > 0);
*/
int ValidateTreatmentConfig(char** treatmentNames, int treatmentNames_len, int* nIndividuals, int nIndividuals_len)
{
  if ((treatmentNames_len != nIndividuals_len))
  {
    return 0;
  }
  int i = 0;
/*@
  loop invariant 0 <= i <= nIndividuals_len;
  loop invariant \forall integer k; 0 <= k < i ==> nIndividuals[k] > 0;
  loop assigns i;
  loop variant nIndividuals_len - i;
*/
  while ((i < nIndividuals_len))
    {
      if ((nIndividuals[i] <= 0))
      {
        return 0;
      }
      i = (i + 1);
    }
  return 1;
}

/*@
  predicate Valid(integer nTimepoints, integer perturbationTimepoint,
                  integer perturbationDuration, real interindividualVariation,
                  real delta, real lambda) =
    nTimepoints > 0 && perturbationTimepoint >= 0 &&
    perturbationDuration > 0 && interindividualVariation >= 0.0 &&
    delta >= 0.0 && lambda >= 0.0;
*/

/*@
    requires \valid_read(&perturbationTimepoint);
    requires \valid_read(&nTimepoints);
    assigns \nothing;
    ensures \result == 1 ==> perturbationTimepoint < nTimepoints;
    ensures \result == 1 ==> perturbationTimepoint >= 0;
*/
int CheckPerturbationTimepoint(int perturbationTimepoint, int nTimepoints)
{
  if (((perturbationTimepoint >= nTimepoints) || (perturbationTimepoint < 0)))
  {
    return 0;
  }
  return 1;
}

// skipped function ParsePerturbationParams due to unsupported type