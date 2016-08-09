#include "Math.h"

int Math_nextPowerOfTwo(double x) {

}

int Math_floor(double x) {
	return (int)x;
}

int Math_ceil(double x) {
	int val = (int)x;
	if (val < x) {
		val++;
	}
	return val;
}

int Math_round(double x) {
	int lower = Math_floor(x);
	int upper = Math_ceil(x);
	if (upper - x < x - lower) {
		return upper;
	}
	return lower;
}

double Math_absd(double x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

double Math_logd(double x) {
	return 0;
}

double Math_exp(double x) {
	return 0;
}

double Math_powd(double x, double y) {
	return 0;
}