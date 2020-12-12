/*****************************************************************//**
 * \file   Decompression.h
 * \brief  Header of the library allowing the management of Decompression
 * 
 * \author Sabrina MOHAMMEDI sabrina.mohammedi@efrei.net
 * \date   December 2020
 *********************************************************************/

#ifndef DECOMPRESSION_H_INCLUDED
#define DECOMPRESSION_H_INCLUDED

#include "Compression.h"

void decompress_file(char *file_decomp,char* file_comp,code_car* dico);

#endif // DECOMPRESSION_H_INCLUDED
