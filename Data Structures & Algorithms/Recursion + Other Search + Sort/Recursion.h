#include <iostream>
#include <string>
using namespace std;

#ifndef RECURSION_H_
#define RECURSION_H_

class Recursion {

public:

	static int sumEvenDigits(int n) {
		//if a number is less than 10 it is a single digit, so return it
		if (n < 10)
		{
			return n;
		}
		else {
			//constribute to sum if it is even
			if (((n % 10)  % 2 == 0) && (n % 10) > 0) {
				std::cout << n%10;
			return sumEvenDigits(n / 10) + n % 10;
			}
			else
			{
				return sumEvenDigits(n/10);
			}
		}
	};




	static void allBinaryStringsWithMoreOnes(int n) {
		allBinaryStringsWithMoreOnes("", 0, 0, n);
	}

private:

	static void allBinaryStringsWithMoreOnes(string str, int numZeroes,
			int numOnes, int n) {
		//base case
		if (str.length()==n && numZeroes < numOnes)
		{
			std::cout << str << "\n";
			
			return;
		}

		//recursive rule
		else if (str.length() < n)
		{
			allBinaryStringsWithMoreOnes(str + "0", numZeroes+1, numOnes, n);
			allBinaryStringsWithMoreOnes(str + "1", numZeroes, numOnes+1, n);
		}
	}
};

#endif /* RECURSION_H_ */
