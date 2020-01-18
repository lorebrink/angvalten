#include <sc2api/sc2_api.h>

#include <iostream>

using namespace sc2;

class Bot : public Agent {
public:

	virtual void OnStep() final {
		std::cout << Observation()->GetGameLoop() << std::endl;
	}

	virtual void OnUnitIdle(const Unit* unit) final {
		switch (unit->unit_type.ToType()) {
		case UNIT_TYPEID::TERRAN_COMMANDCENTER: {
			Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_SCV);
			break;
		}
		default: {
			break;
		}
		}
	}
};

int main(int argc, char* argv[]) {

	Coordinator coordinator;
	coordinator.LoadSettings(argc, argv);

	Bot bot;
	coordinator.SetParticipants({
		CreateParticipant(Race::Zerg, &bot),
		CreateComputer(Race::Zerg)
		});

	coordinator.LaunchStarcraft();
	coordinator.StartGame(sc2::kMapBelShirVestigeLE);

	while (coordinator.Update()) {}

	return 0;
}
