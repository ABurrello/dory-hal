#include "encoder_instruction_memory.h"

extern L2_DATA Instruction_memory_object instruction_memory_compiled[2];

// Warning: we already assume here that A and B have the same shape!
void encoder_instruction_memory(
    Instruction_type mode,
    uint32_t pointer_input,
    uint32_t pointer_weights,
    uint32_t pointer_output,
    Layer_parameters *layer
    ) {
    Instruction_memory_object layer_instruction = {0};
    
    switch(mode)
    {
        case CONV:
            layer_instruction.mode                  = 1;
            layer_instruction.c                     = layer->c;
            layer_instruction.k                     = layer->k / DIG_HWPE_PARALLELISM;
            layer_instruction.cx                    = layer->cx;
            layer_instruction.cy                    = layer->cy;
            layer_instruction.padded_cx             = layer->cx;
            layer_instruction.size_channel          = layer->cx * layer->cy;
            layer_instruction.output_channel_size   = layer->ox *  layer->oy;
            layer_instruction.fx                    = layer->fx;
            layer_instruction.fy                    = layer->fy;
            layer_instruction.ox                    = layer->ox / DIG_HWPE_PARALLELISM;
            layer_instruction.oy                    = layer->oy;
            layer_instruction.activation_function   = layer->activation_function;
            layer_instruction.dilation              = layer->dilation;
            layer_instruction.shift_fixed_point     = layer->output_shift;
            layer_instruction.zero_padding          = layer->padding;
            layer_instruction.write_l2_l1           = 2;
            layer_instruction.conv_strided         = layer->stride;
            break;
        case EWS:
            layer_instruction.mode                  = 3;
            layer_instruction.c                     = layer->c;
            break;
    }
    layer_instruction.weight_memory_pointer = pointer_weights;
    layer_instruction.input_memory_pointer  = pointer_input;
    layer_instruction.output_memory_pointer = pointer_output;
    instruction_memory_compiled[0] = layer_instruction;

    Instruction_memory_object stop_instruction = {0};
    stop_instruction.stop = 1;
    instruction_memory_compiled[1] = stop_instruction;

    return;
}