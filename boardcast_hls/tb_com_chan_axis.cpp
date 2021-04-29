#include "com_chan_axis.h"

int main (){

	INT_STREAM input, output1 , output2;
	application(&input,&output1,&output2);
	print_chan(&output1);
	print_chan(&output2);
	return EXIT_SUCCESS;
}
