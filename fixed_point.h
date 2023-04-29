/** ADDITION: Fixed-point representation for PintOS */

/*
   * Fixed-point representation is a way to write decimal numbers using an integer value
   * It is much faster than floating-point representation, but it has a limited range
   * Assuming 32-bit numbers -> 16 bits for int part & 15 bits for fraction part + 1 sign bit
   * The number is represented by all 32 bits
   * FP Addition: 			(a * (2 ^ FRACTION_BITS)) + (b * (2 ^ FRACTION_BITS)) == (a + b) * (2 ^ FRACTION_BITS) == (a + b) * (1 << FRACTION_BITS)
   * FP Subtraction: 	(a * (2 ^ FRACTION_BITS)) - (b * (2 ^ FRACTION_BITS)) == (a - b) * (2 ^ FRACTION_BITS) == (a - b) * (1 << FRACTION_BITS)
   * FP Multiplication: 	(a * (2 ^ FRACTION_BITS)) * (b * (2 ^ FRACTION_BITS)) == (a * b) * (2 ^ (2 * FRACTION_BITS))  # Has to be rescaled to 2 ^ FRACTION_BITS #
																																	   == (a * b) / (2 ^ FRACTION_BITS) == (a * b) / (1 << FRACTION_BITS)
   * FP Division: 			(a * (2 ^ FRACTION_BITS)) * (b * (2 ^ FRACTION_BITS)) == a / b  # Has to be rescaled to 2 ^ FRACTION_BITS #
																														               == (a * (2 ^ FRACTION_BITS)) / b == (a * (1 << FRACTION_BITS)) / b
   * This implementation is done using macros just to avoid any speed complications
   * All macros/macro-like functions begin with "FP" indicating fixed-point 
   */

#ifndef FIXED_POINT_THREADS_H 
#define FIXED_POINT_THREADS_H

// Macros
#define FP_INT_BITS 										    16
#define FP_FRACTION_BITS 							15
#define FP_FRACTION 						(1 << (FP_FRACTION_BITS))

// Macro-like functions: Conversion
#define FP_CONVERT_TO_FP(X) 								(X) * (FP_FRACTION)
#define FP_CONVERT_TO_INT_ZERO(X) 					(X) / (FP_FRACTION) 
#define FP_CONVERT_TO_INT_NEAREST(X) 			( ( (X) >= 0 ) ? ( ( ( (X) + (FP_FRACTION) ) / 2) / (FP_FRACTION) ) : ( ( ( (X) - (FP_FRACTION) ) / 2) / (FP_FRACTION) ) )

// Macro-like functions: Arithmetic Operations
#define FP_ADD(X, Y) 														( ( (X) + (Y) ) * (FP_FRACTION) )
#define FP_SUB(X, Y) 														( ( (X) - (Y) ) * (FP_FRACTION) )
#define FP_MULTIPLY(X, Y) 											( ( ( (int64_t)(X) ) * (Y) ) / (FP_FRACTION) )
#define FP_DIVIDE(X, Y) 												( ( ( (int64_t)(X) ) * (FP_FRACTION) ) / (Y))

#endif

/** END OF ADDITION */
