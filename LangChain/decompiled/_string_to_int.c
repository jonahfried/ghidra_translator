
int _string_to_int(char **param_1)

{
  ulong uVar1;
  int local_c;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_to_int.\n");
    local_c = 0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if ((uVar1 & 1) == 0) {
      local_c = _atoi(*param_1);
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty string in string_to_int.\n");
      local_c = 0;
    }
  }
  return local_c;
}

