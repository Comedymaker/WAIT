#include "stdio.h"
#include "include/parse.h"
#include "include/types.h"
#include "include/utils.h"

wasm_module_ptr load_module(wasm_code_ptr code){
    wasm_module_ptr module;

    module = (wasm_module_ptr)malloc(sizeof(wasm_module));

    bytes pos = code->ptr;
    bytes end = code->ptr + code->length;

    u32 magic, version;

    Read_u32(&magic, &pos, end);
    Read_u32(&version, &pos, end);

    if (magic != 0x6d736100 || version != 0x1)
    {
        panicf("magic or version not match");
    }

    u8 previousSection = 0;

    while (pos < end)
    {
        u8 section;
        ReadLEB_u7(&section, &pos, end);

        u32 sectionSize;
        ReadLEB_u32(&sectionSize, &pos, end);


    }
    
    return 0;
}

void ParseModuleSection(wasm_module_ptr module, u8 i_sectionType, bytes start, u32 i_numBytes)
{
    typedef void (*Parser)(wasm_code_ptr, bytes, bytes);
    // 仅解析目前支持的seciton，其余section跳过处理
    static Parser s_parsers[] =
        {
            NULL,                  // 0 ParseSection_Custom
            ParseSection_Type,     // 1
            ParseSection_Import,   // 2
            ParseSection_Function, // 3
            NULL,                  // 4: TODO Table
            ParseSection_Memory,   // 5
            ParseSection_Global,   // 6
            NULL,                  //ParseSection_Export,   // 7
            // ParseSection_Start,    // 8
            NULL,    // 8
            NULL,                  //ParseSection_Element,  // 9
            ParseSection_Code,     // 10
            ParseSection_Data,     // 11
        };

    Parser parser = NULL;

    if (i_sectionType <= 12)
    {
        parser = s_parsers[i_sectionType];
        log(parse, " sectionType = %d", (u32)i_sectionType);
    }

    if (parser)
    {
        bytes end = start + i_numBytes;
        parser(module, start, end);
    }
    else
    {
        log(parse, " skipped section type: %d", (u32)i_sectionType);
    }
}