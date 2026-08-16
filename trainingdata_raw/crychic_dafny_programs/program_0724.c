// Generated C + ACSL

typedef struct {
    int energy;
    int mass;
    int pdgId;
} Particle;

/*@
    requires particles != \null;
    requires particles_len >= 0;
    requires \valid(particles + (0 .. particles_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0;
*/
int GeneratorAnalyzer(Particle* particles, int particles_len)
{
  int result = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= particles_len;
  loop invariant result == 0;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant particles_len - i;
*/
  while ((i < particles_len))
    {
      if ((particles[i].energy > particles[i].mass))
      {
        result = (result + 0);
        //@ assert result == 0;
      }
      i = (i + 1);
      //@ assert result == 0;
    }
  //@ assert result == 0;
  //@ assert result >= 0;
  return result;
}

/*@
    requires particles != \null;
    requires particles_len >= 0;
    requires \valid(particles + (0 .. particles_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0;
*/
int HeavyFlavourAnalyzer(Particle* particles, int particles_len)
{
  int result = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= particles_len;
  loop invariant result == 0;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant particles_len - i;
*/
  while ((i < particles_len))
    {
      if (((particles[i].pdgId == 5) || (particles[i].pdgId == 4)))
      {
        result = (result + 0);
        //@ assert result == 0;
      }
      i = (i + 1);
      //@ assert result == 0;
    }
  //@ assert result == 0;
  //@ assert result >= 0;
  return result;
}

/*@
    requires particles != \null;
    requires particles_len >= 0;
    requires \valid(particles + (0 .. particles_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0;
*/
int HiggsDecayModeAnalyzer(Particle* particles, int particles_len)
{
  int result = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= particles_len;
  loop invariant result == 0;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant particles_len - i;
*/
  while ((i < particles_len))
    {
      if ((particles[i].pdgId == 25))
      {
        result = (result + 0);
        //@ assert result == 0;
      }
      i = (i + 1);
      //@ assert result == 0;
    }
  //@ assert result == 0;
  //@ assert result >= 0;
  return result;
}