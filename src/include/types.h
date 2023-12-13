//data types
typedef char bool;
typedef unsigned char u8;
typedef char i8;
typedef unsigned short u16;
typedef short i16;
typedef unsigned int u32;
typedef int i32;
typedef float f32;
typedef double f64;
typedef unsigned long long u64;
typedef long long i64;
typedef u32 bytes;

//wasm字节码
typedef struct WASM_CODE
{
  u32 ptr;
  u16 length;
}wasm_code;

typedef wasm_code* wasm_code_ptr;

typedef struct IMPORT_INFO
{
    char *    moduleUtf8;
    char *    fieldUtf8;
//  unsigned char   type;
}import_info;
typedef import_info* import_info_ptr;

typedef struct FUNC_TYPE
{
    struct FUNC_TYPE *     next;

    u32                     args_num;
    u8                      returnType;
    // u8                      need_memory_pass;
    u8                      args_type_list        [2];    // 用于32位对齐
}func_type;
typedef func_type* func_type_ptr;

typedef struct MEMORY_INFO
{
  u32 init_page_num;
  u32 max_page_num;
}memory_info;
typedef memory_info* memory_info_ptr;

typedef struct WASM_GLOBAL
{
    u32                 initExpr;       // wasm code
    u32                     initExprSize;
    u8                      type;
    bool                    imported;
    struct IMPORT_INFO     import;
    bool                    isMutable;
    u16                   offset;
}wasm_global;
typedef wasm_global* wasm_global_ptr;

typedef void (*normal_function)();
typedef struct WASM_FUNCTION
{
    struct WASM_MODULE*      module;

    u32                 wasm;
    u32                 wasmEnd;

    char*                  name;

    struct FUNC_TYPE*      funcType;

    u16                    compiled;

    u16                     numArgSlots;

    u16                     numLocals;          // not including args
    u16                     numLocalu32;

    struct IMPORT_INFO     import;

}wasm_function;
typedef wasm_function* wasm_function_ptr;

typedef struct DATA_SEGMENT
{
    u32              initExpr;       // wasm code
    u32              data;

    u16                     initExprSize;
    u16                     memoryRegion;
    u16                     size;
}data_segment;
typedef data_segment* data_segment_ptr;

//wasm模块
typedef struct WASM_MODULE
{
  char* name;

  struct MEMORY_INFO memory;
  bool memory_imported;

  u16 global_num;
  struct WASM_GLOBAL*  global_list;

  u16 function_num;
  u16 import_num;

  struct WASM_FUNCTION** function_list;

  // u32 startFunction;
  // u16 entry_method;

  struct FUNC_TYPE** func_type_list;
  u16 func_type_num;

  struct DATA_SEGMENT* data_segment_list;
  u16 data_segment_num;
}wasm_module;
typedef wasm_module* wasm_module_ptr;