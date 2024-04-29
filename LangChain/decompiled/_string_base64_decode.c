
undefined8 _string_base64_decode(long *param_1)

{
  int iVar1;
  void *pvVar2;
  char local_39;
  long local_38;
  ulong local_30;
  int local_28;
  uint local_24;
  undefined8 local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: encodedStr param is null in string_base64_decode\n");
    local_10 = 0;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: dataStr item of encodedStr object is null in string_base64_decode\n");
    local_10 = 0;
  }
  else {
    pvVar2 = _malloc(((ulong)(param_1[1] * 3) >> 2) + 1);
    if (pvVar2 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory for base64 decoding");
      local_10 = 0;
    }
    else {
      local_24 = 0;
      local_28 = -8;
      local_38 = 0;
      for (local_30 = 0;
          (local_30 < (ulong)param_1[1] &&
          (local_39 = *(char *)(*param_1 + local_30), local_39 != '=')); local_30 = local_30 + 1) {
        if ((local_39 < 'A') || ('Z' < local_39)) {
          if (('`' < local_39) && (local_39 < '{')) {
            local_39 = local_39 + -0x47;
            goto LAB_100005e4a;
          }
          if (('/' < local_39) && (local_39 < ':')) {
            local_39 = local_39 + '\x04';
            goto LAB_100005e4a;
          }
          if (local_39 == '+') {
            local_39 = '>';
            goto LAB_100005e4a;
          }
          iVar1 = local_28;
          if (local_39 == '/') {
            local_39 = '?';
            goto LAB_100005e4a;
          }
        }
        else {
          local_39 = local_39 + -0x41;
LAB_100005e4a:
          local_24 = local_24 << 6 | (int)local_39;
          iVar1 = local_28 + 6;
          if (-1 < iVar1) {
            *(char *)((long)pvVar2 + local_38) = (char)((int)local_24 >> ((byte)iVar1 & 0x1f));
            local_38 = local_38 + 1;
            iVar1 = local_28 + -2;
          }
        }
        local_28 = iVar1;
      }
      *(undefined *)((long)pvVar2 + local_38) = 0;
      local_10 = _string_create(pvVar2);
      _free(pvVar2);
    }
  }
  return local_10;
}

