#include <sc2api/sc2_api.h>

#include "terran_bot.h"
#include "zerg_bot.h"

int main(int argc, char* argv[]) {

	sc2::Coordinator coordinator;
	coordinator.LoadSettings(argc, argv);

	TerranBot terran_bot;
  ZergBot zerg_bot;

	coordinator.SetParticipants({
		sc2::CreateParticipant(sc2::Race::Terran, &terran_bot),
    sc2::CreateParticipant(sc2::Race::Zerg, &zerg_bot),
	});

	coordinator.LaunchStarcraft();
	coordinator.StartGame(sc2::kMapBelShirVestigeLE);

	while (coordinator.Update()) {}

	return 0;
}
