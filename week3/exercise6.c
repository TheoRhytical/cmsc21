#include <stdio.h>

struct Enemy {
    int hitpoints;
    int manapoints;
    int attackspeed;
};


int takeDamage(struct Enemy* entity, int damage);


int main() {
	struct Enemy e;
	e.hitpoints = 20;
	int alive = takeDamage(&e, 15);
	printf("%d\n", alive);
	// alive == 1; // still alive after taking damage
	// e.hitpoints == 5; // 5 hitpoints left after taking 15
}


int takeDamage(struct Enemy* entity, int damage) {
	entity->hitpoints -= damage;
	return (entity->hitpoints > 0);
}