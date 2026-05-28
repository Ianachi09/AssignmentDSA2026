#ifndef ITEMS_H
#define ITEMS_H

#include "Battle.h"
#include "raylib.h"
#include "player.h"
#include <string>

class BattleSystem;

// Item effect types
enum ItemEffectType {
    EFFECT_NONE,
    EFFECT_HEAL,
    EFFECT_STRENGTH,
    EFFECT_DEFENSE,
    EFFECT_KEY
};

class BattleItem {
    private:
        int HPHeal = 20;
        int HPPotion = 3;

    public:
        void Healing(Player& player, BattleSystem& battle);
};

// Potion system for battle effects
class PotionEffect {
    public:
        ItemEffectType effectType;
        int duration;      // Number of turns remaining
        int magnitude;     // Bonus damage, extra HP, etc.
        
        PotionEffect() : effectType(EFFECT_NONE), duration(0), magnitude(0) {}
        PotionEffect(ItemEffectType type, int dur, int mag) 
            : effectType(type), duration(dur), magnitude(mag) {}
        
        void DecreaseDuration() {
            if (duration > 0) duration--;
        }
        
        bool IsActive() const {
            return duration > 0;
        }
};

#endif
