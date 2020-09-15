#include "csgo.hpp"

nbqmemory csgo::mem;
module csgo::client;

bool csgo::init()
{
	if (csgo::mem.attach("csgo.exe", PROCESS_ALL_ACCESS))
	{
		csgo::client = mem.get_module("client.dll");
		if (csgo::client.base) { return true; }
	}
	return false;
}

DWORD csgo::localplayer::get_localplayer_base()
{
	return mem.read_memory<DWORD>(csgo::client.base + m_dwLocalPlayer);
}

DWORD csgo::localplayer::get_health(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_iHealth);
}

DWORD csgo::localplayer::get_team(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_iTeamNum);
}

DWORD csgo::localplayer::get_incross(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_iCrossHairID);
}

DWORD csgo::localplayer::get_shots_fired(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_iShotsFired);
}

DWORD csgo::localplayer::get_flags(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_fFlags);
}

DWORD csgo::localplayer::get_scoped(DWORD lp)
{
	return mem.read_memory<DWORD>(lp + m_bIsScoped);
}

VEC3 csgo::localplayer::get_origin(DWORD lp)
{
	return mem.read_memory<VEC3>(lp + m_vecOrigin);
}

VEC2 csgo::localplayer::get_angles(DWORD lp)
{
	return mem.read_memory<VEC2>(lp + m_angRotation);
}

VEC2 csgo::localplayer::get_punch(DWORD lp)
{
	return mem.read_memory<VEC2>(lp + m_vecPunch);
}



DWORD csgo::entity::get_glow_object()
{
	return mem.read_memory<DWORD>(csgo::client.base + m_dwGlowObject);
}

DWORD csgo::entity::get_entity_base(int i)
{
	return mem.read_memory<DWORD>(csgo::client.base + m_dwEntityList + (i * 0x10));
}

DWORD csgo::entity::get_health(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_iHealth);
}

DWORD csgo::entity::get_team(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_iTeamNum);
}

DWORD csgo::entity::get_flags(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_fFlags);
}

DWORD csgo::entity::get_dormant(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_bDormant);
}

DWORD csgo::entity::get_spotted(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_bSpotted);
}

DWORD csgo::entity::get_glow_index(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_iGlowIndex);
}

DWORD csgo::entity::get_bone_ptr(DWORD ent)
{
	return mem.read_memory<DWORD>(ent + m_dwBoneMatrix);
}

VEC3 csgo::entity::get_origin(DWORD ent)
{
	return mem.read_memory<VEC3>(ent + m_vecOrigin);
}

MAT3X4 csgo::entity::get_bone_matrix(DWORD bone_ptr, DWORD bone)
{
	return mem.read_memory<MAT3X4>(bone_ptr + 0x30 * bone);
}
