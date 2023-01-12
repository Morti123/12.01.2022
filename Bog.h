#pragma once
#include "aide.h"
#include <SFML/Graphics.hpp>
struct Bat {
	sf::RectangleShape shape;
	float BatSpeedX;
};
void batInit(Bat& bat)
{
	bat.shape.setSize(80.f, 20.f);
	bat.shape.setFillColor(BatColor);
	bat.shape.setPosition(BatStartPos);
	bat.BatSpeedX = 0;
	bat.Score = 0;
}
void batReboundHorizontal(Bat& bat) {
	if (bat.shape.getPosition().x <= 0) {
		bat.speedx = -bat.speedx;
		bat.rightScore++;
	}
	if (bat.shape.getPosition().x >= (WINDOW_WIDTH - 2 * BAll_RADIUS)) {
		bat.speedx = -bat.speedx;
		bat.leftScore++;
	}
}

void batReboundVertical(Bat& bat) {
	if (bat.shape.getPosition().y <= 0) {
		bat.speedy = -bat.speedy;
	}
	if (bat.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * bat_RADIUS)) {
		bat.speedy = -bat.speedy;
	}
}

void batUpdate(bat& bat) {
	bat.shape.move(bat.speedx, bat.speedy);
	batReboundHorizontal(bat);
	batReboundVertical(bat);
}

void batDraw(sf::RenderWindow& window, bat bat) {
	window.draw(bat.shape);
}
