#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct item{
    char NAME[32];
    unsigned int id, HP_extra, ATK_extra, ENERGY_extra, ARMOR_extra;
    float HP_mult, ATK_mult, ENERGY_mult, ARMOR_mult, COMBAT_SPEED_mult, COMBAT_SPEED_extra;
}t_item;



#endif // ITEM_H_INCLUDED
