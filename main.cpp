#include <iostream>

char tilesArray[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool tileTaken[9] = { false, false, false, false, false, false, false, false, false };
bool winner = false;

void displayBoard()
{
	std::cout << "------------" << std::endl;
	std::cout <<"| " << tilesArray[0] << " | " << tilesArray[1] << " | " << tilesArray[2] << " |" <<std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "| " << tilesArray[3] << " | " << tilesArray[4] << " | " << tilesArray[5] << " |" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "| " << tilesArray[6] << " | " << tilesArray[7] << " | " << tilesArray[8] << " |" << std::endl;
	std::cout << "------------" << std::endl;
}

short askUserForX()
{
	short xInput;

	std::cout << "Where do you want to put X: ";
	std::cin >>xInput;

	return xInput;

}

short askUserForO()
{
	short oInput;

	std::cout << "Where do you want to put O: ";
	std::cin >> oInput;

	return oInput;

}

bool checkWinner()
{

	// 0 1 2
	// 3 4 5
	// 6 7 8

	if (tilesArray[0] == tilesArray[1] && tilesArray[1] == tilesArray[2])
	{
		std::cout << "\n\n" << tilesArray[0] << " wins!" << std::endl;
		return true;
	}
	if (tilesArray[3] == tilesArray[4] && tilesArray[4] == tilesArray[5])
	{
		std::cout << "\n\n" << tilesArray[3] << " wins!" << std::endl;
		return true;
	}
	if (tilesArray[6] == tilesArray[7] && tilesArray[7] == tilesArray[8])
	{
		std::cout << "\n\n" << tilesArray[6] << " wins!" << std::endl;
		return true;
	}

	if (tilesArray[0] == tilesArray[3] && tilesArray[3] == tilesArray[6])
	{
		std::cout << "\n\n" << tilesArray[0] << " wins!" << std::endl;
		return true;
	}
	if (tilesArray[1] == tilesArray[4] && tilesArray[4] == tilesArray[7])
	{
		std::cout << "\n\n" << tilesArray[1] << " wins!" << std::endl;
		return true;
	}
	if (tilesArray[2] == tilesArray[5] && tilesArray[5] == tilesArray[8])
	{
		std::cout << "\n\n" << tilesArray[2] << " wins!" << std::endl;
		return true;
	}

	if (tilesArray[0] == tilesArray[4] && tilesArray[4] == tilesArray[8])
	{
		std::cout << "\n\n" << tilesArray[0] << " wins!" << std::endl;
		return true;
	}
	if (tilesArray[2] == tilesArray[4] && tilesArray[4] == tilesArray[6])
	{
		std::cout <<"\n\n" << tilesArray[2] << " wins!" << std::endl;
		return true;
	}

	return false;

}

int main()
{
	
	std::cout << "Version 1.0" <<std::endl;

	short xInput, oInput;
	bool wins = false;

	while (true)
	{

		wins = checkWinner();

		if (wins == true)
		{
			displayBoard();
			break;
		}

		do 
		{

			displayBoard();
			xInput = askUserForX();

			if (tileTaken[xInput - 1] == true) 
			{
				std::cout << "This tile is taken, Choose another one! " <<std::endl;
			}
			else 
			{
				tilesArray[xInput - 1] = 'X';
				tileTaken[xInput - 1] = true;
				break;
			}

		} while (true);

		wins = checkWinner();

		if (wins == true)
		{
			displayBoard();
			break;
		}

		do
		{

			displayBoard();
			oInput = askUserForO();

			if (tileTaken[oInput - 1] == true)
			{
				std::cout << "This tile is taken, Choose another one! " << std::endl;
			}
			else
			{
				tilesArray[oInput - 1] = 'O';
				tileTaken[oInput - 1] = true;
				break;
			}

		} while (true);

	}

	return 0;
}
