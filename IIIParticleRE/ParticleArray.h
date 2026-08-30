#pragma once
#include "_config.h"
#include "_precl.h"
#include "ParticleXbox.h"
#include "ParticlePS2.h"
#include <vector>


class CParticleArray
{
public:
	enum
	{
		DEFAULT_PARTICLE_ARRAY_SIZE = 1000
	};
private:
	static std::vector<CParticle>         ParticlesPC;
	static std::vector<REXBOX::CParticle> ParticlesXbox;
	static std::vector<REPS2::CParticle>  ParticlesPS2;

public:
	static void Initialise();
	static void ReInitArrays();
	static void InitOriginalParticleArray(CParticle *array, UInt32 size);
	static void PatchPSystem();
	static void ReSize(UInt32 size);
	
	static std::vector<CParticle>&         GetPC()   { return ParticlesPC;   } 
	static std::vector<REPS2::CParticle>&  GetPS2()  { return ParticlesPS2;  } 
	static std::vector<REXBOX::CParticle>& GetXBOX() { return ParticlesXbox; } 
};
