typedef unsigned char   undefined;

typedef pointer64 ImageBaseOffset64;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef int    wchar_t;
typedef unsigned short    word;
typedef ulong __darwin_size_t;

typedef __darwin_size_t size_t;

typedef long __darwin_time_t;

typedef longlong __int64_t;

typedef __int64_t __darwin_off_t;

typedef struct __sFILEX __sFILEX, *P__sFILEX;

struct __sFILEX {
};

typedef struct __sbuf __sbuf, *P__sbuf;

struct __sbuf {
    uchar *_base;
    int _size;
};

typedef struct __sFILE __sFILE, *P__sFILE;

typedef __darwin_off_t fpos_t;

typedef struct __sFILE FILE;

struct __sFILE {
    uchar *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct __sbuf _bf;
    int _lbfsize;
    void *_cookie;
    int (*_close)(void *);
    int (*_read)(void *, char *, int);
    fpos_t (*_seek)(void *, fpos_t, int);
    int (*_write)(void *, char *, int);
    struct __sbuf _ub;
    struct __sFILEX *_extra;
    int _ur;
    uchar _ubuf[3];
    uchar _nbuf[1];
    struct __sbuf _lb;
    int _blksize;
    fpos_t _offset;
};

typedef __darwin_time_t time_t;

typedef struct uuid_command uuid_command, *Puuid_command;

struct uuid_command {
    dword cmd;
    dword cmdsize;
    byte uuid[16];
};

typedef struct lc_str lc_str, *Plc_str;

struct lc_str {
    dword offset;
};

typedef struct section section, *Psection;

struct section {
    char sectname[16];
    char segname[16];
    qword addr;
    qword size;
    dword offset;
    dword align;
    dword reloff;
    dword nrelocs;
    dword flags;
    dword reserved1;
    dword reserved2;
    dword reserved3;
};

typedef struct entry_point_command entry_point_command, *Pentry_point_command;

struct entry_point_command {
    dword cmd;
    dword cmdsize;
    qword entryoff;
    qword stacksize;
};

typedef struct nlist nlist, *Pnlist;

struct nlist {
    dword n_strx;
    byte n_type;
    byte n_sect;
    word n_desc;
    qword n_value;
};

typedef struct segment_command segment_command, *Psegment_command;

struct segment_command {
    dword cmd;
    dword cmdsize;
    char segname[16];
    qword vmaddr;
    qword vmsize;
    qword fileoff;
    qword filesize;
    dword maxprot;
    dword initprot;
    dword nsects;
    dword flags;
};

typedef struct dyld_chained_import dyld_chained_import, *Pdyld_chained_import;

struct dyld_chained_import {
    dword lib_ordinal:8;
    dword weak_import:1;
    dword name_offset:23;
};

typedef struct source_version_command source_version_command, *Psource_version_command;

struct source_version_command {
    dword cmd;
    dword cmdsize;
    qword version;
};

typedef struct mach_header mach_header, *Pmach_header;

struct mach_header {
    dword magic;
    dword cputype;
    dword cpusubtype;
    dword filetype;
    dword ncmds;
    dword sizeofcmds;
    dword flags;
    dword reserved;
};

typedef struct dylinker_command dylinker_command, *Pdylinker_command;

struct dylinker_command {
    dword cmd;
    dword cmdsize;
    struct lc_str name;
};

typedef struct build_tool_version build_tool_version, *Pbuild_tool_version;

struct build_tool_version {
    dword tool;
    dword version;
};

typedef struct build_version_command build_version_command, *Pbuild_version_command;

struct build_version_command {
    dword cmd;
    dword cmdsize;
    dword platform;
    dword minos;
    dword sdk;
    dword ntools;
    struct build_tool_version build_tool_version[][1];
};

typedef struct dylib dylib, *Pdylib;

struct dylib {
    struct lc_str name;
    dword timestamp;
    dword current_version;
    dword compatibility_version;
};

typedef struct dyld_chained_fixups_command dyld_chained_fixups_command, *Pdyld_chained_fixups_command;

struct dyld_chained_fixups_command {
    dword cmd;
    dword cmdsize;
    dword dataoff;
    dword datasize;
};

typedef struct dysymtab_command dysymtab_command, *Pdysymtab_command;

struct dysymtab_command {
    dword cmd;
    dword cmdsize;
    dword ilocalsym;
    dword nlocalsym;
    dword iextdefsym;
    dword nextdefsym;
    dword iundefsym;
    dword nundefsym;
    dword tocoff;
    dword ntoc;
    dword modtaboff;
    dword nmodtab;
    dword extrefsymoff;
    dword nextrefsyms;
    dword indirectsymoff;
    dword nindirectsyms;
    dword extreloff;
    dword nextrel;
    dword locreloff;
    dword nlocrel;
};

typedef struct dyld_chained_fixups_header dyld_chained_fixups_header, *Pdyld_chained_fixups_header;

struct dyld_chained_fixups_header {
    dword fixups_version; // 0
    dword starts_offset; // offset of dyld_chained_starts_in_image in chain_data
    dword imports_offset; // offset of imports table in chain_data
    dword symbols_offset; // offset of symbol strings in chain_data
    dword imports_count; // number of imported symbol names
    dword imports_format; // DYLD_CHAINED_IMPORT*
    dword symbols_format; // 0 => uncompressed, 1 => zlib compressed
};

typedef struct dylib_command dylib_command, *Pdylib_command;

struct dylib_command {
    dword cmd;
    dword cmdsize;
    struct dylib dylib;
};

typedef struct dyld_chained_starts_in_segment dyld_chained_starts_in_segment, *Pdyld_chained_starts_in_segment;

struct dyld_chained_starts_in_segment {
    dword size; // size of this (amount kernel needs to copy)
    word page_size; // 0x1000 or 0x4000
    word pointer_format; // DYLD_CHAINED_PTR_*
    ImageBaseOffset64 segment_offset; // offset in memory to start of segment
    dword max_valid_pointer; // for 32-bit OS, any value beyond this is not a pointer
    word page_count; // how many pages are in array
    word page_starts[1]; // each entry is offset in each page of first element in chain or DYLD_CHAINED_PTR_START_NONE if no fixups on page
};

typedef struct symtab_command symtab_command, *Psymtab_command;

struct symtab_command {
    dword cmd;
    dword cmdsize;
    dword symoff;
    dword nsyms;
    dword stroff;
    dword strsize;
};

typedef struct dyld_chained_starts_in_image dyld_chained_starts_in_image, *Pdyld_chained_starts_in_image;

struct dyld_chained_starts_in_image {
    dword seg_count;
    dword seg_info_offset[5]; // each entry is offset into this struct for that segment followed by pool of dyld_chain_starts_in_segment data
};

typedef struct linkedit_data_command linkedit_data_command, *Plinkedit_data_command;

struct linkedit_data_command {
    dword cmd;
    dword cmdsize;
    dword dataoff;
    dword datasize;
};




long * _string_create(char *param_1)

{
  long *plVar1;
  long lVar2;
  size_t local_30;
  
  plVar1 = (long *)_malloc(0x20);
  if (plVar1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory allocation failed for String object in string_create.\n");
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  if (param_1 == (char *)0x0) {
    local_30 = 0;
  }
  else {
    local_30 = _strlen(param_1);
  }
  plVar1[1] = local_30;
  plVar1[2] = local_30 + 0x20;
  lVar2 = _memory_pool_create(1000000);
  plVar1[3] = lVar2;
  if (plVar1[3] == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool creation failed in string_create.\n");
    _free(plVar1);
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  lVar2 = _memory_pool_allocate(plVar1[3],plVar1[2]);
  *plVar1 = lVar2;
  if (*plVar1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool allocation failed in string_create.\n");
    _memory_pool_destroy(plVar1[3]);
    _free(plVar1);
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  if (param_1 != (char *)0x0) {
    ___strcpy_chk(*plVar1,param_1,0xffffffffffffffff);
  }
  return plVar1;
}



void ** _memory_pool_create(void *param_1)

{
  void *pvVar1;
  void **local_10;
  
  local_10 = (void **)_malloc(0x18);
  if (local_10 != (void **)0x0) {
    pvVar1 = _malloc((size_t)param_1);
    *local_10 = pvVar1;
    if (*local_10 == (void *)0x0) {
      _free(local_10);
      local_10 = (void **)0x0;
    }
    else {
      local_10[1] = param_1;
      local_10[2] = (void *)0x0;
    }
  }
  return local_10;
}



long _memory_pool_allocate(long *param_1,long param_2)

{
  long local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool is NULL in memory_pool_allocate.\n");
    local_10 = 0;
  }
  else if ((ulong)param_1[1] < (ulong)(param_1[2] + param_2)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool out of memory in memory_pool_allocate.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[2];
    param_1[2] = param_2 + param_1[2];
  }
  return local_10;
}



void _memory_pool_destroy(void **param_1)

{
  if (param_1 == (void **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Warning: Attempt to destroy a NULL memory pool in memory_pool_destroy.\n");
  }
  else {
    _free(*param_1);
    _free(param_1);
  }
  return;
}



undefined8 * _string_create_with_pool(undefined8 param_1)

{
  undefined8 *puVar1;
  
  if (_string_create_with_pool_counter == 0) {
    _init_global_memory_pool(param_1);
    _string_create_with_pool_counter = _string_create_with_pool_counter + 1;
  }
  if (_global_pool == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Failed to initialize global memory pool in string_create_with_pool.\n");
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  puVar1 = (undefined8 *)_malloc(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory allocation failed for String object in string_create_with_pool.\n");
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  puVar1[1] = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  puVar1[3] = _global_pool;
  return puVar1;
}



void _init_global_memory_pool(undefined8 param_1)

{
  if (_global_pool == 0) {
    _global_pool = _memory_pool_create(param_1);
    _memoryPoolCreated = 1;
  }
  return;
}



void ** _string_substr(long *param_1,ulong param_2,void *param_3)

{
  void *pvVar1;
  void *local_28;
  void **local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_substr.\n");
    local_10 = (void **)0x0;
  }
  else if (param_2 < (ulong)param_1[1]) {
    local_28 = param_3;
    if ((ulong)param_1[1] < param_2 + (long)param_3) {
      local_28 = (void *)(param_1[1] - param_2);
    }
    local_10 = (void **)_string_create(0);
    if (local_10 == (void **)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed for substring in string_substr.\n");
      local_10 = (void **)0x0;
    }
    else {
      local_10[1] = local_28;
      local_10[2] = (void *)((long)local_28 + 1);
      pvVar1 = _malloc((size_t)local_10[2]);
      *local_10 = pvVar1;
      if (*local_10 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed for dataStr in substring in string_substr.\n");
        _free(local_10);
        local_10 = (void **)0x0;
      }
      else {
        ___strncpy_chk(*local_10,*param_1 + param_2,local_28,0xffffffffffffffff);
        *(undefined *)((long)*local_10 + (long)local_28) = 0;
      }
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_substr.\n")
    ;
    local_10 = (void **)0x0;
  }
  return local_10;
}



bool _string_empty(long param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = *(long *)(param_1 + 8) == 0;
  }
  return bVar1;
}



bool _string_contains(char **param_1,char *param_2)

{
  char *pcVar1;
  bool local_9;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_contains.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The substring is NULL in string_contains.\n"
            );
    local_9 = false;
  }
  else {
    pcVar1 = _strstr(*param_1,param_2);
    local_9 = pcVar1 != (char *)0x0;
  }
  return local_9;
}



int _string_compare(char **param_1,char **param_2)

{
  int local_c;
  
  if ((param_1 == (char **)0x0) || (param_2 == (char **)0x0)) {
    if (param_1 == param_2) {
      local_c = 0;
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: One or both String objects are NULL in string_compare.\n");
      local_c = 1;
      if (param_1 == (char **)0x0) {
        local_c = -1;
      }
    }
  }
  else {
    local_c = _strcmp(*param_1,*param_2);
  }
  return local_c;
}



bool _string_is_equal(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return iVar1 == 0;
}



bool _string_is_less(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return iVar1 < 0;
}



bool _string_is_greater(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return 0 < iVar1;
}



bool _string_is_less_or_equal(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return iVar1 < 1;
}



bool _string_is_greater_or_equal(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return -1 < iVar1;
}



bool _string_is_not_equal(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return iVar1 != 0;
}



undefined _string_is_alpha(long *param_1)

{
  ulong local_20;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    local_9 = 0;
  }
  else {
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if (((*(char *)(*param_1 + local_20) < 'a') || ('z' < *(char *)(*param_1 + local_20))) &&
         ((*(char *)(*param_1 + local_20) < 'A' || ('Z' < *(char *)(*param_1 + local_20))))) {
        return 0;
      }
    }
    local_9 = 1;
  }
  return local_9;
}



undefined _string_is_digit(long *param_1)

{
  ulong local_20;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_is_digit.\n");
    local_9 = 0;
  }
  else {
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if ((*(char *)(*param_1 + local_20) < '0') || ('9' < *(char *)(*param_1 + local_20))) {
        return 0;
      }
    }
    local_9 = 1;
  }
  return local_9;
}



undefined _string_is_upper(long *param_1)

{
  ulong local_20;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_is_upper.\n");
    local_9 = 0;
  }
  else {
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if (('`' < *(char *)(*param_1 + local_20)) && (*(char *)(*param_1 + local_20) < '{')) {
        return 0;
      }
    }
    local_9 = 1;
  }
  return local_9;
}



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



void _string_reverse(long *param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  int local_20;
  int local_1c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_reverse.\n");
  }
  else {
    pvVar1 = _malloc(param_1[1] + 1);
    if (pvVar1 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_reverse.\n");
    }
    else {
      local_1c = (int)param_1[1];
      local_20 = 0;
      while (local_1c = local_1c + -1, -1 < local_1c) {
        *(undefined *)((long)pvVar1 + (long)local_20) = *(undefined *)(*param_1 + (long)local_1c);
        local_20 = local_20 + 1;
      }
      *(undefined *)((long)pvVar1 + param_1[1]) = 0;
      uVar2 = _string_c_str(param_1);
      _string_replace(param_1,uVar2,pvVar1);
      _free(pvVar1);
    }
  }
  return;
}



void _string_replace(char **param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object (str1) is NULL in string_replace.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The oldStr is NULL in string_replace.\n");
  }
  else if (param_3 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The newStr is NULL in string_replace.\n");
  }
  else {
    pcVar1 = _strstr(*param_1,param_2);
    if (pcVar1 == (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Warning: oldStr not found in str1 in string_replace.\n");
    }
    else {
      sVar2 = _strlen(param_2);
      sVar3 = _strlen(param_3);
      sVar4 = _strlen(pcVar1 + sVar2);
      pcVar5 = pcVar1 + sVar4 + (sVar3 - (long)*param_1);
      if (param_1[2] < pcVar5 + 1) {
        pcVar6 = (char *)_memory_pool_allocate(param_1[3],pcVar5 + 1);
        if (pcVar6 == (char *)0x0) {
          return;
        }
        ___memcpy_chk(pcVar6,*param_1,(long)pcVar1 - (long)*param_1,0xffffffffffffffff);
        ___memcpy_chk(pcVar6 + (long)(pcVar1 + (sVar3 - (long)*param_1)),pcVar1 + sVar2,sVar4,
                      0xffffffffffffffff);
        *param_1 = pcVar6;
        param_1[2] = pcVar5 + 1;
      }
      else {
        ___memmove_chk(pcVar1 + sVar3,pcVar1 + sVar2,sVar4,0xffffffffffffffff);
      }
      ___memcpy_chk(pcVar1,param_3,sVar3,0xffffffffffffffff);
      param_1[1] = pcVar5;
    }
  }
  return;
}



char * _string_c_str(char **param_1)

{
  char *local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid input in string_c_str function.\n");
    local_10 = "";
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Uninitialized String in string_c_str function.\n");
    local_10 = "";
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}



void _string_resize(long *param_1,ulong param_2)

{
  long lVar1;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_resize.\n");
  }
  else if (param_2 < (ulong)param_1[1]) {
    param_1[1] = param_2;
    *(undefined *)(*param_1 + param_2) = 0;
  }
  else if ((ulong)param_1[1] < param_2) {
    if ((ulong)param_1[2] <= param_2) {
      lVar1 = _memory_pool_allocate(param_1[3],param_2 + 1);
      if (lVar1 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_resize.\n");
        return;
      }
      ___memcpy_chk(lVar1,*param_1,param_1[1],0xffffffffffffffff);
      *param_1 = lVar1;
      param_1[2] = param_2 + 1;
    }
    ___memset_chk(*param_1 + param_1[1],0,param_2 - param_1[1],0xffffffffffffffff);
    param_1[1] = param_2;
  }
  return;
}



void _string_shrink_to_fit(long *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_shrink_to_fit.\n");
  }
  else if ((param_1[1] + 1 != param_1[2]) && (*param_1 != 0)) {
    lVar1 = param_1[1];
    lVar2 = _memory_pool_allocate(param_1[3],lVar1 + 1);
    if (lVar2 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_shrink_to_fit.\n");
    }
    else {
      ___memcpy_chk(lVar2,*param_1,param_1[1],0xffffffffffffffff);
      *(undefined *)(lVar2 + param_1[1]) = 0;
      *param_1 = lVar2;
      param_1[2] = lVar1 + 1;
    }
  }
  return;
}



void _string_append(long *param_1,char *param_2)

{
  size_t sVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_append.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The strItem is NULL in string_append.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if (sVar1 != 0) {
      if ((ulong)param_1[2] <= param_1[1] + sVar1) {
        lVar2 = param_1[1] + sVar1 + 1;
        lVar3 = _memory_pool_allocate(param_1[3],lVar2);
        if (lVar3 == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Memory allocation failed in string_append.\n");
          return;
        }
        ___memcpy_chk(lVar3,*param_1,param_1[1],0xffffffffffffffff);
        *param_1 = lVar3;
        param_1[2] = lVar2;
      }
      ___strcpy_chk(*param_1 + param_1[1],param_2,0xffffffffffffffff);
      param_1[1] = sVar1 + param_1[1];
    }
  }
  return;
}



void _string_push_back(long *param_1,undefined param_2)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_push_back.\n");
  }
  else {
    if ((ulong)param_1[2] <= param_1[1] + 1U) {
      lVar1 = param_1[2];
      lVar2 = _memory_pool_allocate(param_1[3],lVar1 << 1);
      if (lVar2 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_push_back.\n");
        return;
      }
      if (*param_1 != 0) {
        ___memcpy_chk(lVar2,*param_1,param_1[1],0xffffffffffffffff);
      }
      *param_1 = lVar2;
      param_1[2] = lVar1 << 1;
    }
    *(undefined *)(*param_1 + param_1[1]) = param_2;
    param_1[1] = param_1[1] + 1;
    *(undefined *)(*param_1 + param_1[1]) = 0;
  }
  return;
}



void _string_assign(long *param_1,char *param_2)

{
  size_t sVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_assign.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The newStr is NULL in string_assign.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if ((ulong)param_1[2] < sVar1 + 1) {
      lVar2 = _memory_pool_allocate(param_1[3],sVar1 + 1);
      if (lVar2 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_assign.\n");
        return;
      }
      *param_1 = lVar2;
      param_1[2] = sVar1 + 1;
    }
    ___strcpy_chk(*param_1,param_2,0xffffffffffffffff);
    param_1[1] = sVar1;
  }
  return;
}



void _string_insert(long *param_1,ulong param_2,char *param_3)

{
  size_t sVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_insert.\n");
  }
  else if (param_3 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The strItem is NULL in string_insert.\n");
  }
  else if ((ulong)param_1[1] < param_2) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_insert.\n")
    ;
  }
  else {
    sVar1 = _strlen(param_3);
    lVar2 = param_1[1] + sVar1;
    if ((ulong)param_1[2] < lVar2 + 1U) {
      lVar3 = _memory_pool_allocate(param_1[3],lVar2 + 1);
      if (lVar3 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_insert.\n");
        return;
      }
      ___memcpy_chk(lVar3,*param_1,param_2,0xffffffffffffffff);
      ___memcpy_chk(lVar3 + param_2 + sVar1,*param_1 + param_2,param_1[1] - param_2,
                    0xffffffffffffffff);
      *param_1 = lVar3;
      param_1[2] = lVar2 + 1;
    }
    else {
      ___memmove_chk(*param_1 + param_2 + sVar1,*param_1 + param_2,param_1[1] - param_2,
                     0xffffffffffffffff);
    }
    ___memcpy_chk(*param_1 + param_2,param_3,sVar1,0xffffffffffffffff);
    param_1[1] = lVar2;
  }
  return;
}



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



void _string_swap(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (undefined8 *)0x0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: One or both String objects are NULL in string_swap.\n");
  }
  else {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    *param_2 = uVar1;
    param_2[1] = uVar2;
    param_2[2] = uVar3;
    param_2[3] = uVar4;
  }
  return;
}



void _string_pop_back(long *param_1)

{
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_pop_back.\n");
  }
  else if (param_1[1] == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Warning: Attempt to pop back from an empty string in string_pop_back.\n");
  }
  else {
    *(undefined *)(*param_1 + param_1[1] + -1) = 0;
    param_1[1] = param_1[1] + -1;
  }
  return;
}



void _string_deallocate(void *param_1)

{
  if (param_1 == (void *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Warning: Attempt to deallocate a NULL String object in string_deallocate.\n");
  }
  else {
    if (*(long *)((long)param_1 + 0x18) != 0) {
      _memory_pool_destroy(*(undefined8 *)((long)param_1 + 0x18));
      *(undefined8 *)((long)param_1 + 0x18) = 0;
    }
    _free(param_1);
    if ((_memoryPoolCreated & 1) != 0) {
      _destroy_global_memory_pool();
    }
  }
  return;
}



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



long _string_back(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (param_1[1] == 0)) {
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1] + -1;
  }
  return local_10;
}



undefined8 _string_front(undefined8 *param_1)

{
  undefined8 local_10;
  
  if ((param_1 == (undefined8 *)0x0) || (param_1[1] == 0)) {
    local_10 = 0;
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}



undefined8 _string_length(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_length.\n");
    local_10 = 0;
  }
  else {
    local_10 = *(undefined8 *)(param_1 + 8);
  }
  return local_10;
}



undefined8 _string_capacity(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_capacity.\n");
    local_10 = 0;
  }
  else {
    local_10 = *(undefined8 *)(param_1 + 0x10);
  }
  return local_10;
}



undefined8 _string_max_size(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_max_size.\n");
    local_10 = 0;
  }
  else {
    local_10 = 0xffffffffffffffff;
  }
  return local_10;
}



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



int _string_find(long *param_1,char *param_2,ulong param_3)

{
  char *pcVar1;
  int local_c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find.\n");
    local_c = -1;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The buffer is NULL in string_find.\n");
    local_c = -1;
  }
  else if (param_3 < (ulong)param_1[1]) {
    pcVar1 = _strstr((char *)(*param_1 + param_3),param_2);
    if (pcVar1 == (char *)0x0) {
      local_c = -1;
    }
    else {
      local_c = (int)pcVar1 - (int)*param_1;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_find.\n");
    local_c = -1;
  }
  return local_c;
}



int _string_rfind(long *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  ulong local_40;
  int local_34;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_rfind.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The buffer is NULL in string_rfind.\n");
  }
  else {
    sVar2 = _strlen(param_2);
    if (sVar2 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The buffer is empty in string_rfind.\n");
    }
    else if (param_3 < sVar2 - 1) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position is too small in string_rfind.\n")
      ;
    }
    else {
      local_40 = param_3;
      if ((ulong)param_1[1] <= param_3) {
        local_40 = param_1[1] - 1;
      }
      for (local_34 = (int)local_40; -1 < local_34; local_34 = local_34 + -1) {
        iVar1 = _strncmp((char *)(*param_1 + (long)local_34),param_2,sVar2);
        if (iVar1 == 0) {
          return local_34;
        }
      }
    }
  }
  return -1;
}



int _string_find_first_of(long *param_1,char *param_2,ulong param_3)

{
  char *pcVar1;
  int local_c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_first_of.\n");
    local_c = -1;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_first_of.\n");
    local_c = -1;
  }
  else if (param_3 < (ulong)param_1[1]) {
    pcVar1 = _strstr((char *)(*param_1 + param_3),param_2);
    if (pcVar1 == (char *)0x0) {
      local_c = -1;
    }
    else {
      local_c = (int)pcVar1 - (int)*param_1;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Position out of bounds in string_find_first_of.\n");
    local_c = -1;
  }
  return local_c;
}



int _string_find_last_of(char **param_1,char *param_2,char *param_3)

{
  bool bVar1;
  char *local_38;
  int local_2c;
  int local_c;
  
  if ((param_1 == (char **)0x0) || (*param_1 == (char *)0x0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_last_of.\n");
    local_c = -1;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_last_of.\n");
    local_c = -1;
  }
  else if (param_3 < param_1[1]) {
    local_2c = -1;
    local_38 = _strstr(*param_1,param_2);
    while( true ) {
      bVar1 = false;
      if (local_38 != (char *)0x0) {
        bVar1 = local_38 + -(long)*param_1 <= param_3;
      }
      if (!bVar1) break;
      local_2c = (int)local_38 - (int)*param_1;
      local_38 = _strstr(local_38 + 1,param_2);
    }
    local_c = local_2c;
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Position out of bounds in string_find_last_of.\n");
    local_c = -1;
  }
  return local_c;
}



undefined4 _string_find_first_not_of(long *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  ulong local_38;
  undefined4 local_c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  else if (param_3 < (ulong)param_1[1]) {
    sVar2 = _strlen(param_2);
    local_38 = param_3;
    if (sVar2 == 0) {
      local_c = (undefined4)param_3;
    }
    else {
      for (; local_38 <= param_1[1] - sVar2; local_38 = local_38 + 1) {
        iVar1 = _strncmp((char *)(*param_1 + local_38),param_2,sVar2);
        if (iVar1 != 0) {
          return (int)local_38;
        }
      }
      local_c = 0xffffffff;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Position out of bounds in string_find_first_not_of.\n");
    local_c = 0xffffffff;
  }
  return local_c;
}



int _string_find_last_not_of(long *param_1,char *param_2,ulong param_3)

{
  int iVar1;
  size_t sVar2;
  ulong local_40;
  int local_34;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_last_not_of.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_last_not_of.\n");
  }
  else {
    sVar2 = _strlen(param_2);
    if (sVar2 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: The buffer is empty in string_find_last_not_of.\n");
    }
    else if (param_3 < sVar2 - 1) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Position is too small in string_find_last_not_of.\n");
    }
    else {
      local_40 = param_3;
      if (param_1[1] - sVar2 <= param_3) {
        local_40 = param_1[1] - sVar2;
      }
      for (local_34 = (int)local_40; -1 < local_34; local_34 = local_34 + -1) {
        iVar1 = _strncmp((char *)(*param_1 + (long)local_34),param_2,sVar2);
        if (iVar1 != 0) {
          return local_34;
        }
      }
    }
  }
  return -1;
}



long _string_data(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_data function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}



char * _string_begin(char **param_1)

{
  char *local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid input in string_begin function.\n");
    local_10 = "";
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Uninitialized String in string_begin function.\n");
    local_10 = "";
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}



long _string_end(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_end function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1];
  }
  return local_10;
}



long _string_rbegin(long *param_1)

{
  long local_10;
  
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input, uninitialized, or empty String in string_rbegin function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1] + -1;
  }
  return local_10;
}



long _string_rend(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_rend function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + -1;
  }
  return local_10;
}



long _string_cbegin(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_cbegin function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1;
  }
  return local_10;
}



long _string_cend(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_cend function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1];
  }
  return local_10;
}



long _string_crbegin(long *param_1)

{
  long local_10;
  
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input, uninitialized, or empty String in string_crbegin function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1] + -1;
  }
  return local_10;
}



long _string_crend(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input or uninitialized String in string_crend function.\n");
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + -1;
  }
  return local_10;
}



void _string_clear(long *param_1)

{
  if ((param_1 != (long *)0x0) && (param_1[1] = 0, *param_1 != 0)) {
    *(undefined *)*param_1 = 0;
  }
  _fprintf(*(FILE **)PTR____stderrp_10000a038,
           "Info : String object is null no need to clear in string_clear.\n");
  return;
}



void * _string_to_upper(long *param_1)

{
  int iVar1;
  ulong local_28;
  void *local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input \'str\' is NULL in string_to_upper function.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_10 = _malloc(param_1[1] + 1);
    if (local_10 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory for string_to_upper function.\n");
                    // WARNING: Subroutine does not return
      _exit(-1);
    }
    for (local_28 = 0; local_28 < (ulong)param_1[1]; local_28 = local_28 + 1) {
      iVar1 = _isalpha((int)*(char *)(*param_1 + local_28));
      if (((iVar1 == 0) || (*(char *)(*param_1 + local_28) < 'a')) ||
         ('z' < *(char *)(*param_1 + local_28))) {
        *(undefined *)((long)local_10 + local_28) = *(undefined *)(*param_1 + local_28);
      }
      else {
        iVar1 = _toupper((int)*(char *)(*param_1 + local_28));
        *(char *)((long)local_10 + local_28) = (char)iVar1;
      }
    }
    *(undefined *)((long)local_10 + param_1[1]) = 0;
  }
  return local_10;
}



void * _string_to_lower(long *param_1)

{
  int iVar1;
  ulong local_28;
  void *local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input \'str\' is NULL in string_to_lower function.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_10 = _malloc(param_1[1] + 1);
    if (local_10 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory for string_to_lower function.\n");
                    // WARNING: Subroutine does not return
      _exit(-1);
    }
    for (local_28 = 0; local_28 < (ulong)param_1[1]; local_28 = local_28 + 1) {
      iVar1 = _isalpha((int)*(char *)(*param_1 + local_28));
      if (((iVar1 == 0) || (*(char *)(*param_1 + local_28) < 'A')) ||
         ('Z' < *(char *)(*param_1 + local_28))) {
        *(undefined *)((long)local_10 + local_28) = *(undefined *)(*param_1 + local_28);
      }
      else {
        iVar1 = _tolower((int)*(char *)(*param_1 + local_28));
        *(char *)((long)local_10 + local_28) = (char)iVar1;
      }
    }
    *(undefined *)((long)local_10 + param_1[1]) = 0;
  }
  return local_10;
}



undefined _string_set_pool_size(long *param_1,long param_2)

{
  long lVar1;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input - \'str\' is NULL in string_set_pool_size.\n");
    local_9 = 0;
  }
  else if (param_2 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input - \'newSize\' is zero in string_set_pool_size.\n");
    local_9 = 0;
  }
  else {
    if (param_1[3] != 0) {
      _memory_pool_destroy(param_1[3]);
      param_1[3] = 0;
    }
    lVar1 = _memory_pool_create(param_2);
    param_1[3] = lVar1;
    if (param_1[3] == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to create a new memory pool in string_set_pool_size.\n");
      local_9 = 0;
    }
    else {
      if ((param_1[1] != 0) && (*param_1 != 0)) {
        lVar1 = _memory_pool_allocate(param_1[3],param_1[1] + 1);
        if (lVar1 == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Failed to allocate memory for string data in the new pool in string_set_pool_size.\n"
                  );
          _memory_pool_destroy(param_1[3]);
          param_1[3] = 0;
          return 0;
        }
        ___memcpy_chk(lVar1,*param_1,param_1[1],0xffffffffffffffff);
        *(undefined *)(lVar1 + param_1[1]) = 0;
        *param_1 = lVar1;
      }
      local_9 = 1;
    }
  }
  return local_9;
}



void _string_concatenate(long param_1,undefined8 *param_2)

{
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object \'str1\' in string_concatenate.\n");
  }
  else if (param_2 == (undefined8 *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object \'str2\' in string_concatenate.\n");
  }
  else {
    _string_append(param_1,*param_2);
  }
  return;
}



void _string_trim_left(long *param_1)

{
  int iVar1;
  bool bVar2;
  ulong local_18;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_trim_left.\n");
  }
  else if (param_1[1] != 0) {
    local_18 = 0;
    while( true ) {
      bVar2 = false;
      if (local_18 < (ulong)param_1[1]) {
        iVar1 = _isspace((uint)*(byte *)(*param_1 + local_18));
        bVar2 = iVar1 != 0;
      }
      if (!bVar2) break;
      local_18 = local_18 + 1;
    }
    if (local_18 != 0) {
      ___memmove_chk(*param_1,*param_1 + local_18,param_1[1] - local_18,0xffffffffffffffff);
      param_1[1] = param_1[1] - local_18;
      *(undefined *)(*param_1 + param_1[1]) = 0;
    }
  }
  return;
}



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



void _string_trim(long param_1)

{
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_trim.\n");
  }
  else {
    _string_trim_left(param_1);
    _string_trim_right(param_1);
  }
  return;
}



void * _string_split(undefined8 *param_1,char *param_2,undefined4 *param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  ulong local_58;
  ulong local_50;
  char *local_40;
  ulong local_30;
  void *local_10;
  
  if (param_1 == (undefined8 *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_split.\n");
    local_10 = (void *)0x0;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null delimiter in string_split.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_30 = 0;
    pcVar1 = (char *)_string_strdup(*param_1);
    if (pcVar1 == (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_split.\n");
      local_10 = (void *)0x0;
    }
    else {
      local_40 = _strtok(pcVar1,param_2);
      while (local_40 != (char *)0x0) {
        local_30 = local_30 + 1;
        local_40 = _strtok((char *)0x0,param_2);
      }
      _free(pcVar1);
      if (local_30 == 0) {
        local_10 = (void *)0x0;
      }
      else {
        local_10 = _malloc(local_30 << 3);
        if (local_10 == (void *)0x0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Memory allocation failed for splits in string_split.\n");
          local_10 = (void *)0x0;
        }
        else {
          pcVar1 = (char *)_string_strdup(*param_1);
          if (pcVar1 == (char *)0x0) {
            _fprintf(*(FILE **)PTR____stderrp_10000a038,
                     "Error: Memory allocation failed in string_split.\n");
            _free(local_10);
            local_10 = (void *)0x0;
          }
          else {
            local_40 = _strtok(pcVar1,param_2);
            local_50 = 0;
            while (local_40 != (char *)0x0 && local_50 < local_30) {
              uVar2 = _string_create(local_40);
              *(undefined8 *)((long)local_10 + local_50 * 8) = uVar2;
              if (*(long *)((long)local_10 + local_50 * 8) == 0) {
                _fprintf(*(FILE **)PTR____stderrp_10000a038,
                         "Error: Failed to create string in string_split.\n");
                for (local_58 = 0; local_58 < local_50; local_58 = local_58 + 1) {
                  _string_deallocate(*(undefined8 *)((long)local_10 + local_58 * 8));
                }
                _free(local_10);
                _free(pcVar1);
                return (void *)0x0;
              }
              local_50 = local_50 + 1;
              local_40 = _strtok((char *)0x0,param_2);
            }
            _free(pcVar1);
            *param_3 = (int)local_30;
          }
        }
      }
    }
  }
  return local_10;
}



void * _string_strdup(char *param_1)

{
  size_t sVar1;
  void *local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Parameter \'s\' is NULL in string_strdup.\n"
            );
    local_10 = (void *)0x0;
  }
  else {
    sVar1 = _strlen(param_1);
    local_10 = _malloc(sVar1 + 1);
    if (local_10 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_strdup for string: %s\n",param_1);
      local_10 = (void *)0x0;
    }
    else {
      ___strcpy_chk(local_10,param_1,0xffffffffffffffff);
    }
  }
  return local_10;
}



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



void _string_replace_all(char **param_1,char *param_2,long param_3)

{
  undefined8 *puVar1;
  char *pcVar2;
  size_t sVar3;
  char *local_30;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_replace_all.\n"
            );
  }
  else if ((param_2 == (char *)0x0) || (param_3 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_replace_all.\n");
  }
  else {
    puVar1 = (undefined8 *)_string_create("");
    if (puVar1 == (undefined8 *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_replace_all.\n");
    }
    else {
      local_30 = *param_1;
      while( true ) {
        pcVar2 = _strstr(local_30,param_2);
        if (pcVar2 == (char *)0x0) break;
        *pcVar2 = '\0';
        _string_append(puVar1,local_30);
        _string_append(puVar1,param_3);
        sVar3 = _strlen(param_2);
        local_30 = pcVar2 + sVar3;
      }
      _string_append(puVar1,local_30);
      _string_assign(param_1,*puVar1);
      _string_deallocate(puVar1);
    }
  }
  return;
}



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



double _string_to_double(char **param_1)

{
  ulong uVar1;
  double local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_to_double.\n");
    local_10 = 0.0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if ((uVar1 & 1) == 0) {
      local_10 = _strtod(*param_1,(char **)0x0);
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty string in string_to_double.\n");
      local_10 = 0.0;
    }
  }
  return local_10;
}



void _string_pad_left(void **param_1,void *param_2,char param_3)

{
  long lVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_1 == (void **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_pad_left.\n");
  }
  else if (param_1[1] < param_2) {
    lVar1 = (long)param_2 - (long)param_1[1];
    pvVar2 = (void *)((long)param_1[1] + lVar1);
    pvVar3 = _malloc((long)pvVar2 + 1);
    if (pvVar3 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory in string_pad_left.\n");
    }
    else {
      ___memset_chk(pvVar3,(int)param_3,lVar1,0xffffffffffffffff);
      ___memcpy_chk((long)pvVar3 + lVar1,*param_1,param_1[1],0xffffffffffffffff);
      *(undefined *)((long)pvVar3 + (long)pvVar2) = 0;
      _free(*param_1);
      *param_1 = pvVar3;
      param_1[1] = pvVar2;
      param_1[2] = (void *)((long)pvVar2 + 1);
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Size of String object is bigger or equal that total Length in string_pad_left.\n"
            );
  }
  return;
}



void _string_pad_right(void **param_1,void *param_2,char param_3)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_1 == (void **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_pad_right.\n");
  }
  else if (param_1[1] < param_2) {
    pvVar1 = param_1[1];
    pvVar2 = (void *)((long)param_1[1] + ((long)param_2 - (long)pvVar1));
    pvVar3 = _realloc(*param_1,(long)pvVar2 + 1);
    if (pvVar3 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory in string_pad_right.\n");
    }
    else {
      ___memset_chk((long)pvVar3 + (long)param_1[1],(int)param_3,(long)param_2 - (long)pvVar1,
                    0xffffffffffffffff);
      *(undefined *)((long)pvVar3 + (long)pvVar2) = 0;
      *param_1 = pvVar3;
      param_1[1] = pvVar2;
      param_1[2] = (void *)((long)pvVar2 + 1);
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Size of String object is bigger or equal that total Length in string_pad_right.\n"
            );
  }
  return;
}



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



long _string_from_hex(long *param_1)

{
  ulong uVar1;
  long lVar2;
  char local_2b;
  undefined local_2a;
  undefined local_29;
  ulong local_28;
  long local_20;
  long *local_18;
  long local_10;
  
  local_18 = param_1;
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_from_hex.\n");
    local_10 = 0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if (((uVar1 & 1) == 0) && ((local_18[1] & 1U) == 0)) {
      local_20 = _string_create("");
      if (local_20 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_from_hex.\n");
        local_10 = 0;
      }
      else {
        for (local_28 = 0; local_28 < (ulong)local_18[1]; local_28 = local_28 + 2) {
          local_2b = *(char *)(*local_18 + local_28);
          local_2a = *(undefined *)(*local_18 + 1 + local_28);
          local_29 = 0;
          lVar2 = _strtol(&local_2b,(char **)0x0,0x10);
          _string_push_back(local_20,(int)(char)lVar2);
        }
        local_10 = local_20;
      }
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid hex string in string_from_hex.\n")
      ;
      local_10 = 0;
    }
  }
  return local_10;
}



long _string_count(char **param_1,char *param_2)

{
  size_t sVar1;
  char *local_30;
  long local_28;
  long local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_count.\n");
    local_10 = 0;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_count.\n");
    local_10 = 0;
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null data string in String object in string_count.\n");
    local_10 = 0;
  }
  else {
    local_28 = 0;
    local_30 = *param_1;
    while( true ) {
      local_30 = _strstr(local_30,param_2);
      if (local_30 == (char *)0x0) break;
      local_28 = local_28 + 1;
      sVar1 = _strlen(param_2);
      local_30 = local_30 + sVar1;
    }
    local_10 = local_28;
  }
  return local_10;
}



void _string_remove(char **param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  char *local_28;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_remove.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_remove.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null data string in String object in string_remove.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if (sVar1 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty substring in string_remove.\n");
    }
    else {
      sVar1 = _strlen(param_2);
      local_28 = *param_1;
      while( true ) {
        local_28 = _strstr(local_28,param_2);
        if (local_28 == (char *)0x0) break;
        sVar2 = _strlen(local_28 + sVar1);
        ___memmove_chk(local_28,local_28 + sVar1,sVar2 + 1,0xffffffffffffffff);
      }
    }
  }
  return;
}



void _string_remove_range(long *param_1,ulong param_2,ulong param_3)

{
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object in string_remove_range.\n");
  }
  else if ((param_2 < param_3) && (param_3 <= (ulong)param_1[1])) {
    ___memmove_chk(*param_1 + param_2,*param_1 + param_3,(param_1[1] - param_3) + 1,
                   0xffffffffffffffff);
    param_1[1] = param_1[1] - (param_3 - param_2);
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid range in string_remove_range.\n");
  }
  return;
}



undefined8 _string_from_int(undefined4 param_1)

{
  undefined8 uVar1;
  undefined local_1c [12];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___sprintf_chk(local_1c,0,0xc,"%d",param_1);
  uVar1 = _string_create(local_1c);
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



void * _string_from_int_cstr(undefined4 param_1)

{
  size_t sVar1;
  void *pvVar2;
  char local_1c [12];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___sprintf_chk(local_1c,0,0xc,"%d",param_1);
  sVar1 = _strlen(local_1c);
  pvVar2 = _malloc(sVar1 + 1);
  if (pvVar2 != (void *)0x0) {
    ___strcpy_chk(pvVar2,local_1c,0xffffffffffffffff);
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return pvVar2;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



undefined8 _string_from_float(float param_1)

{
  undefined8 uVar1;
  undefined local_38 [40];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___sprintf_chk((double)param_1,local_38,0,0x20,"%f");
  uVar1 = _string_create(local_38);
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



undefined8 _string_from_double(undefined8 param_1)

{
  undefined8 uVar1;
  undefined local_38 [40];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___snprintf_chk(param_1,local_38,0x20,0,0x20,"%f");
  uVar1 = _string_create(local_38);
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



void * _string_tokenize(undefined8 *param_1,char *param_2,undefined4 *param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  ulong local_58;
  ulong local_50;
  char *local_40;
  ulong local_30;
  void *local_10;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (char *)0x0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid input in string_tokenize.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_30 = 0;
    pcVar1 = (char *)_string_strdup(*param_1);
    if (pcVar1 == (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_tokenize.\n");
      local_10 = (void *)0x0;
    }
    else {
      local_40 = _strtok(pcVar1,param_2);
      while (local_40 != (char *)0x0) {
        local_30 = local_30 + 1;
        local_40 = _strtok((char *)0x0,param_2);
      }
      _free(pcVar1);
      local_10 = _malloc(local_30 << 3);
      if (local_10 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed for tokens in string_tokenize.\n");
        local_10 = (void *)0x0;
      }
      else {
        pcVar1 = (char *)_string_strdup(*param_1);
        if (pcVar1 == (char *)0x0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Memory allocation failed in string_tokenize.\n");
          _free(local_10);
          local_10 = (void *)0x0;
        }
        else {
          local_40 = _strtok(pcVar1,param_2);
          local_50 = 0;
          while (local_40 != (char *)0x0 && local_50 < local_30) {
            uVar2 = _string_create(local_40);
            *(undefined8 *)((long)local_10 + local_50 * 8) = uVar2;
            if (*(long *)((long)local_10 + local_50 * 8) == 0) {
              _fprintf(*(FILE **)PTR____stderrp_10000a038,
                       "Error: string_create failed in string_tokenize.\n");
              for (local_58 = 0; local_58 < local_50; local_58 = local_58 + 1) {
                _string_deallocate(*(undefined8 *)((long)local_10 + local_58 * 8));
              }
              _free(local_10);
              _free(pcVar1);
              return (void *)0x0;
            }
            local_50 = local_50 + 1;
            local_40 = _strtok((char *)0x0,param_2);
          }
          _free(pcVar1);
          *param_3 = (int)local_30;
        }
      }
    }
  }
  return local_10;
}



int _string_compare_ignore_case(char **param_1,char **param_2)

{
  int local_c;
  
  if ((param_1 == (char **)0x0) || (param_2 == (char **)0x0)) {
    if (param_1 == param_2) {
      local_c = 0;
    }
    else {
      local_c = 1;
      if (param_1 == (char **)0x0) {
        local_c = -1;
      }
    }
  }
  else if ((*param_1 == (char *)0x0) || (*param_2 == (char *)0x0)) {
    if (*param_1 == *param_2) {
      local_c = 0;
    }
    else {
      local_c = 1;
      if (*param_1 == (char *)0x0) {
        local_c = -1;
      }
    }
  }
  else {
    local_c = _strcasecmp(*param_1,*param_2);
  }
  return local_c;
}



long _string_base64_encode(long *param_1)

{
  ulong local_30;
  int local_28;
  int local_24;
  long local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_baes64_encode.\n");
    local_10 = 0;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_base64_encode.\n");
    local_10 = 0;
  }
  else {
    local_10 = _string_create("");
    local_24 = 0;
    local_28 = -6;
    for (local_30 = 0; local_30 < (ulong)param_1[1]; local_30 = local_30 + 1) {
      local_24 = local_24 * 0x100 + (uint)*(byte *)(*param_1 + local_30);
      for (local_28 = local_28 + 8; -1 < local_28; local_28 = local_28 + -6) {
        _string_push_back(local_10,(int)(char)_base64_chars
                                              [(int)(local_24 >> ((byte)local_28 & 0x1f) & 0x3f)]);
      }
    }
    if (-6 < local_28) {
      _string_push_back(local_10,(int)(char)_base64_chars
                                            [(int)((local_24 << 8) >> ((char)local_28 + 8U & 0x1f) &
                                                  0x3f)]);
    }
    while ((*(ulong *)(local_10 + 8) & 3) != 0) {
      _string_push_back(local_10,0x3d);
    }
  }
  return local_10;
}



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



void _string_format(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                   long param_9,long param_10,undefined8 param_11,undefined8 param_12,
                   undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined local_f8 [16];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_68;
  undefined4 local_58;
  void *local_48;
  int local_3c;
  long local_38;
  long local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_c8 = param_1;
    local_b8 = param_2;
    local_a8 = param_3;
    local_98 = param_4;
    local_88 = param_5;
    local_78 = param_6;
    local_68 = param_7;
    local_58 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_e8 = param_11;
  local_e0 = param_12;
  local_d8 = param_13;
  local_d0 = param_14;
  local_38 = param_10;
  local_30 = param_9;
  if (param_9 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_format.\n");
  }
  else if (param_10 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The format string is NULL in string_format.\n");
  }
  else {
    local_18 = local_f8;
    local_20 = &stack0x00000008;
    local_24 = 0x30;
    local_28 = 0x10;
    local_3c = ___vsnprintf_chk(0,0,0,0xffffffffffffffff,param_10,&local_28);
    if (local_3c < 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: vsnprintf failed in string_format.\n");
    }
    else {
      local_48 = _malloc((long)(local_3c + 1));
      if (local_48 == (void *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Failed to allocate memory in string_format.\n");
      }
      else {
        ___vsnprintf_chk(local_48,(long)(local_3c + 1),0,0xffffffffffffffff,local_38,&local_28);
        _string_assign(local_30,local_48);
        _free(local_48);
      }
    }
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



undefined8 _string_repeat(long *param_1,ulong param_2)

{
  undefined *puVar1;
  ulong local_40;
  undefined *local_38;
  undefined8 local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_repeat.\n");
    local_10 = 0;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_repeat.\n");
    local_10 = 0;
  }
  else {
    puVar1 = (undefined *)_malloc(param_1[1] * param_2 + 1);
    if (puVar1 == (undefined *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Failed to allocate memory in string_repeat\n");
      local_10 = 0;
    }
    else {
      local_38 = puVar1;
      for (local_40 = 0; local_40 < param_2; local_40 = local_40 + 1) {
        ___memcpy_chk(local_38,*param_1,param_1[1],0xffffffffffffffff);
        local_38 = local_38 + param_1[1];
      }
      *local_38 = 0;
      local_10 = _string_create(puVar1);
      _free(puVar1);
    }
  }
  return local_10;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined8
_string_join_variadic
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,ulong param_9,
          undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
          undefined8 param_14)

{
  char in_AL;
  long *local_158;
  long *local_140;
  long local_128 [4];
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_e8;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined8 local_78;
  undefined8 *local_70;
  ulong local_68;
  undefined *local_60;
  undefined *local_58;
  long local_50;
  ulong local_48;
  long local_40;
  ulong local_38;
  undefined8 local_30;
  uint local_28;
  undefined4 local_24;
  long *local_20;
  long *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_f8 = param_1;
    local_e8 = param_2;
    local_d8 = param_3;
    local_c8 = param_4;
    local_b8 = param_5;
    local_a8 = param_6;
    local_98 = param_7;
    local_88 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_18 = local_128;
  local_20 = (long *)&stack0x00000008;
  local_24 = 0x30;
  local_28 = 8;
  local_40 = 0;
  for (local_48 = 0; local_48 < param_9; local_48 = local_48 + 1) {
    if (local_28 < 0x29) {
      local_140 = (long *)((long)local_18 + (long)(int)local_28);
      local_28 = local_28 + 8;
    }
    else {
      local_140 = local_20;
      local_20 = local_20 + 1;
    }
    local_50 = *local_140;
    local_40 = *(long *)(local_50 + 8) + local_40;
  }
  local_128[1] = param_10;
  local_128[2] = param_11;
  local_128[3] = param_12;
  local_108 = param_13;
  local_100 = param_14;
  local_38 = param_9;
  local_58 = (undefined *)_malloc(local_40 + 1);
  if (local_58 == (undefined *)0x0) {
    _perror("Failed to allocate memory in string_join_variadic");
    local_30 = 0;
  }
  else {
    local_18 = local_128;
    local_20 = (long *)&stack0x00000008;
    local_24 = 0x30;
    local_28 = 8;
    local_60 = local_58;
    for (local_68 = 0; local_68 < local_38; local_68 = local_68 + 1) {
      if (local_28 < 0x29) {
        local_158 = (long *)((long)local_18 + (long)(int)local_28);
        local_28 = local_28 + 8;
      }
      else {
        local_158 = local_20;
        local_20 = local_20 + 1;
      }
      local_70 = (undefined8 *)*local_158;
      ___memcpy_chk(local_60,*local_70,local_70[1],0xffffffffffffffff);
      local_60 = local_60 + local_70[1];
    }
    *local_60 = 0;
    local_78 = _string_create(local_58);
    _free(local_58);
    local_30 = local_78;
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return local_30;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



void _string_trim_characters(char **param_1,char *param_2)

{
  char *pcVar1;
  bool bVar2;
  char *local_28;
  char *local_20;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_trim_characters.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_trim_characters.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The chars parameter is NULL in string_trim_characters.\n");
  }
  else {
    local_20 = *param_1;
    local_28 = *param_1 + (long)param_1[1] + -1;
    while( true ) {
      bVar2 = false;
      if (local_20 <= local_28) {
        pcVar1 = _strchr(param_2,(int)*local_20);
        bVar2 = pcVar1 != (char *)0x0;
      }
      if (!bVar2) break;
      local_20 = local_20 + 1;
    }
    while( true ) {
      bVar2 = false;
      if (local_20 < local_28) {
        pcVar1 = _strchr(param_2,(int)*local_28);
        bVar2 = pcVar1 != (char *)0x0;
      }
      if (!bVar2) break;
      local_28 = local_28 + -1;
    }
    local_28 = local_28 + (1 - (long)local_20);
    ___memmove_chk(*param_1,local_20,local_28,0xffffffffffffffff);
    (*param_1)[(long)local_28] = '\0';
    param_1[1] = local_28;
  }
  return;
}



void _string_shuffle(char **param_1)

{
  char cVar1;
  int iVar2;
  time_t tVar3;
  ulong uVar4;
  ulong local_20;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_shuffle.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_shuffle.\n");
  }
  else {
    tVar3 = _time((time_t *)0x0);
    _srand((uint)tVar3);
    uVar4 = _strlen(*param_1);
    while (local_20 = uVar4 - 1, local_20 != 0) {
      iVar2 = _rand();
      cVar1 = (*param_1)[local_20];
      (*param_1)[local_20] = (*param_1)[(ulong)(long)iVar2 % uVar4];
      (*param_1)[(ulong)(long)iVar2 % uVar4] = cVar1;
      uVar4 = local_20;
    }
  }
  return;
}



void _string_to_title(long *param_1)

{
  bool bVar1;
  int iVar2;
  ulong local_20;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_to_title.\n");
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_to_title.\n");
  }
  else {
    bVar1 = true;
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if ((bVar1) && (iVar2 = _isalpha((int)*(char *)(*param_1 + local_20)), iVar2 != 0)) {
        iVar2 = _toupper((int)*(char *)(*param_1 + local_20));
        *(char *)(*param_1 + local_20) = (char)iVar2;
        bVar1 = false;
      }
      else {
        iVar2 = _isalpha((int)*(char *)(*param_1 + local_20));
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          iVar2 = _tolower((int)*(char *)(*param_1 + local_20));
          *(char *)(*param_1 + local_20) = (char)iVar2;
        }
      }
    }
  }
  return;
}



void _string_to_capitalize(char **param_1)

{
  int iVar1;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_to_capitalize.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_to_capitalize.\n");
  }
  else if (param_1[1] == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The size of String object is zero in string_to_capitalize.\n");
  }
  else {
    iVar1 = _toupper((int)**param_1);
    **param_1 = (char)iVar1;
  }
  return;
}



void _string_to_casefold(long *param_1)

{
  int iVar1;
  ulong local_18;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid string input in string_to_casefold.\n");
  }
  else {
    for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
      iVar1 = _tolower((int)*(char *)(*param_1 + local_18));
      *(char *)(*param_1 + local_18) = (char)iVar1;
    }
  }
  return;
}



bool _string_starts_with(char **param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  bool local_9;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The substring is NULL in string_starts_with.\n");
    local_9 = false;
  }
  else {
    pcVar2 = (char *)_strlen(param_2);
    if (param_1[1] < pcVar2) {
      local_9 = false;
    }
    else {
      iVar1 = _strncmp(*param_1,param_2,(size_t)pcVar2);
      local_9 = iVar1 == 0;
    }
  }
  return local_9;
}



bool _string_ends_with(long *param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  bool local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The substring is NULL in string_ends_with.\n");
    local_9 = false;
  }
  else {
    sVar2 = _strlen(param_2);
    if ((ulong)param_1[1] < sVar2) {
      local_9 = false;
    }
    else {
      iVar1 = _strncmp((char *)((*param_1 + param_1[1]) - sVar2),param_2,sVar2);
      local_9 = iVar1 == 0;
    }
  }
  return local_9;
}



void _string_swap_case(long *param_1)

{
  int iVar1;
  ulong local_18;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is NULL in string_swap_case\n");
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str->dataStr is NULL in string_swap_case\n")
    ;
  }
  else {
    for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
      iVar1 = _islower((int)*(char *)(*param_1 + local_18));
      if (iVar1 == 0) {
        iVar1 = _isupper((int)*(char *)(*param_1 + local_18));
        if (iVar1 != 0) {
          iVar1 = _tolower((int)*(char *)(*param_1 + local_18));
          *(char *)(*param_1 + local_18) = (char)iVar1;
        }
      }
      else {
        iVar1 = _toupper((int)*(char *)(*param_1 + local_18));
        *(char *)(*param_1 + local_18) = (char)iVar1;
      }
    }
  }
  return;
}



wchar_t * _string_to_unicode(char *param_1)

{
  size_t sVar1;
  wchar_t *local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input string is NULL in string_to_unicode.\n");
    local_10 = (wchar_t *)0x0;
  }
  else {
    sVar1 = _mbstowcs((wchar_t *)0x0,param_1,0);
    sVar1 = sVar1 + 1;
    if (sVar1 == 0xffffffffffffffff) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Conversion failed in string_to_unicode.\n"
              );
      local_10 = (wchar_t *)0x0;
    }
    else {
      local_10 = (wchar_t *)_malloc(sVar1 * 4);
      if (local_10 == (wchar_t *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_to_unicode.\n");
        local_10 = (wchar_t *)0x0;
      }
      else {
        _mbstowcs(local_10,param_1,sVar1);
      }
    }
  }
  return local_10;
}



undefined8 _string_from_unicode(wchar_t *param_1)

{
  size_t sVar1;
  char *pcVar2;
  undefined8 local_10;
  
  if (param_1 == (wchar_t *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input wide string is NULL in string_from_unicode.\n");
    local_10 = 0;
  }
  else {
    sVar1 = _wcstombs((char *)0x0,param_1,0);
    if (sVar1 == 0xffffffffffffffff) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Conversion failed in string_from_unicode.\n");
      local_10 = 0;
    }
    else {
      pcVar2 = (char *)_malloc(sVar1 + 1);
      if (pcVar2 == (char *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_from_unicode.\n");
        local_10 = 0;
      }
      else {
        _wcstombs(pcVar2,param_1,sVar1 + 1);
        local_10 = _string_create(pcVar2);
        _free(pcVar2);
      }
    }
  }
  return local_10;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void * _string_create_from_initializer
                 (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 ulong param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined8 uVar1;
  undefined8 *local_120;
  undefined local_108 [8];
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_68;
  ulong local_58;
  undefined8 local_50;
  ulong local_48;
  void *local_40;
  ulong local_38;
  void *local_30;
  uint local_28;
  undefined4 local_24;
  undefined8 *local_20;
  undefined *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_d8 = param_1;
    local_c8 = param_2;
    local_b8 = param_3;
    local_a8 = param_4;
    local_98 = param_5;
    local_88 = param_6;
    local_78 = param_7;
    local_68 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_100 = param_10;
  local_f8 = param_11;
  local_f0 = param_12;
  local_e8 = param_13;
  local_e0 = param_14;
  local_38 = param_9;
  if (param_9 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: count is zero in string_create_from_initializer.\n");
    local_30 = (void *)0x0;
  }
  else {
    local_18 = local_108;
    local_20 = (undefined8 *)&stack0x00000008;
    local_24 = 0x30;
    local_28 = 8;
    local_40 = _malloc((param_9 + 1) * 8);
    if (local_40 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed for strings array in string_create_from_initializer.\n"
              );
      local_30 = (void *)0x0;
    }
    else {
      for (local_48 = 0; local_48 < local_38; local_48 = local_48 + 1) {
        if (local_28 < 0x29) {
          local_120 = (undefined8 *)(local_18 + (int)local_28);
          local_28 = local_28 + 8;
        }
        else {
          local_120 = local_20;
          local_20 = local_20 + 1;
        }
        local_50 = *local_120;
        uVar1 = _string_create(local_50);
        *(undefined8 *)((long)local_40 + local_48 * 8) = uVar1;
        if (*(long *)((long)local_40 + local_48 * 8) == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: string_create failed for string: %s in string_create_from_initializer.\n"
                   ,local_50);
          for (local_58 = 0; local_58 < local_48; local_58 = local_58 + 1) {
            _string_deallocate(*(undefined8 *)((long)local_40 + local_58 * 8));
          }
          _free(local_40);
          local_30 = (void *)0x0;
          goto LAB_1000071d2;
        }
      }
      *(undefined8 *)((long)local_40 + local_38 * 8) = 0;
      local_30 = local_40;
    }
  }
LAB_1000071d2:
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return local_30;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



size_t _string_length_cstr(char *param_1)

{
  size_t local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is null in string_length_cstr.\n");
    local_10 = 0;
  }
  else {
    local_10 = _strlen(param_1);
  }
  return local_10;
}



long _string_length_utf8(char *param_1)

{
  long local_20;
  char *local_18;
  long local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is null in string_length_cstr.\n");
    local_10 = 0;
  }
  else {
    local_20 = 0;
    for (local_18 = param_1; *local_18 != '\0'; local_18 = local_18 + 1) {
      if (((int)*local_18 & 0xc0U) != 0x80) {
        local_20 = local_20 + 1;
      }
    }
    local_10 = local_20;
  }
  return local_10;
}



undefined _string_to_bool_from_cstr(char *param_1)

{
  int iVar1;
  undefined local_9;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: bool str is NULL and invalid in string_to_bool_cstr.\n");
    local_9 = 0;
  }
  else {
    iVar1 = _strcmp(param_1,"true");
    if (iVar1 == 0) {
      local_9 = 1;
    }
    else {
      iVar1 = _strcmp(param_1,"false");
      if (iVar1 == 0) {
        local_9 = 0;
      }
      else {
        local_9 = 0;
      }
    }
  }
  return local_9;
}



undefined8 _string_utf8_char_len(char param_1)

{
  undefined8 local_10;
  
  if (((int)param_1 & 0x80U) == 0) {
    local_10 = 1;
  }
  else if (((int)param_1 & 0xe0U) == 0xc0) {
    local_10 = 2;
  }
  else if (((int)param_1 & 0xf0U) == 0xe0) {
    local_10 = 3;
  }
  else if (((int)param_1 & 0xf8U) == 0xf0) {
    local_10 = 4;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



undefined8 entry(void)

{
  if (*(long *)PTR____stack_chk_guard_10000a030 == *(long *)PTR____stack_chk_guard_10000a030) {
    return 0;
  }
                    // WARNING: Subroutine does not return
  ___stack_chk_fail();
}



void _destroy_global_memory_pool(void)

{
  if ((_global_pool != 0) && ((_memoryPoolCreated & 1) != 0)) {
    _memory_pool_destroy(_global_pool);
    _global_pool = 0;
  }
  return;
}



void ___memcpy_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074d8. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____memcpy_chk_10000a000)();
  return;
}



void ___memmove_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074de. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____memmove_chk_10000a008)();
  return;
}



void ___memset_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074e4. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____memset_chk_10000a010)();
  return;
}



void ___snprintf_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074ea. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____snprintf_chk_10000a018)();
  return;
}



void ___sprintf_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074f0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____sprintf_chk_10000a020)();
  return;
}



void ___stack_chk_fail(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074f6. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____stack_chk_fail_10000a028)();
  return;
}



void ___strcpy_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x0001000074fc. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____strcpy_chk_10000a040)();
  return;
}



void ___strncpy_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x000100007502. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____strncpy_chk_10000a048)();
  return;
}



void ___vsnprintf_chk(void)

{
                    // WARNING: Could not recover jumptable at 0x000100007508. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR____vsnprintf_chk_10000a050)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

double _atof(char *param_1)

{
  double dVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000750e. Too many branches
                    // WARNING: Treating indirect jump as call
  dVar1 = (double)(*(code *)PTR__atof_10000a058)();
  return dVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _atoi(char *param_1)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007514. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__atoi_10000a060)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void _exit(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00010000751a. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR__exit_10000a068)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007520. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__fprintf_10000a070)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void _free(void *param_1)

{
                    // WARNING: Could not recover jumptable at 0x000100007526. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR__free_10000a078)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _isalpha(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000752c. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__isalpha_10000a080)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _islower(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007532. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__islower_10000a088)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _isspace(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007538. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__isspace_10000a090)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _isupper(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000753e. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__isupper_10000a098)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * _malloc(size_t param_1)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007544. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = (void *)(*(code *)PTR__malloc_10000a0a0)();
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t _mbstowcs(wchar_t *param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000754a. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = (*(code *)PTR__mbstowcs_10000a0a8)();
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void _perror(char *param_1)

{
                    // WARNING: Could not recover jumptable at 0x000100007550. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR__perror_10000a0b0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _rand(void)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007556. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__rand_10000a0b8)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * _realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000755c. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = (void *)(*(code *)PTR__realloc_10000a0c0)();
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void _srand(uint param_1)

{
                    // WARNING: Could not recover jumptable at 0x000100007562. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR__srand_10000a0c8)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _strcasecmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007568. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__strcasecmp_10000a0d0)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * _strchr(char *param_1,int param_2)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000756e. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = (char *)(*(code *)PTR__strchr_10000a0d8)();
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _strcmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007574. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__strcmp_10000a0e0)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000757a. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = (*(code *)PTR__strlen_10000a0e8)();
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _strncmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007580. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__strncmp_10000a0f0)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007586. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = (char *)(*(code *)PTR__strstr_10000a0f8)();
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

double _strtod(char *param_1,char **param_2)

{
  double dVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000758c. Too many branches
                    // WARNING: Treating indirect jump as call
  dVar1 = (double)(*(code *)PTR__strtod_10000a100)();
  return dVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * _strtok(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007592. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = (char *)(*(code *)PTR__strtok_10000a108)();
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

long _strtol(char *param_1,char **param_2,int param_3)

{
  long lVar1;
  
                    // WARNING: Could not recover jumptable at 0x000100007598. Too many branches
                    // WARNING: Treating indirect jump as call
  lVar1 = (*(code *)PTR__strtol_10000a110)();
  return lVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    // WARNING: Could not recover jumptable at 0x00010000759e. Too many branches
                    // WARNING: Treating indirect jump as call
  tVar1 = (*(code *)PTR__time_10000a118)();
  return tVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _tolower(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001000075a4. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__tolower_10000a120)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int _toupper(int _c)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001000075aa. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = (*(code *)PTR__toupper_10000a128)();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t _wcstombs(char *param_1,wchar_t *param_2,size_t param_3)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001000075b0. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = (*(code *)PTR__wcstombs_10000a130)();
  return sVar1;
}


