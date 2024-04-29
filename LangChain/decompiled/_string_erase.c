
void _string_erase(long *param_1,ulong param_2,long param_3)

{
  long local_20;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_erase.\n");
  }
  else if (param_2 < (ulong)param_1[1]) {
    local_20 = param_3;
    if ((ulong)param_1[1] < param_2 + param_3) {
      local_20 = param_1[1] - param_2;
    }
    ___memmove_chk(*param_1 + param_2,*param_1 + param_2 + local_20,
                   ((param_1[1] - param_2) - local_20) + 1,0xffffffffffffffff);
    param_1[1] = param_1[1] - local_20;
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_erase.\n");
  }
  return;
}

