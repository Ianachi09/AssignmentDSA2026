#include "Items.h"
#include "Battle.h"
#include <iostream>

void BattleItem::Healing(Player& player, BattleSystem& battle) {
    int& HP = battle.get_healing();

    if (HPPotion <= 0) {
        return;
    }

    HP += HPHeal;

    if (HP > battle.max_HP()) {
        HP = battle.max_HP();
    }

    HPPotion--;
}
