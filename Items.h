#ifndef ITEMS_H
#define ITEMS_H
 
// Items.h
// Defines passive effect tracking for active potions in battle.
// BattleItem has been removed — item usage is now driven by the
// player's actual Inventory via BattleSystem's ApplyXxxPotion() methods.
// This also eliminates the circular dependency: Items.h no longer
// needs to include Battle.h.
 
enum ItemEffectType {
    EFFECT_NONE,
    EFFECT_HEAL,
    EFFECT_STRENGTH,
    EFFECT_DEFENSE,
    EFFECT_KEY
};
 
// Tracks a timed potion effect that is active during battle (e.g. strength buff).
class PotionEffect {
public:
    ItemEffectType effectType;
    int duration;   // Turns remaining
    int magnitude;  // Bonus damage, extra HP, etc.
 
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
