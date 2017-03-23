#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
std::fstream file;

long double pow(long double x, unsigned int n)
{
	if (n == 0)
	{
		return 1.0;
	}
	else if (n % 2 == 1)
	{
		return x*pow(x, n - 1);
	}
	else
	{
		long double a = pow(x, n / 2);
		return a*a;
	}
}

long double factorial(long double a) {
	if ((a == 0) || (a == 1)) return 1;
	long double s = 1;
	for (long double i = 1; i <= a; i++) s *= i;
	return s;
}

long double lib(long double x) {
	return exp(x);
}

long double defAsc(long double x, long double n) {
	long double sum = 1;

	for (long double i = 1; i <= n; i++) {
		sum += pow(x, i) / factorial(i);
	}

	return sum;
}

long double defDesc(long double x, long double n) {
	long double sum = 1;
	for (long double i = n; i >= 1; i--)
		sum += pow(x, i) / factorial(i);

	return sum;
}

long double prev(long double x, long double n) {
	long double sum = 1;
	long double prevElem = 1;


	for (long double i = 1; i <= n; i++){
		prevElem *= x / i;
		sum += prevElem;
	}

	return sum;
}

long double medTab[29] = {0};

long double minDefAsc(long double x) {

	long double min = 999;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - defAsc(i, 300)) < min)
			min = abs(lib(i) - defAsc(i, 300));
	}

	return min;
}

long double minDefDesc(long double x) {

	long double min = 999;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - defDesc(i, 300)) < min)
			min = abs(lib(i) - defDesc(i, 300));
	}

	return min;
}

long double minPrev(long double x) {

	long double min = 999;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - prev(i, 300)) < min)
			min = abs(lib(i) - prev(i, 300));
	}

	return min;
}

long double maxDefAsc(long double x) {

	long double max = 0;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - defAsc(i, 300)) > max)
			max = abs(lib(i) - defAsc(i, 300));
	}

	return max;
}

long double maxDefDesc(long double x) {

	long double max = 0;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - defDesc(i, 300)) > max)
			max = abs(lib(i) - defDesc(i, 300));
	}

	return max;
}

long double maxPrev(long double x) {

	long double max = 0;
	for (long double i = 2; i <= x; i++) {
		if (abs(lib(i) - prev(i, 300)) > max)
			max = abs(lib(i) - prev(i, 300));
	}

	return max;
}


int main() {
	file.open("wyniki.txt", std::ios::out);
	file << "Metody numeryczne, projekt pierwszy, funkcja e^x \n";
	file << "Maciej Komorowski 160822 \n*************************************************";
	file << "\n\n\nZ biblioteki math.h (exp(x))\n";


	for (long double x = 2.0; x <= 4.0; x += 1)
		file << "x:\t" << std::fixed << std::setprecision(3) << x << "\t\t" << std::setprecision(30) << lib(x) << "\n";

	file << "\n\n\nDodawanie od poczatku, z definicji  \n";
	for (long double x = 2.0; x <= 4.0; x += 1)
		for (long double y = 1; y < 20; y += 1)
			file << "x:\t" << std::fixed << std::setprecision(3) << x << "\t n: " << (int)y << "\t\t" << std::setprecision(30) << abs(lib(x) - defAsc(x, y)) << "\n";

	file << "\n\n\nDodawanie od konca, z definicji  \n";
	for (long double x = 2.0; x <= 4.0; x += 1)
		for (long double y = 1; y < 20; y += 1)
			file << "x:\t" << std::fixed << std::setprecision(3) << x << "\t n: " << (int)y << "\t\t" << std::setprecision(30) << abs(lib(x) - defDesc(x, y)) << "\n";

	file << "\n\n\nDodawanie od poczatku, z poprzedniego wyrazu  \n";
	for (long double x = 2.0; x <= 4.0; x += 1)
		for (long double y = 1; y < 20; y += 1)
			file << "x:\t" << std::fixed << std::setprecision(3) << x << "\t n: " << (int)y << "\t\t" << std::setprecision(30) << abs(lib(x) - prev(x, y)) << "\n";


	file << "\n\nmin def  asc\t\t" << std::fixed << std::setprecision(40) << minDefAsc(30) <<  "\n";
	file << "min def desc\t\t" << std::fixed << std::setprecision(40) << minDefDesc(30) << "\n";
	file << "min     prev\t\t" << std::fixed << std::setprecision(40) << minPrev(30) << "\n\n";

	file << "max def  asc\t\t" << std::fixed << std::setprecision(40) << maxDefAsc(30) << "\n";
	file << "max def desc\t\t" << std::fixed << std::setprecision(40) << maxDefDesc(30) << "\n";
	file << "max     prev\t\t" << std::fixed << std::setprecision(40) << maxPrev(30) << "\n\n";




	long double sum = 0;
	for (int i = 2; i <= 30; i++) {
		sum += abs(lib(i) - defAsc(i, 200));
	}
	file << "srednia     asc \t\t" << std::fixed << std::setprecision(60) << sum/28 << "\n";

	sum = 0;
	for (int i = 2; i <= 30; i++) {
		sum += abs(lib(i) - defDesc(i, 200));
	}
	file << "srednia     desc \t\t" << std::fixed << std::setprecision(60) << sum / 28 << "\n";

	sum = 0;
	for (int i = 2; i <= 30; i++) {
		sum += abs(lib(i) - prev(i, 200));
	}
	file << "srednia     prev \t\t" << std::fixed << std::setprecision(60) << sum / 28 << "\n\n";


	for (int i = 2; i <= 30; i++) {
		medTab[i - 2] = abs(lib(i) - defAsc(i, 200));
	}
	std::sort(std::begin(medTab), std::end(medTab));
	file << "mediana     asc \t\t" << std::fixed << std::setprecision(60) << medTab[14] << "\n";


	for (int i = 2; i <= 30; i++) {
		medTab[i - 2] = abs(lib(i) - defDesc(i, 200));
	}
	std::sort(std::begin(medTab), std::end(medTab));
	file << "mediana     desc\t\t" << std::fixed << std::setprecision(60) << medTab[14] << "\n";



	for (int i = 2; i <= 30; i++) {
		medTab[i-2] = abs(lib(i) - prev(i, 200));
	}
	std::sort(std::begin(medTab), std::end(medTab));
	file << "mediana     prev\t\t" << std::fixed << std::setprecision(60) << medTab[14] << "\n";


	file.close();
	return 0;
}