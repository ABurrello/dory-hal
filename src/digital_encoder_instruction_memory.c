#include "digital_encoder_instruction_memory.h"

extern L2_DATA Instruction_memory_object_digital instruction_memory_compiled_digital[2];

// Warning: we already assume here that A and B have the same shape!
void digital_encoder_instruction_memory(
    Instruction_type mode,
    uint32_t pointer_input,
    uint32_t pointer_weights,
    uint32_t pointer_output,
    Layer_parameters *layer
    ) {
    
    switch(mode)
    {
        case CONV:
            instruction_memory_compiled_digital[0].mode                  = 1;
            instruction_memory_compiled_digital[0].c                     = layer->c;
            instruction_memory_compiled_digital[0].k                     = layer->k / DIG_HWPE_PARALLELISM;
            instruction_memory_compiled_digital[0].cx                    = layer->cx;
            instruction_memory_compiled_digital[0].cy                    = layer->cy;
            instruction_memory_compiled_digital[0].padded_cx             = layer->cx;
            instruction_memory_compiled_digital[0].size_channel          = layer->cx * layer->cy;
            instruction_memory_compiled_digital[0].output_channel_size   = layer->ox *  layer->oy;
            instruction_memory_compiled_digital[0].fx                    = layer->fx;
            instruction_memory_compiled_digital[0].fy                    = layer->fy;
            instruction_memory_compiled_digital[0].ox                    = layer->ox / DIG_HWPE_PARALLELISM;
            instruction_memory_compiled_digital[0].oy                    = layer->oy;
            instruction_memory_compiled_digital[0].activation_function   = layer->activation_function;
            instruction_memory_compiled_digital[0].dilation              = layer->dilation;
            instruction_memory_compiled_digital[0].shift_fixed_point     = layer->output_shift;
            instruction_memory_compiled_digital[0].zero_padding          = layer->padding;
            instruction_memory_compiled_digital[0].write_l2_l1           = 2;
            instruction_memory_compiled_digital[0].conv_strided         = layer->stride;
            break;
        case EWS:
            instruction_memory_compiled_digital[0].mode                  = 3;
            instruction_memory_compiled_digital[0].c                     = layer->c / DIG_HWPE_PARALLELISM;
            instruction_memory_compiled_digital[0].k                     = 0;
            instruction_memory_compiled_digital[0].cx                    = 0;
            instruction_memory_compiled_digital[0].cy                    = 0;
            instruction_memory_compiled_digital[0].padded_cx             = 0;
            instruction_memory_compiled_digital[0].size_channel          = 0;
            instruction_memory_compiled_digital[0].output_channel_size   = 0;
            instruction_memory_compiled_digital[0].fx                    = 0;
            instruction_memory_compiled_digital[0].fy                    = 0;
            instruction_memory_compiled_digital[0].ox                    = 0;
            instruction_memory_compiled_digital[0].oy                    = 0;
            instruction_memory_compiled_digital[0].activation_function   = 0;
            instruction_memory_compiled_digital[0].dilation              = 0;
            instruction_memory_compiled_digital[0].shift_fixed_point     = 0;
            instruction_memory_compiled_digital[0].zero_padding          = 0;
            instruction_memory_compiled_digital[0].write_l2_l1           = 0;
            instruction_memory_compiled_digital[0].conv_strided          = 0;
            break;
    }
    instruction_memory_compiled_digital[0].weight_memory_pointer = pointer_weights;
    instruction_memory_compiled_digital[0].input_memory_pointer  = pointer_input;
    instruction_memory_compiled_digital[0].output_memory_pointer = pointer_output;
    instruction_memory_compiled_digital[1].stop = 1;

    return;
}