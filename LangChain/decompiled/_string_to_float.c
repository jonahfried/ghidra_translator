
float _string_to_float(char **param_1)

{
  ulong uVar1;
  double dVar2;
  float local_c;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_to_float.\n");
    local_c = 0.0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if ((uVar1 & 1) == 0) {
      dVar2 = _atof(*param_1);
      local_c = (float)dVar2;
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty string in string_to_float.\n");
      local_c = 0.0;
    }
  }
  return local_c;
}

