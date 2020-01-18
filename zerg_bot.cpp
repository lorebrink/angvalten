#include "zerg_bot.h"

void ZergBot::OnStep() {

}

void ZergBot::OnUnitIdle(const sc2::Unit* unit) {
  switch (unit->unit_type.ToType()) {
  case sc2::UNIT_TYPEID::ZERG_HATCHERY: {
    Actions()->UnitCommand(unit, sc2::ABILITY_ID::TRAIN_DRONE);
    break;
  }
  default: {
    break;
  }
  }
}
