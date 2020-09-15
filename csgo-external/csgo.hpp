#pragma once

#include "nbqmemory.hpp"
#include "data.hpp"
#include "offsets.hpp"

namespace csgo
{
	extern nbqmemory mem;
	extern module client;

	bool init();

	namespace localplayer
	{
		DWORD get_localplayer_base();

		DWORD get_health(DWORD lp);

		DWORD get_team(DWORD lp);

		DWORD get_incross(DWORD lp);

		DWORD get_shots_fired(DWORD lp);

		DWORD get_flags(DWORD lp);

		DWORD get_scoped(DWORD lp);

		VEC3 get_origin(DWORD lp);

		VEC2 get_angles(DWORD lp);

		VEC2 get_punch(DWORD lp);
	}

	namespace entity
	{
		DWORD get_glow_object();

		DWORD get_entity_base(int i);

		DWORD get_health(DWORD ent);

		DWORD get_team(DWORD ent);

		DWORD get_flags(DWORD ent);

		DWORD get_dormant(DWORD ent);

		DWORD get_spotted(DWORD ent);

		DWORD get_glow_index(DWORD ent);

		DWORD get_bone_ptr(DWORD ent);

		VEC3 get_origin(DWORD ent);

		MAT3X4 get_bone_matrix(DWORD bone_ptr, DWORD bone);
	}
}