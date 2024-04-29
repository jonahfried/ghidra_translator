
long _string_copy(long *param_1,long param_2,ulong param_3,long param_4)

{
  long local_38;
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_copy.\n");
    local_10 = 0;
  }
  else if (param_2 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The buffer is NULL in string_copy.\n");
    local_10 = 0;
  }
  else if (param_3 < (ulong)param_1[1]) {
    if (((ulong)param_1[1] < param_3 + param_4) || (local_38 = param_4, param_4 == 0)) {
      local_38 = param_1[1] - param_3;
    }
    ___strncpy_chk(param_2,*param_1 + param_3,local_38,0xffffffffffffffff);
    *(undefined *)(param_2 + local_38) = 0;
    local_10 = local_38;
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_copy.\n");
    local_10 = 0;
  }
  return local_10;
}

