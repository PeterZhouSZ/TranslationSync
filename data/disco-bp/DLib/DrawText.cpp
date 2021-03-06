//
//  DLib: A simple image processing library.
//
//  David Crandall, 2003-2005
//  crandall@cs.cornell.edu
//
//  Please do not redistribute this code.
//
//
//
//
#include <math.h>
#include "DrawText.h"


/*  GIMP header image file format (RGB): /Users/dave/maya/test_imgs/letters2.h  */

static int width = 564;
static int height = 13;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
  pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
  pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
  pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
  data += 4; \
}
static char *header_data =
	"````````````````````````````````````````````````````````````````"
	"````````````````!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````````````````!!!!````"
	"````!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````!!!!````````````````````````````````````````````"
	"````````````````````````!!!!````````````````!!!!````!!!!````````"
	"````````!!!!````!!!!````````!!!!!!!!!!!!````````````!!!!````````"
	"````!!!!````!!!!!!!!````````````````````````!!!!````````````````"
	"````!!!!````````````````!!!!````````````````````!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!````````!!!!"
	"!!!!!!!!````````````````!!!!````````````````!!!!!!!!!!!!````````"
	"````!!!!!!!!!!!!````````````````````!!!!````````!!!!!!!!!!!!!!!!"
	"!!!!````````````!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!````````!!!!"
	"!!!!!!!!````````````!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````!!!!!!!!!!!!````````````````"
	"!!!!!!!!````````````````!!!!````````````!!!!!!!!!!!!!!!!````````"
	"````!!!!!!!!!!!!````````!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!````!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!````````!!!!````"
	"````````!!!!````````!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!````"
	"!!!!````````````!!!!````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````````!!!!!!!!!!!!````````!!!!!!!!"
	"!!!!!!!!````````````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!````````"
	"````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````````````!!!!````!!!!!!!!!!!!!!!!!!!!````"
	"````````!!!!!!!!!!!!````````!!!!````````````````````!!!!!!!!!!!!"
	"````````````````!!!!````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````````````````"
	"````````````````````````````````````````!!!!````````````````````"
	"````````````````!!!!!!!!````````````````````````````````!!!!````"
	"````````````````````````!!!!````````````````````````!!!!````````"
	"!!!!````````````````````````````!!!!````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````!!!!````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````!!!!!!!!````````````!!!!````````````!!!!!!!!````````"
	"````````````````````````````````````````!!!!````````````````!!!!"
	"````!!!!````````````````!!!!````!!!!````!!!!````!!!!````!!!!````"
	"!!!!````!!!!````````!!!!!!!!````````!!!!````````````````````!!!!"
	"````````````````!!!!````````````````````````!!!!````````!!!!````"
	"!!!!````!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"!!!!````!!!!````````````!!!!````````!!!!!!!!````````````!!!!````"
	"````````!!!!````!!!!````````````!!!!````````````!!!!!!!!````````"
	"!!!!````````````````````````!!!!````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!````````````"
	"!!!!````````!!!!````````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````!!!!````````````!!!!````!!!!````````!!!!````````"
	"!!!!````````````````````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````````````!!!!````````````````````"
	"````````!!!!````!!!!````````!!!!````````!!!!````````````````````"
	"!!!!!!!!````!!!!!!!!````!!!!!!!!````````!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````````````!!!!````````````!!!!````````````"
	"!!!!````````````!!!!````!!!!````````````!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````````````"
	"````````!!!!````````````!!!!````````````````!!!!````````````````"
	"````````````!!!!````````````````!!!!````````````````````````````"
	"````````````````!!!!````````````````````````````````````!!!!````"
	"````````````````````````````````````````````````````````!!!!````"
	"````````````````````````````!!!!````````````````````````````````"
	"````````!!!!````````````````````````````````````````````````````"
	"````````````````!!!!````````````````````````````!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````!!!!````````````````````!!!!````````````"
	"````````!!!!````````````````````````````````````````````!!!!````"
	"````````````!!!!````!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!````"
	"!!!!````````````!!!!````!!!!````!!!!````!!!!````````````````````"
	"````````````!!!!````````````````!!!!````````````````````````!!!!"
	"````````````!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````!!!!````````!!!!````````!!!!!!!!````!!!!````!!!!````"
	"````````````````````````!!!!````````````````````!!!!````````!!!!"
	"````!!!!````````!!!!````````````````````!!!!````````````````````"
	"````````````````!!!!````!!!!````````````!!!!````!!!!````````````"
	"!!!!````````````!!!!!!!!````````````````!!!!!!!!````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````!!!!````!!!!````````!!!!!!!!````````````!!!!````"
	"````````!!!!````````````!!!!````!!!!````````````````````!!!!````"
	"````````!!!!````!!!!````````````````````!!!!````````````````````"
	"!!!!````````````````````!!!!````````````!!!!````````````!!!!````"
	"````````````````````````!!!!````!!!!````!!!!````````````!!!!````"
	"````````````````!!!!!!!!````!!!!!!!!````!!!!!!!!````````!!!!````"
	"!!!!````````````!!!!````!!!!````````````!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````````````````````"
	"!!!!````````````!!!!````````````!!!!````!!!!````````````!!!!````"
	"!!!!````!!!!````!!!!````````!!!!````!!!!````````````!!!!````!!!!"
	"````````````````````!!!!````````````````!!!!````````````````````"
	"!!!!````````````````````````!!!!````````````!!!!````!!!!````````"
	"````````````````````````````````````!!!!````````````!!!!!!!!!!!!"
	"!!!!````!!!!````!!!!!!!!````````````!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!!!!!````````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!````````"
	"````!!!!!!!!!!!!!!!!````!!!!````!!!!!!!!````````````!!!!!!!!````"
	"````````````!!!!!!!!!!!!````````!!!!````````!!!!````````````````"
	"!!!!````````````!!!!!!!!````!!!!````````!!!!````!!!!!!!!````````"
	"````!!!!!!!!!!!!````````!!!!````!!!!!!!!````````````!!!!!!!!!!!!"
	"!!!!````!!!!!!!!````!!!!!!!!````````!!!!!!!!!!!!````````!!!!!!!!"
	"!!!!!!!!````````!!!!````````````!!!!````!!!!````````````!!!!````"
	"!!!!````````````!!!!````!!!!````````````!!!!````!!!!````````````"
	"!!!!````!!!!!!!!!!!!!!!!!!!!````````````!!!!````````````````````"
	"!!!!````````````````````!!!!````````````````````````````````````"
	"````````!!!!````````````````````````````````````````````!!!!````"
	"!!!!````````!!!!!!!!````````````````!!!!````!!!!````````````!!!!"
	"````````````````````````````````````````````!!!!````````````````"
	"````````````````!!!!````````!!!!!!!!!!!!````````````````!!!!````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````!!!!````````!!!!````!!!!````!!!!````"
	"````````!!!!````````````````````````!!!!````````````````!!!!!!!!"
	"````````!!!!````````!!!!````````!!!!!!!!!!!!!!!!````````!!!!!!!!"
	"!!!!!!!!````````````````````!!!!````````````!!!!!!!!!!!!````````"
	"!!!!````````````!!!!````````````!!!!!!!!````````````````!!!!!!!!"
	"````````````````````````!!!!!!!!````````````````````````!!!!!!!!"
	"````````````````````````````!!!!````````!!!!````!!!!````!!!!````"
	"````!!!!````!!!!````````!!!!!!!!!!!!!!!!````````!!!!````````````"
	"````````!!!!````````````!!!!````!!!!!!!!!!!!!!!!````````!!!!!!!!"
	"!!!!!!!!````````!!!!````````````````````!!!!!!!!!!!!!!!!!!!!````"
	"````````!!!!````````````````````````````!!!!````!!!!!!!!````````"
	"````````!!!!````````````````````!!!!````!!!!````!!!!````!!!!````"
	"!!!!````!!!!````!!!!````````````!!!!````!!!!````````````!!!!````"
	"!!!!````````````!!!!````!!!!````````````!!!!````````!!!!!!!!!!!!"
	"````````````````!!!!````````````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````!!!!````!!!!````````````!!!!````````````"
	"````!!!!````!!!!````````````````!!!!````````````````````!!!!````"
	"````````````````!!!!````````````````````````!!!!````````````!!!!"
	"````!!!!````````````````````````````````````````````````````````"
	"!!!!````````````!!!!````!!!!!!!!````````!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````````!!!!"
	"````````````````!!!!````````````!!!!````!!!!!!!!````````!!!!````"
	"````````!!!!````````````````````````!!!!````````!!!!````!!!!````"
	"````````````````!!!!````````````!!!!````!!!!````!!!!````!!!!!!!!"
	"````````!!!!````!!!!````````````!!!!````!!!!!!!!````````!!!!````"
	"!!!!````````````!!!!````````!!!!!!!!````````````!!!!````````````"
	"!!!!````````!!!!````````````````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````````````!!!!````````!!!!````!!!!````````"
	"!!!!````````````!!!!````````````````!!!!````````````````!!!!````"
	"````````````````!!!!````````````````````!!!!````````````````!!!!"
	"!!!!````````!!!!````````!!!!````````````````````````````````````"
	"````````!!!!````!!!!````````````!!!!!!!!````````````````!!!!````"
	"!!!!````!!!!````!!!!````````````````````````````````````````!!!!"
	"````````````````````````````````!!!!````!!!!````!!!!````!!!!````"
	"````````!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````````!!!!!!!!"
	"````````!!!!````````````!!!!````````````````````!!!!````````````"
	"````````````````!!!!````!!!!!!!!!!!!!!!!!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````````````````!!!!````````!!!!````"
	"````````!!!!````````!!!!!!!!!!!!!!!!````````````````````````````"
	"````````````````````````````````!!!!!!!!````````!!!!!!!!!!!!!!!!"
	"!!!!````````````!!!!!!!!````````````````!!!!````````````!!!!````"
	"!!!!````!!!!````````!!!!````!!!!````````!!!!````````````!!!!````"
	"!!!!````````````````````!!!!````````````!!!!````!!!!````````````"
	"````````!!!!````````````````````!!!!````````!!!!!!!!````!!!!````"
	"````````!!!!````````````!!!!````````````````````````````!!!!````"
	"!!!!!!!!````````````````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````!!!!````!!!!````!!!!````````````!!!!````!!!!!!!!"
	"!!!!!!!!````````!!!!````````````!!!!````!!!!!!!!!!!!!!!!````````"
	"````````````````!!!!````````````!!!!````````````!!!!````````````"
	"!!!!````````!!!!````!!!!````````!!!!````!!!!````!!!!````````````"
	"!!!!````````````````````!!!!````````````````````!!!!````````````"
	"````````!!!!````````````````````````!!!!````````````````````!!!!"
	"````````!!!!````````````!!!!````````````````````````````````````"
	"````````````````!!!!````````````!!!!````!!!!````````````!!!!````"
	"!!!!````````````````````!!!!````````````!!!!````!!!!!!!!!!!!!!!!"
	"!!!!````````!!!!````````````````!!!!````````````!!!!````!!!!````"
	"````````!!!!````````````!!!!````````````````````````!!!!````````"
	"!!!!!!!!````````````````````````!!!!````````````!!!!````!!!!````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````````````!!!!````````!!!!````````````````"
	"````!!!!!!!!````````````````!!!!````````````````!!!!````````````"
	"!!!!````````!!!!````!!!!````````!!!!````!!!!````!!!!````````````"
	"!!!!````````````````!!!!````!!!!````````````````!!!!````````````"
	"````````!!!!````````````````````!!!!````````````````````!!!!````"
	"````````!!!!````````!!!!!!!!````````````!!!!````````````````````"
	"````````````````!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!````!!!!````"
	"````!!!!````!!!!````!!!!!!!!````````!!!!````!!!!````````````````"
	"````````````!!!!````````````````````````````````!!!!````````````"
	"!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````````````````````"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````!!!!````````"
	"````````!!!!````````````!!!!````````````!!!!````````````````!!!!"
	"````````````````````````````````!!!!````````````````!!!!````````"
	"````````````````!!!!````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````````````!!!!````````````````````!!!!````````````"
	"````````````````````````````````````````!!!!!!!!````````````````"
	"````````````````````````````````````````!!!!!!!!````````!!!!````"
	"````````!!!!````````!!!!!!!!````!!!!!!!!!!!!!!!!!!!!````!!!!````"
	"````````!!!!````!!!!````````````````````!!!!````````````!!!!````"
	"!!!!````````````````````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````!!!!````!!!!````````````!!!!````````````````````"
	"!!!!````````````!!!!````!!!!````````!!!!!!!!````!!!!````````````"
	"!!!!````!!!!````````````````````!!!!````````````!!!!````!!!!````"
	"!!!!````````````````````````````!!!!````````````!!!!````````````"
	"!!!!````````````!!!!````````!!!!````!!!!````````````!!!!````!!!!"
	"````````````!!!!````!!!!````````````````!!!!````````````````!!!!"
	"````````````````````````!!!!````````````````````````!!!!````````"
	"````````````!!!!````````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!````!!!!````"
	"````````!!!!````!!!!````````````````````!!!!````````````!!!!````"
	"!!!!````````````````````````!!!!````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````````````!!!!````````````````````"
	"````!!!!````````!!!!````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````!!!!````!!!!````````````!!!!````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````````!!!!"
	"````````````````````````````!!!!````````````!!!!````````````````"
	"!!!!````````````!!!!````````!!!!````!!!!````````!!!!````!!!!````"
	"!!!!````````````!!!!````````````````!!!!````!!!!````````````!!!!"
	"````````````````!!!!!!!!````````````````````````!!!!````````````"
	"````````````!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````!!!!````!!!!````````!!!!````"
	"!!!!````!!!!````!!!!````````!!!!````!!!!!!!!````````````!!!!````"
	"````````````````````````````!!!!````````````````````````````````"
	"!!!!````````````````````````````````````!!!!````````````````````"
	"!!!!!!!!````````````````````````````````````````!!!!!!!!````````"
	"````!!!!````````````````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````````````````````!!!!````````````!!!!````````````"
	"````!!!!````````````````````````!!!!````!!!!````````````!!!!````"
	"````````!!!!````````````!!!!````````````!!!!````````````````!!!!"
	"````````````````!!!!!!!!````````````````!!!!!!!!````````````````"
	"!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!````````"
	"````````````````````````````!!!!````````````````!!!!````````````"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````!!!!````"
	"````!!!!````````!!!!````````````````````!!!!````````````````````"
	"!!!!````````````!!!!````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````````````!!!!````!!!!````````!!!!````````!!!!````"
	"````````````````!!!!````````````!!!!````!!!!````````!!!!!!!!````"
	"!!!!````````````!!!!````!!!!````````````````````!!!!````````````"
	"!!!!````!!!!````````!!!!````````!!!!````````````!!!!````````````"
	"!!!!````````````!!!!````````````!!!!````````````!!!!````````````"
	"````!!!!````!!!!````````!!!!````````````!!!!````````````!!!!````"
	"````````!!!!````````````````````````````!!!!````````````````````"
	"````````!!!!````````````````!!!!````````````````````````````````"
	"````````````````````````````````````````````````!!!!````````!!!!"
	"!!!!````!!!!````````````!!!!````!!!!````````````!!!!````!!!!````"
	"````!!!!!!!!````!!!!````````````!!!!````````!!!!````````````````"
	"!!!!````````!!!!!!!!````!!!!````````````!!!!````````````!!!!````"
	"````````````````````!!!!````````!!!!````````!!!!````````````````"
	"!!!!````````````!!!!````!!!!````!!!!````!!!!````````````!!!!````"
	"!!!!````````````!!!!````!!!!````````````!!!!````!!!!````````!!!!"
	"!!!!````````!!!!````````````````!!!!````````````!!!!````````!!!!"
	"````````!!!!````!!!!````````!!!!!!!!````````````!!!!````````````"
	"````!!!!````!!!!````````````!!!!````!!!!````````````````!!!!````"
	"````````!!!!````````````````````````````!!!!````````````````````"
	"!!!!````````````````````!!!!````````````````````````````````````"
	"````````!!!!````````````````````````````````````````!!!!````!!!!"
	"````````````!!!!!!!!!!!!````````!!!!````````````!!!!````````!!!!"
	"!!!!!!!!````!!!!````````````````````````````````!!!!````````````"
	"````````````!!!!````````````````````````````````````````!!!!````"
	"````````````````!!!!!!!!````````````````````````````````````````"
	"!!!!!!!!````````!!!!````````````````````````!!!!!!!!!!!!````````"
	"!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!"
	"````````````````````!!!!````````!!!!!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!````````````````!!!!````````````````!!!!!!!!!!!!````````"
	"````!!!!!!!!````````````````````!!!!!!!!````````````````!!!!!!!!"
	"````````````````````````!!!!!!!!````````````````````````!!!!!!!!"
	"````````````````````````!!!!````````````````````!!!!!!!!!!!!````"
	"!!!!````````````!!!!````!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!"
	"````````!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!````!!!!````"
	"````````````````````!!!!!!!!!!!!````````!!!!````````````!!!!````"
	"````!!!!!!!!!!!!````````````!!!!!!!!!!!!````````!!!!````````````"
	"!!!!````!!!!!!!!!!!!!!!!!!!!````!!!!````````````!!!!````!!!!````"
	"````````!!!!````````!!!!!!!!!!!!````````!!!!````````````````````"
	"````!!!!!!!!!!!!````````!!!!````````````!!!!````````!!!!!!!!!!!!"
	"````````````````!!!!````````````````!!!!!!!!!!!!````````````````"
	"!!!!````````````````!!!!````!!!!````````!!!!````````````!!!!````"
	"````````!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````!!!!````"
	"````````````````````````!!!!````````````````!!!!````````````````"
	"````````````````````````````````````````````````````````````````"
	"````!!!!!!!!````!!!!````!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!"
	"````````````!!!!!!!!````!!!!````````!!!!!!!!!!!!````````````!!!!"
	"````````````````````!!!!!!!!````!!!!````!!!!````````````!!!!````"
	"````````!!!!!!!!````````````````````!!!!````````!!!!````````````"
	"!!!!````````````!!!!!!!!````````!!!!````!!!!````!!!!````!!!!````"
	"````````!!!!````````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!````````"
	"````!!!!!!!!````!!!!````!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"````````````````!!!!!!!!````````````!!!!!!!!````!!!!````````````"
	"!!!!````````````````!!!!````!!!!````````!!!!````````````!!!!````"
	"````````!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````!!!!````"
	"````````````````!!!!````````````````````!!!!````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"!!!!````````````````````````!!!!````````````````````````````````"
	"````````````````````````````````````!!!!````````````````````````"
	"````````````````````````````````!!!!````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````!!!!````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````!!!!````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````!!!!````````````````````````````````````````````````!!!!"
	"````````````````````````````````!!!!!!!!!!!!!!!!!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!````````````"
	"````````````````````````````````````````````````````!!!!````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````!!!!````"
	"````````````````````````````````!!!!````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````!!!!````````````````````````````````````````"
	"````````!!!!````````````````````!!!!````````````````````!!!!````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````!!!!````````````````!!!!````````````````````"
	"````````````````````````````````````````````````!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````!!!!````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!!!!!````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````!!!!````````````````````````````````````"
	"````````````!!!!````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````!!!!!!!!!!!!"
	"````````````````````````````````````````````````````````!!!!!!!!"
	"!!!!````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````!!!!````````````````````````````````````!!!!````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````````````````````"
	"````````````````````````!!!!````````````````````````````````````"
	"````````!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!!!!!!!!!````````````"
	"````````````````````!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!````````````"
	"````````````````!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````";



static const int numbers[10][120] = {
    {0, 0, 0, 1, 1, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 0, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 0, 1, 1, 1, 1, 0, 0,
     0, 0, 0, 1, 1, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 0, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 1, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 0, 0, 0,
     0, 1, 1, 1, 1, 1, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 0, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 1, 0, 0, 0, 0,
     0, 0, 0, 0, 1, 0, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 0, 1, 1, 1, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 1, 0, 0, 0, 1, 0, 0,
     0, 1, 1, 1, 1, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 0, 1, 0, 0, 0, 1, 0,
     0, 0, 1, 0, 0, 0, 1, 0,
     0, 0, 1, 0, 0, 0, 1, 0,
     0, 0, 1, 0, 0, 0, 1, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 1, 1, 1, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 1, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 0, 0},

    {0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 1, 1, 1, 1, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 0, 0, 0, 0, 1, 0,
     0, 1, 1, 1, 1, 1, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 1, 0,
     0, 0, 0, 0, 0, 0, 0, 0}};



static const int chr_rows=13;
static const int chr_cols=6;

static const int num_rows=13;
static const int num_cols=8;

void draw_number(_DPlane<unsigned char> &img, int number, int digits, const DPoint &location,
	    int value)
{
  int row = location.row(), col = location.col();

    for(int d=digits; d>0; d--)
    {
        int num = (number % int(pow(10.,d))) / int(pow(10.,d-1));

	assert(num >= 0 && num <= 9);

        for(int i=0; i<num_rows; i++)
            for(int j=0; j<num_cols; j++)
                if(row+i >= 0 && col+j >=0 && row+i < img.rows() && col+j < img.cols())
                    img[row+i][col+j] = int(img[row+i][col+j])/2 | int(numbers[num][i*num_cols + j] * value);

        col += num_cols;
    }

    return;
}


static int first=1;

void draw_text(_DPlane<unsigned char> &img, char *str, const DPoint &location, int value, bool rev)
{
  static _DPlane<unsigned char> characters(height, width);

  DPoint pt(location);

  if(first)
    {
      char *data = header_data;
      for(int i=0; i<height; i++)
	for(int j=0; j<width; j++)
	  {
	    char pixel[4];

	    HEADER_PIXEL(data, pixel);

	    characters[i][j] = pixel[0];
	  }

      first=0;
    }

  for(size_t i=0; i<strlen(str); i++)
    {
      int char_no = str[i] - 33;

      if(char_no < 0) 
	{
	  pt.col(pt.col() + chr_cols);
	  continue;
	}

      if(pt.row() >= 0 && pt.col() >= 0 && pt.row() + chr_rows < img.rows() && pt.col() + chr_cols < img.cols())
	if(rev)
	  img.set_submatrix(pt, characters.extract(DRect(0, char_no*chr_cols, chr_rows-1, (char_no+1)*chr_cols-1)));
	else
	  img.set_submatrix(pt, (unsigned char)255 - characters.extract(DRect(0, char_no*chr_cols, chr_rows-1, (char_no+1)*chr_cols-1)));
      pt.col(pt.col() + chr_cols);
    }
}
