
int _string_at(long *param_1,ulong param_2)

{
  char local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The String object is NULL in string_at.\n");
    local_9 = '\0';
  }
  else if (param_2 < (ulong)param_1[1]) {
    local_9 = *(char *)(*param_1 + param_2);
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Index out of range in string_at.\n");
    local_9 = '\0';
  }
  return (int)local_9;
}

