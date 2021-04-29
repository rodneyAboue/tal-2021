#include "com_chan_axis.h"

int main (){

	INT_STREAM input, output;
	application(&input,&output);
	print_chan(&output);
	return EXIT_SUCCESS;
}
