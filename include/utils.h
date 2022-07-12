#include <archi/hwme/hwme_v1.h>
#include <hal/hwme/hwme_v1.h>
#include <hal/pulp.h>
#include <pulp.h>

#define DIG_HWPE_PARALLELISM 16
#define padding( value, base ) ((value + base - 1) / base * base)

#ifndef INSTR_DIG_H
#define INSTR_DIG_H
typedef struct Instruction_memory_object {
    // Mode: 0 --> Stop Instruction
    //       1 --> Convolution
    //       2 --> TO DO
    //       3 --> Element Wise Sum 
    uint32_t mode;
    // from 0x0
    // for ews the weights are the first input activation
    uint32_t weight_memory_pointer; 
    // from 0x0: adress in L1 of max dimension 0x10000 
    uint32_t input_memory_pointer;  
    // from 0x0: adress in L1 of max dimension 0x10000 
    uint32_t output_memory_pointer;
    // input channels. Addition is mapped as a 0x0xc. All the other fields should be 0
    //This field therefore correspond to the total dimension of the tensors
    uint32_t c;
    // output channels: this values is / 16 for unrolling on accelerator;
    // E.g. Map k=16 as 0x1.
    uint32_t k;
    // input activation dimension x
    uint32_t cx;
    // input activation dimension y
    uint32_t cy;
    // TO DO
    uint32_t padded_cx;
    // TO DO
    uint32_t size_channel;
    // Filter dimension x
    uint32_t fx;
    // Filter dimension y
    uint32_t fy;
    // Output dimension x: this values is / 16 for unrolling on accelerator;
    // E.g. Map ox=32 as 0x2.
    uint32_t ox;
    // Output dimension y
    uint32_t oy;
    // Activation function: 1 --> Relu
    //                      0 --> Nothing
    uint32_t activation_function;
    // Data Layout: 2 --> Ox for using in digital accelerator
    //              1 --> K for using in analog accelerator
    uint32_t write_l2_l1;
    // TO DO
    uint32_t output_channel_size;
    // dilation
    uint32_t dilation;
    // There is also the need of a stop instruction as last one. 
    // 0 --> nothing
    // 1 --> STOP
    uint32_t stop;
    // shift the output result for requantization
    uint32_t shift_fixed_point;
    // TO DO
    uint32_t zero_padding;
    // TO DO
    uint32_t type_nonlinear_function;
    // set to 0 from this parameter
    uint32_t weight_tile_size;
    uint32_t nb_weight_tile;
    uint32_t conv_strided;
    uint32_t norm;
    uint32_t output_precision;
    uint32_t input_precision;
    uint32_t empty_filed_0;
    uint32_t empty_filed_1;
    uint32_t empty_filed_2;
    uint32_t empty_filed_3;
// Because we are going to serialize this struct at some point, we have to make
// sure that it is packed. That should be the default on the 32bits pulpissimo,
// but since GCC enables it, lets'be explicit.
} __attribute__((packed)) Instruction_memory_object;
#endif

#ifndef LAYERPARAM_H
#define LAYERPARAM_H
typedef struct Layer_parameters {
  uint32_t c;
  uint32_t k;
  uint32_t cx;
  uint32_t cy;
  uint32_t fx;
  uint32_t fy;
  uint32_t ox;
  uint32_t oy;
  uint32_t activation_function;
  uint32_t output_shift;
  uint32_t padding;
  uint32_t dilation;
  uint32_t stride;
} Layer_parameters;
#endif

void global_sync();

