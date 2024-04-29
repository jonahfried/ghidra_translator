
long _string_join(long param_1,int param_2,long param_3)

{
  int local_34;
  long local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null string array in string_join.\n");
    local_10 = 0;
  }
  else if (param_2 < 1) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid count in string_join.\n");
    local_10 = 0;
  }
  else if (param_3 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null delimiter in string_join.\n");
    local_10 = 0;
  }
  else {
    local_10 = _string_create("");
    if (local_10 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_join.\n");
      local_10 = 0;
    }
    else {
      for (local_34 = 0; local_34 < param_2; local_34 = local_34 + 1) {
        _string_append(local_10,**(undefined8 **)(param_1 + (long)local_34 * 8));
        if (local_34 < param_2 + -1) {
          _string_append(local_10,param_3);
        }
      }
    }
  }
  return local_10;
}

