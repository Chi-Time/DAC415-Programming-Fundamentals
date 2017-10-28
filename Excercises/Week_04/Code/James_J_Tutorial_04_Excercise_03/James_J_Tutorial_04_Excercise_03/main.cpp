#include <iostream>
#include <conio.h>

int main ()
{
	int i = 16;
	int j = 32;
	int k = 8;
	bool result;

	std::cout << std::boolalpha;

	result = (i == 16);
	std::cout << "r = (i == 16) is " << result << std::endl;

	result = (k != 16);
	std::cout << "r = (k != 16) is " << result << std::endl;

	result = (k < 10);
	std::cout << "r = (k < 10) is " << result << std::endl;

	result = (j > 33);
	std::cout << "r = (j > 33) is " << result << std::endl;

	result = (j == (k * 2));
	std::cout << "r = (j == (k * 2)) is " << result << std::endl;

	result = (j == (i * 2));
	std::cout << "r = (j == (i * 2)) is " << result << std::endl;

	result = ((k + j) <= (j - i));
	std::cout << "r = ((k + j) <= (j - i)) is " << result << std::endl;

	result = (((i + j + k) / k) >= 7);
	std::cout << "r = (((i + j + k) / k) >= 7) is " << result << std::endl;

	result = ((i / k) > (j / i)) ? true : false;
	std::cout << "r = ((i / k) > (j / i)) is " << result << std::endl;

	_getch ();

	return 0;
}
