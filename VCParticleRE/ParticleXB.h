#pragma once
#include "ParticleMgrXB.h"
#include "_config.h"

namespace REVCXB
{
	
class CParticle
{
	enum
	{
		RAND_TABLE_SIZE    = 20,
		SIN_COS_TABLE_SIZE = 1024
	};
	
public:
	CVector   m_vecPosition;
	CVector   m_vecVelocity;
	UInt32     m_nTimeWhenWillBeDestroyed; // Int32
	Int32     m_nTimeWhenColorWillBeChanged;
	Float     m_fZGround;
	CVector   m_vecParticleMovementOffset;
	Int16     m_nCurrentZRotation;
	UInt16    m_nZRotationTimer;
	Float     m_fCurrentZRadius;
	UInt16    m_nZRadiusTimer;
	UInt8     m_nColorIntensity;
	UInt8     m_nAlpha;
	Float     m_fSize;
	Float     m_fExpansionRate;
	
	//UInt16    m_nFadeToBlackTimer;
	//UInt16    m_nFadeAlphaTimer;
	
	
	Int16    m_nFadeToBlackTimer;
	Int16    m_nFadeAlphaTimer;
	
	
	Int16     m_nAnimationSpeedTimer;
	Int16     m_nRotationStep;
	Int16     m_nRotation;
	UInt8     m_nCurrentFrame;
	RwRGBA    m_Color;
	char _pad1[1];
	CParticle *m_pNext;
	
	CParticle()
	{
		;
	}
	
	~CParticle()
	{
		;
	}

	static Float      ms_afRandTable[RAND_TABLE_SIZE];
	static CParticle *m_pUnusedListHead;
	static Float      m_SinTable[SIN_COS_TABLE_SIZE];
	static Float      m_CosTable[SIN_COS_TABLE_SIZE];
	
	static void FixFlame5Bug(Bool enable);
	
	static void ReloadConfig();
	static void Initialise();
	static void Shutdown();

	static void AddParticlesAlongLine(tParticleType type, CVector const &vecStart, CVector const &vecEnd, CVector const &vecDir, Float fPower, CEntity *pEntity, Float fSize,                     Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan);	
	static void AddParticlesAlongLine(tParticleType type, CVector const &vecStart, CVector const &vecEnd, CVector const &vecDir, Float fPower, CEntity *pEntity, Float fSize, RwRGBA const&color, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan);

	static CParticle *AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize,                      Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan);
	static CParticle *AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize, RwRGBA const &color, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan);

	static void Update();
	static void Render();

	static void RemovePSystem(tParticleType type);
	static void RemoveParticle(CParticle *pParticle, CParticle *pPrevParticle, tParticleSystemData *pPSystemData);
	
	static inline void _Next(CParticle *&pParticle, CParticle *&pPrevParticle, tParticleSystemData *pPSystemData, Bool bRemoveParticle)
	{
		if ( bRemoveParticle )
		{
			RemoveParticle(pParticle, pPrevParticle, pPSystemData);
					
			if ( pPrevParticle )
				pParticle = pPrevParticle->m_pNext;
			else
				pParticle = pPSystemData->m_pParticles;
		}
		else
		{
			pPrevParticle = pParticle;
			pParticle = pParticle->m_pNext;
		}
	}

	static void AddJetExplosion(CVector const &vecPos, Float fPower, Float fSize);
	static void AddYardieDoorSmoke(CVector const &vecPos, CMatrix const &matMatrix);
	static void CalWindDir(CVector *vecDirIn, CVector *vecDirOut);
	
	static void HandleShipsAtHorizonStuff();
	static void HandleShootableBirdsStuff(CEntity *entity, CVector const&camPos);

};

extern Bool clearWaterDrop;
extern Int32 numWaterDropOnScreen;

};