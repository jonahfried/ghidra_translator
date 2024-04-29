
undefined _string_is_lower(long *param_1)

{
  ulong local_20;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_is_lower.\n");
    local_9 = 0;
  }
  else {
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if (('@' < *(char *)(*param_1 + local_20)) && (*(char *)(*param_1 + local_20) < '[')) {
        return 0;
      }
    }
    local_9 = 1;
  }
  return local_9;
}

