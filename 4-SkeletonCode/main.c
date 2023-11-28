/*
Name:Prasan Galagali
Date:28/11/2023
Description:Steganography
Input:./a.out -e beautiful.bmp secret.txt stego.bmp
Output:
*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char **argv)
{
    int status;
    status = check_operation_type(argv);

     // Function call for check operation type
    if(status == e_encode)
    {
	printf("Selected encodeing\n");
	EncodeInfo encInfo;   // Declare structure variable
	status = read_and_validate_encode_args(argv, &encInfo);
	// Read and validate encode arguments
	if(status == e_success)
	{
	    printf("Read val is success\n");
	    do_encoding(&encInfo);
	}
	else
	{
	    printf("Failure\n");
	    printf("./a.out -e <.bmp> <.txt> [optional stage.bmp]\n");
	}
    }

        // Function call for check operation type
    else if(status == e_decode)
    {
	printf("Selected decodeing\n");
	// Declare structure variables
	DecodeInfo decInfo;
	status = read_and_validate_decode_args(argv, &decInfo);
	if(status == d_success)
	{
	    printf("Read and Validate decode arguments is a success\n");
	     if(do_decoding(&decInfo) == d_success)
	     {
		 printf("<-----Completed decodeing--------->\n");
	     }
	    
	  }
	else
	{
	    printf("Read and validate decode arguments is a failure\n");
	    return e_failure;
    }
    }
    else
    {
	printf("./a.out -e <.bmp> <.txt> [optional stego.bmp]\n./a.out <.bmp> [optional decode.txt]\n");
    }


    return 0;
}


