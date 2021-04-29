#include "com_chan_axis.h"


// Note
// template<int D, int U, int TI, int TD>
// Note : La fonction "application" doit �tre en top function
// Struct ap_axis{
/*
	ap_int<D> data;
	ap_unit<D/8> keep;
	ap_uint<D/8> strb;
	ap_uint<U> user;
	ap_unit<1> last;
	ap_unit<TI> id;
	ap_unit<TD> dest;

*/

void traitementA(INT_STREAM* input, INT_STREAM * outputB , INT_STREAM* outputC){
	#pragma HLS INTERFACE axis port=input
	#pragma HLS INTERFACE axis port=output
	AXI_INT data;
	while (!input->empty()){
		input->read(data);
		data.id = 0;
		outputB->write(data);
		data.id = 1;
		outputC->write(data);
	}
}

void traitementB(INT_STREAM* input, INT_STREAM* output){
	#pragma HLS INTERFACE axis port=input
	#pragma HLS INTERFACE axis port=output
	AXI_INT data;
	while (!input->empty()){
		input->read(data);
		data.data = data.data+2;
		output->write(data);
	}
}

void traitementC(INT_STREAM* input, INT_STREAM* output){
	#pragma HLS INTERFACE axis port=input
	#pragma HLS INTERFACE axis port=output
	AXI_INT data;
	while (!input->empty()){
		input->read(data);
		data.data = data.data*3;
		output->write(data);
	}
}


void print_chan(INT_STREAM* channel){
	#pragma HLS INTERFACE axis port=channel
	printf("Results: \n");
	AXI_INT data;
	while (!channel->empty()){
		channel->read(data);
		printf("Noeud %d, data: %d\n",data.id.to_int(),data.data.to_int());
	}
}

void initStream(INT_STREAM * streamData){
	size_t i ;
	AXI_INT data;
	printf("Initialization : \n");
	for(i=0 ; i<NUM; i++ ){
		data.data = i;
		data.user = 1;
		data.last = (i == NUM-1);
		data.dest = 2;
		streamData->write(data);
		printf("data: %d\n",data.data.to_int());
	}
}


// Impl�mentation d'une archit�cture piplin�

void application(INT_STREAM* input, INT_STREAM* outputB, INT_STREAM* outputC){
	#pragma HLS DATAFLOW
	#pragma HLS INTERFACE axis port=input
	#pragma HLS INTERFACE axis port=output

	int i , ret;
	INT_STREAM chaB, chaC;
	// Initialisation des donn�es
	initStream(input);
	printf("----------------------------Noeud A ----------------------------\n");
	traitementA(input, &chaB ,&chaC);
	printf("----------------------------Noeud B----------------------------\n");
	traitementB(&chaB,outputB);
	printf("----------------------------Noeud C----------------------------\n");
	traitementC(&chaC, outputC);
}
