
uchar * _string_to_hex(char *str,long *len)

{
  ulong uVar1;
  undefined local_2b [3];
  ulong local_28;
  uchar *local_20;
  long *local_18;
  uchar *local_10;
  
  local_18 = (long *)str;
  if (str == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_to_hex.\n");
    local_10 = (uchar *)0x0;
  }
  else {
    uVar1 = _string_empty(str);
    if ((uVar1 & 1) == 0) {
      local_20 = (uchar *)_string_create("");
      if (local_20 == (uchar *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_to_hex.\n");
        local_10 = (uchar *)0x0;
      }
      else {
        for (local_28 = 0; local_28 < (ulong)local_18[1]; local_28 = local_28 + 1) {
          ___sprintf_chk(local_2b,0,3,"%02x",*(undefined *)(*local_18 + local_28));
          _string_append(local_20);
        }
        local_10 = local_20;
      }
    }
    else {
      local_10 = (uchar *)_string_create("");
    }
  }
  return local_10;
}

