#include "analog_encoder_instruction_memory.h"

extern L2_DATA Instruction_memory_object_analog instruction_memory_compiled_analog[2];

// Warning: we already assume here that A and B have the same shape!
void analog_encoder_instruction_memory(
    uint32_t pointer_input,
    uint32_t pointer_weights,
    uint32_t pointer_output,
    Layer_parameters *layer
    ) {
    instruction_memory_compiled_analog[0].skips                 = 0x3F;
    //instruction_memory_compiled_analog[0].reg1                  = 0x0;
    instruction_memory_compiled_analog[0].input_memory_pointer  = pointer_input;
    instruction_memory_compiled_analog[0].output_memory_pointer = pointer_output;
    //instruction_memory_compiled_analog[0].partial_sum_pointer   = 0x0;
    //instruction_memory_compiled_analog[0].residual_sum_pointer  = 0x0;
    //instruction_memory_compiled_analog[0].bn_pointer            = 0x0;
    instruction_memory_compiled_analog[0].c                     = layer->c;
    instruction_memory_compiled_analog[0].k                     = layer->k;
    instruction_memory_compiled_analog[0].cx                    = layer->cx;
    instruction_memory_compiled_analog[0].cy                    = layer->cy;
    instruction_memory_compiled_analog[0].precision             = 0x7;
    instruction_memory_compiled_analog[0].pool_fy_fx            = layer->fx + (layer->fy<<4);
    instruction_memory_compiled_analog[0].ox                    = layer->ox;
    instruction_memory_compiled_analog[0].oy                    = layer->oy;
    instruction_memory_compiled_analog[0].ox_unroll             = layer->ox_unroll;
    instruction_memory_compiled_analog[0].stride                = layer->stride;
    instruction_memory_compiled_analog[0].padding               = layer->padding;
    instruction_memory_compiled_analog[0].processing_blocks     = (int)((layer->c+63)/64);
    instruction_memory_compiled_analog[0].complicated_register  = 0x2005;
    instruction_memory_compiled_analog[0].use_blk_col           = 0xFFFF;
    instruction_memory_compiled_analog[0].reg21                 = 0x0100;
    instruction_memory_compiled_analog[0].stop                  = 0xF000;
    //instruction_memory_compiled_analog[0].reg23                 = 0x0000;
    instruction_memory_compiled_analog[0].reg24                 = 0x0084;
    instruction_memory_compiled_analog[0].reg25                 = 0x0900;
    //instruction_memory_compiled_analog[0].reg26                 = 0x0000;
    //instruction_memory_compiled_analog[0].reg27                 = 0x0000;
    //instruction_memory_compiled_analog[0].reg28                 = 0x0000;
    //instruction_memory_compiled_analog[0].reg29                 = 0x0000;
    //instruction_memory_compiled_analog[0].reg30                 = 0x0000;
    //instruction_memory_compiled_analog[0].reg31                 = 0x0000;
    instruction_memory_compiled_analog[1].skips                 = 0x3F;
    instruction_memory_compiled_analog[1].precision             = 0x7;
    instruction_memory_compiled_analog[1].ox_unroll             = 0x1;
    instruction_memory_compiled_analog[1].processing_blocks     = 0x1;
    instruction_memory_compiled_analog[1].complicated_register  = 0x0005;
    instruction_memory_compiled_analog[1].use_blk_col           = 0x0001;
    instruction_memory_compiled_analog[1].reg21                 = 0x010a;
    instruction_memory_compiled_analog[1].stop                  = 0xF001;
    instruction_memory_compiled_analog[1].reg24                 = 0x0084;
    return;
}
