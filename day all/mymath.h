#pragma once
#include <stdio.h>

int Fibonachi(int n);
int Fibonachi(int n) {
	if (n < 1) return -1;
	if (n == 1 || n == 2) return 1;
	return Fibonachi(n - 1) + Fibonachi(n - 2);
}
int ThreeBeforeAdded(int n);
int ThreeBeforeAdded(int n) { 
	if (n < 1) return -1;
	if (n == 1 || n == 2 || n == 3) return 1;
	return ThreeBeforeAdded(n - 1) + ThreeBeforeAdded(n - 2) + ThreeBeforeAdded(n - 3);

}
int Three(int n);
int Three(int n) { 
	if (n < 1) return -1;
	if (n == 1 || n == 2 || n == 3) return 1;
	return Three(n - 1) * (Three(n - 2) + Three(n - 3));
} 