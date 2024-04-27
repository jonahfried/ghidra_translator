
void _string_trim_right(long *param_1)

{
  int iVar1;
  bool bVar2;
  ulong local_18;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_trim_right.\n")
    ;
  }
  else if (param_1[1] != 0) {
    local_18 = param_1[1];
    while( true ) {
      bVar2 = false;
      if (local_18 != 0) {
        iVar1 = _isspace((uint)*(byte *)(*param_1 + (local_18 - 1)));
        bVar2 = iVar1 != 0;
      }
      if (!bVar2) break;
      local_18 = local_18 - 1;
    }
    if (local_18 < (ulong)param_1[1]) {
      *(undefined *)(*param_1 + local_18) = 0;
      param_1[1] = local_18;
    }
  }
  return;
}

