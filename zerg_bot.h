#pragma once

#include <sc2api/sc2_api.h>

class ZergBot : public sc2::Agent
{

  virtual void OnStep() final;

  virtual void OnUnitIdle(const sc2::Unit* unit) final;

};

