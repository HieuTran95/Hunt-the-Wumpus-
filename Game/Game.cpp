#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>


const int r = 7;
const int c = 7;
const bool debug = true;

struct PlayerData {
	int bat;
	int pit;
	int wumpusSmell;
	int player;
	int wumpusAlive;
	int extra;
	int arrow;
	int win;
};


void game(int x, int y, int xW, int yW, int xB1, int yB1, int xB2, int yB2, int xP1, int yP1, int xP2, int yP2, int xEX1, int yEX1, int xEX2, int yEX2);
void getData(PlayerData& data);

class Position {
	int position;
public:
	Position(int);
	int spawnB() {
		return 	rand() % position;
	}

	int spawnP() {
		int p = rand() % position;
		if (p == spawnB()) {
			p = rand() % position;
		}
		return p;

	}
	int spawnW() {
		int w = rand() % position;
		if (w == spawnB() && w == spawnP()) {
			w = rand() % position;
		}
		return w;
	}
	int spawnEX() {
		int ex = rand() % position;
		if (ex == spawnB() && ex == spawnW() && ex == spawnP()) {
			ex = rand() % position;
		}
		return ex;
	}
	int spawnPL() {
		int pl = rand() % position;
		if (pl == spawnB() && pl == spawnW() && pl == spawnP() && pl == spawnEX()) {
			pl = rand() % position;
		}
		return pl;
	}

};


Position::Position(int a) {
	position = 7;
}




void getData(PlayerData& data) {
	data.bat = 2;
	data.pit = 2;
	data.wumpusSmell = 0;
	data.player = 1;
	data.wumpusAlive = 1;
	data.extra = 2;
	data.arrow = 5;
	data.win = 1;
}

Position position(7);
int xPL() {
	int x;
	return x = position.spawnPL();
}
int yPL() {
	int y;
	return y = position.spawnPL();
}
int xWP() {
	int x;
	return x = position.spawnW();
}
int yWP() {
	int x;
	return x = position.spawnW();
}
int xB() {
	int x;
	return x = position.spawnB();
}
int yB() {
	int x;
	return x = position.spawnB();
}
int xBT2() {
	int x;
	return x = position.spawnB();
}
int yBT2() {
	int x;
	return x = position.spawnB();
}
int xP() {
	int x;
	return x = position.spawnP();
}
int yP() {
	int x;
	return x = position.spawnP();
}
int xPT2() {
	int x;
	return x = position.spawnP();
}
int yPT2() {
	int x;
	return x = position.spawnP();
}
int xEX() {
	int x;
	return x = position.spawnEX();
}
int yEX() {
	int x;
	return x = position.spawnEX();
}
int xEXA2() {
	int x;
	return x = position.spawnEX();
}
int yEXA2() {
	int x;
	return x = position.spawnEX();
}

std::ofstream outputFile("game.txt");

void game(int x, int y, int xW, int yW, int xB1, int yB1, int xB2, int yB2, int xP1, int yP1, int xP2, int yP2, int xEX1, int yEX1, int xEX2, int yEX2) {

	int cave[r][c];

	struct PlayerData data;
	getData(data);

	Position position(7);

	int move = 0;


	cave[yW][xW] = 1;

	cave[yB2][xB2] = 2;

	cave[yB1][xB1] = 0;

	cave[yP1][xP1] = 4;
	cave[yP2][xP2] = 3;

	cave[yEX1][xEX1] = 2;
	cave[yEX2][xEX2] = 4;


	int countARR = 0;
	int countARR2 = 0;
	int wumpus = data.wumpusSmell;
	int player = data.player;
	int wumpusAlive = data.wumpusAlive;
	int arrow = data.arrow;
	int win = data.win;



	while (wumpusAlive == 1 || player == 1) {
		std::cout << "Player at : (x)" << x << " , (y)" << y << std::endl;
		outputFile << x << std::endl;
		outputFile << y << std::endl;
		outputFile << xW << std::endl;
		outputFile << yW << std::endl;
		outputFile << xB1 << std::endl;
		outputFile << yB1 << std::endl;
		outputFile << xB2 << std::endl;
		outputFile << yB2 << std::endl;
		outputFile << xP1 << std::endl;
		outputFile << yP1 << std::endl;
		outputFile << xP2 << std::endl;
		outputFile << yP2 << std::endl;
		outputFile << xEX1 << std::endl;
		outputFile << yEX1 << std::endl;
		outputFile << xEX2 << std::endl;
		outputFile << yEX2 << std::endl;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (y == i && x == j) {
					std::cout << " p ";
				}
				else
					std::cout << " . ";
			}
			std::cout << "\n";
		}


		move = 0;

		if (cave[y - 1][x] == 1 || cave[y + 1][x] == 1 || cave[y][x - 1] == 1 || cave[y][x + 1] == 1) {
			std::cout << "You smell a foul stench nearby " << std::endl;
			wumpus = 1;
		}
		else {
			wumpus = 0;
		}

		if (cave[y][x] == 1) {
			std::cout << "You have been eaten by the wumpus. Game Over " << std::endl;
			break;
		}

		if (cave[y][x] == 0) {
			std::cout << "The Bat will drop you into any room " << std::endl;
			x = position.spawnPL();
			y = position.spawnPL();
			std::cout << "Player at : (x)" << x << " , (y)" << y << std::endl;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (y == i && x == j) {
						std::cout << " p ";
					}
					else
						std::cout << " . ";
				}
				std::cout << "\n";
			}
		}

		if (cave[y - 1][x] == 0 || cave[y + 1][x] == 0 || cave[y][x - 1] == 0 || cave[y][x + 1] == 0) {
			std::cout << "You hear flapping nearby " << std::endl;
		}


		if (cave[y - 1][x] == 2 || cave[y + 1][x] == 2 || cave[y][x - 1] == 2 || cave[y][x + 1] == 2) {
			std::cout << "You hear flapping nearby " << std::endl;

		}

		if (cave[y][x] == 2) {
			std::cout << "The Bat will drop you into any room " << std::endl;
			x = position.spawnPL();
			y = position.spawnPL();
			std::cout << "Player at : (x)" << x << " , (y)" << y << std::endl;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (y == i && x == j) {
						std::cout << " p ";
					}
					else
						std::cout << " . ";
				}
				std::cout << "\n";
			}
		}

		if (cave[y - 1][x] == 4 || cave[y + 1][x] == 4 || cave[y][x - 1] == 4 || cave[y][x + 1] == 4) {
			std::cout << "You feel a breeze nearby " << std::endl;
		}

		if (cave[y - 1][x] == 3 || cave[y + 1][x] == 3 || cave[y][x - 1] == 3 || cave[y][x + 1] == 3) {
			std::cout << "You feel a breeze nearby " << std::endl;
		}


		if (cave[y][x] == 4) {
			std::cout << "You fall to the doom. Game Over " << std::endl;
			break;
		}


		if (cave[y][x] == 3) {
			std::cout << "You fall to the doom. Game Over " << std::endl;
			break;
		}

		if (cave[y][x] == 2) {
			if (arrow < 8 && countARR < 1) {
				std::cout << "You found a magical Wumpus- Killing arrow! " << std::endl;
				arrow = arrow + 1;
				countARR = countARR + 1;
				std::cout << "You have " << arrow << " arrows " << std::endl;
			}
		}

		if (cave[y][x] == 4) {
			if (arrow < 8 && countARR2 < 1) {
				std::cout << "You found a magical Wumpus- Killing arrow! " << std::endl;
				arrow = arrow + 1;
				countARR2 = countARR2 + 1;
				std::cout << "You have " << arrow << " arrows " << std::endl;
			}
		}

		std::cout << "Please Choose:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n7. Save\n" << std::endl;

		int choose = 0;
		int room = 0;

		while (move < 1 || move > 4) {
			do {
				std::cin >> move;
				if (move < 1 || move > 8) {
					std::cout << "Choose the option again \n" << std::endl;
				}
			} while (move < 1 || move > 8);

			switch (move) {
			case 1:
				if (y < 7) {
					y += 1;
				}
				break;
			case 2:
				if (y > 0) {
					y -= 1;
				}
				break;
			case 3:
				if (x < 7) {
					x += 1;
				}
				break;
			case 4:
				if (x > 0) {
					x -= 1;
				}
				break;
			case 5:


				do {
					std::cout << "Choose the direction to shoot \n1. Move North\n2. Move South\n3. Move East\n4. Move West\n";
					std::cin >> choose;
					if (choose < 1 || choose > 4) {
						std::cout << "Choose the direction again \n" << std::endl;
					}
				} while (choose < 1 || choose > 4);


				do {
					std::cout << "How many rooms to shoot \n" << std::endl;
					std::cin >> room;
					if (room < 1 || room > 3) {
						std::cout << "Pick no less than 1 room and no more than 3 rooms \n" << std::endl;
					}
				} while (room < 1 || room > 3);


				if (choose == 1) {
					if (room == 1) {
						if (cave[y + 1][x] == 1 && arrow == 1 && wumpus <= 7) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 2) {
						if (cave[y + 1][x] == 1 && cave[y + 2][x] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 3) {
						if (cave[y + 1][x] == 1 && cave[y + 2][x] == 1 && cave[y + 3][x] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}

					}
					else {
						arrow = arrow - 1;

						std::cout << "You miss the shot. The Wumpus will move to other room. " << "You have " << arrow << " arrows left. " << std::endl;
						std::cout << " " << std::endl;
						std::cout << "You can:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n";
						int random = rand() % 4;

						if (random == 0) {
							yW = yW - 1;

						}
						if (random == 1) {
							yW = yW + 1;

						}
						if (random == 2) {
							xW = xW - 1;

						}
						if (random == 3) {
							xW = xW + 1;

						}

					}
				}
				if (choose == 2) {
					if (room == 1) {
						if (cave[y - 1][x] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 2) {
						if (cave[y - 1][x] == 1 && cave[y - 2][x] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 3) {
						if (cave[y - 1][x] == 1 && cave[y - 2][x] == 1 && cave[y - 3][x] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					else {
						arrow = arrow - 1;

						std::cout << "You miss the shot. The Wumpus will move to other room. " << "You have " << arrow << " arrows left. " << std::endl;
						std::cout << " " << std::endl;
						std::cout << "You can:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n";
						int random = rand() % 4;

						if (random == 0) {
							yW = yW - 1;

						}
						if (random == 1) {
							yW = yW + 1;

						}
						if (random == 2) {
							xW = xW - 1;

						}
						if (random == 3) {
							xW = xW + 1;

						}

					}
				}
				if (choose == 3) {
					if (room == 1) {
						if (cave[y][x + 1] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 2) {
						if (cave[y][x - 1] == 1 && cave[y][x + 2] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 3) {
						if (cave[y][x + 1] == 1 && cave[y][x + 2] == 1 && cave[y][x + 3] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					else {
						arrow = arrow - 1;

						std::cout << "You miss the shot. The Wumpus will move to other room. " << "You have " << arrow << " arrows left. " << std::endl;
						std::cout << " " << std::endl;
						std::cout << "You can:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n";
						int random = rand() % 4;

						if (random == 0) {
							yW = yW - 1;

						}
						if (random == 1) {
							yW = yW + 1;

						}
						if (random == 2) {
							xW = xW - 1;

						}
						if (random == 3) {
							xW = xW + 1;

						}

					}
				}
				if (choose == 4) {
					if (room == 1) {
						if (cave[y][x - 1] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 2) {
						if (cave[y][x - 1] == 1 && cave[y][x - 1] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					if (room == 3) {
						if (cave[y][x - 1] == 1 && cave[y][x - 2] == 1 && cave[y][x - 3] == 1 && arrow <= 7 && wumpus == 1) {
							std::cout << "Congratulations, You shot the wumpus!\n";
							win = 0;
							break;
						}
					}
					else {
						arrow = arrow - 1;

						std::cout << "You miss the shot. The Wumpus will move to other room. " << "You have " << arrow << " arrows left. " << std::endl;
						std::cout << " " << std::endl;
						std::cout << "You can:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n";
						int random = rand() % 4;

						if (random == 0) {
							yW = yW - 1;

						}
						if (random == 1) {
							yW = yW + 1;

						}
						if (random == 2) {
							xW = xW - 1;

						}
						if (random == 3) {
							xW = xW + 1;

						}
					}
				}
				break;
			case 6:
				std::cout << "Exit\n";
				exit(0);
			case 7:

				outputFile.close();
				std::cout << "Saved \n";
				std::cout << "Please Choose:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow \n6. Exit\n7. Save\n" << std::endl;
			}
			if (win == 0) {
				break;
			}
			else if (arrow == 0) {
				std::cout << "Run out of arrows. End Game!" << std::endl;
				break;
			}

		}//end of inner while loop
		if (arrow == 0) {
			std::cout << "Run out of arrows. End Game!" << std::endl;
			break;
		}
		else if (win == 0) {
			break;
		}
	}//end of outer while loop



}


int main() {
	srand(time(NULL));

	int menu;

	int x = xPL();
	int y = yPL();

	int xW = xWP();
	int yW = yWP();

	int xB1 = xB();
	int yB1 = yB();

	int xB2 = xBT2();
	int yB2 = yBT2();

	int xP1 = xP();
	int yP1 = yP();

	int xP2 = xPT2();
	int yP2 = yPT2();

	int xEX1 = xEX();
	int yEX1 = yEX();

	int xEX2 = xEXA2();
	int yEX2 = yEXA2();


	if (debug == true) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (i == yW && j == xW) {
					std::cout << "w";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (i == y && j == x) {
					std::cout << "p";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yB1 == i && xB1 == j) {
					std::cout << "b1";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yB2 == i && xB2 == j) {
					std::cout << "b2";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yP1 == i && xP1 == j) {
					std::cout << "p1";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yP2 == i && xP2 == j) {
					std::cout << "p2";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yEX1 == i && xEX1 == j) {
					std::cout << "ex1";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (yEX2 == i && xEX2 == j) {
					std::cout << "ex2";
				}
				else
					std::cout << " - ";
			}
			std::cout << "\n";
		}
	}

	std::cout << "\n";
	std::cout << "Welcome to the Hunting Wumpus game \n" << std::endl;
	std::cout << "Some symbols in the game that the player need to know : \n" << std::endl;
	std::cout << "P = player , B1 = bat #1 , B2 = bat #2 , W = wumpus , P1 = pit#1 , \n";
	std::cout << "P2 = pit#2 , EX1 = extra arrow #1 , Ex2 = extra arrow #2 \n" << std::endl;


	do {
		std::cout << "1. New game " << std::endl;
		std::cout << "2. Continue " << std::endl;
		std::cout << "3. Exit " << std::endl;
		std::cin >> menu;
		if (menu < 1 || menu > 3) {
			std::cout << "Choose again \n" << std::endl;
		}
	} while (menu < 1 || menu > 3);

	if (menu == 3) {
		std::cout << "Exit " << std::endl;

	}
	if (menu == 2) {
	}

	if (menu == 1) {
		game(x, y, xW, yW, xB1, yB1, xB2, yB2, xP1, yP1, xP2, yP2, xEX1, yEX1, xEX2, yEX2);
	}


	return 0;

}



