#ifndef _INT_STREAM_EXAMPLE_H
#define _INT_STREAM_EXAMPLE_H

#include <stdlib.h>
#include "ap_axi_sdata.h"
#include "hls_stream.h"

typedef ap_axis<32,2,1,1> AXI_INT;
typedef hls::stream <AXI_INT> INT_STREAM;

#define NUM 10

void print_chan(INT_STREAM* channel);
void initStream(INT_STREAM* input);
void traitementA(INT_STREAM* input, INT_STREAM* output1,INT_STREAM* output2);
void traitementB(INT_STREAM* input, INT_STREAM* output);
void traitementC(INT_STREAM* input, INT_STREAM* output);
void traitementD(INT_STREAM* inputB, INT_STREAM*inputC, INT_STREAM* output);
void application(INT_STREAM* input, INT_STREAM* output);

#endif
