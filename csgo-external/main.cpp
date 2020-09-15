#include "csgo.hpp"

int main()
{
	printf("Testing csgo-external\n\n");

	csgo::init();

	DWORD lp = csgo::localplayer::get_localplayer_base();
	printf("get_localplayer_base(): %d\n", lp);
	printf("get_health(): %d\n", csgo::localplayer::get_health(lp));
	printf("get_team(): %d\n", csgo::localplayer::get_team(lp));
	printf("get_incross(): %d\n", csgo::localplayer::get_incross(lp));
	printf("get_shots_fired(): %d\n", csgo::localplayer::get_shots_fired(lp));
	printf("get_flags(): %d\n", csgo::localplayer::get_flags(lp));
	printf("get_scoped(): %d\n", csgo::localplayer::get_scoped(lp));
	VEC3 origin = csgo::localplayer::get_origin(lp);
	printf("get_origin(): %f %f %f\n", origin.x, origin.y, origin.z);
	VEC2 angles = csgo::localplayer::get_angles(lp);
	printf("get_angles(): %f %f\n", angles.x, angles.y);
	VEC2 punch = csgo::localplayer::get_punch(lp);
	printf("get_punch(): %f %f\n", punch.x, punch.y);


	getchar();
	return 0;
}