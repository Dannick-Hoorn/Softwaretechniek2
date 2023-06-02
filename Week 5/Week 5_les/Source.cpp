#include <iostream>


void main()
{
	long totaal = 0;
	try
	{
		while (true)
		{
			new char[1000 * 1000];
			totaal++;
			std::cout << totaal << " MB" << std::endl;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Geheugen is op";
	}
}