#include <math.h>
#include <stdbool.h>

double calculate_perim(double a, double b, double c){
     return a + b + c;
}

double calculate_s(double a, double b, double c){
    double p = (calculate_perim(a,b,c) / 2);
    double value = p * (p - a) * (p - b) * (p - c);
    double square = sqrt(value);
    return square;
}

bool isexist(double a, double b, double c){
	return (a < b + c && b < a + c && c < a + b);
}
