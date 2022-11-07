//#############################################################################
// Script Name:		main.c						      /
//									     /
// Purpose of Script:	Calculate & Output  volume of an oblate spheroid,   /
//			given equatorial diameter & polar diameter.	   /  
//									  /  
// Author:		Will Stevens					 /     
//									/      
// Contact Email:	wxs244@student.bham.ac.uk		       / 	      
//##################################################################### 


// Includes 

#include <stdio.h>		// This will be used for user input & output 
#include <math.h>		// This is used for standard form calculation.

// Definitions

#define PI (3.1415926535)	// This will come in handy for calculation

// For each of our mathematical functions, a respective function will exist
// below for ease of use & to retain core OOP values.


// Radius, given any diameter.
//
// Variables:
// radius_r	:	Radius output. Double
// d		:	Diameter, Double
double radius_r(double d){
	return (d/2);
}

// Height Difference, given equatorial diameter & polar diameter
//
// Variables:
// height_h	:	Difference in height, Double
// d_e		:	Equatorial Diameter, Double
// d_p		:	Polar Diameter, Double
double height_h(double d_e, double d_p){
	return (0.5*(d_e - d_p));
}

// Volume 1, given radius
//
// Variables:
// vol_1	:	Volume 1, Double
// r		:	Radius, Double
double vol_1(double r){
	return (PI*4/3*r*r*r);		// It's easier to hardcode r*r*r than
}					// to import math library and use pow()
					// function


// Volume 2, given radius and height
//
// Variables:
// vol_2	:	Volume 2, Double
// r		:	Radius, Double
// h		:	Height Function, Double
double vol_2(double r,double h){
	return((PI/3*h*h)*((3*r)-h));
}

// Final Volume, given Volume 1 & Volume 2
//
// Variables:
// vol		:	Volume, Double
// vol_1	:	Volume 1, Double
// vol_2	:	Volume 2, Double
double vol(double vol_1,double vol_2){
	return (vol_1 - (2*vol_2));
}

// Find the largest power of 10 that fits inside a number
//
// Variables:
// findExponent	:	Our Result, Int
int findExponent(double value){
	return floor(log10(value));
}


// Take a Double and print it to stdout in standard form
//
// Variables:
//
// exponent	:	Result of above findExponent function, Int
// prefix	:	Prefix to "x10^", Float
void standardFormIfy(double value){
	int exponent = findExponent(value);
	float prefix = value/(pow(10,exponent));
	printf("%fx10^%d",prefix,exponent);	
}



// Main Function
int main(void){
	float d_e;
	float d_p;

	printf("\nEnter Equatorial Diameter, in km: ");
	scanf("%f",&d_e);

	printf("Enter Polar Diameter, in km: ");
	scanf("%f",&d_p);
	
	if(d_p>d_e){
		printf(
"Error - the equatorial diameter must be greater than the polar diameter\n");
		return -1;
	}

	if(d_p<0 || d_e<0){
		printf("Error - your diameters must be positive\n");
		return -1;
	}

	double result;
	double v_1;
	double v_2;
	
	v_1 = vol_1(radius_r(d_e));
	v_2 = vol_2(radius_r(d_e),height_h(d_e,d_p));
	
	result = vol(v_1,v_2);
	
	printf("V1=");standardFormIfy(v_1);
	printf(" km^3 V2=");standardFormIfy(v_2);
	printf(" km^3\nThe Volume of the planet is ");standardFormIfy(result);
	printf(" km^3\n");
	return 0;
}
