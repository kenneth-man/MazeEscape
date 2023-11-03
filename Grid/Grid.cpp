#include <iostream>
#include "./Grid.h"

using namespace std;

void Grid::render(Player player) {
	for (int col = 0; col < Grid::ySize; col++) {
		for (int row = 0; row < Grid::xSize; row ++) {
			if (player.xPos == row && player.yPos == col) {
				cout << player.sprite;
			} else {
				cout << Grid::sprite;
			}
		}
		cout << "\n";
	}
	cout << "◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇" << "\n";
}