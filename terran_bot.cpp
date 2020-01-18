#include "terran_bot.h"

void TerranBot::OnStep() {
  
}

void TerranBot::OnUnitIdle(const sc2::Unit* unit) {
  switch (unit->unit_type.ToType()) {
  case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER: {
    Actions()->UnitCommand(unit, sc2::ABILITY_ID::TRAIN_SCV);
    break;
  }
  default: {
    break;
  }
  }
}