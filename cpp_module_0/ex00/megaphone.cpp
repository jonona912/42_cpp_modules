#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		int i = 1;
		int	j;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << static_cast<char>(toupper(argv[i][j]));
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
