#ifndef BGANIMATIONLAYER_H
#define BGANIMATIONLAYER_H
/*
-----------------------------------------------------------------------------
 Class: BGAnimation

 Desc: Particles that play in the background of ScreenGameplay

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Ben Nordstrom
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "Sprite.h"

const int MAX_TILES_WIDE = 11;
const int MAX_TILES_HIGH = 8;
const int MAX_SPRITES = MAX_TILES_WIDE*MAX_TILES_HIGH;


class BGAnimationLayer
{
public:
	BGAnimationLayer();
	virtual ~BGAnimationLayer() { }

	void LoadFromStaticGraphic( CString sPath );
	void LoadFromAniLayerFile( CString sPath, CString sSongBGPath );
	void LoadFromMovie( CString sMoviePath, bool bLoop, bool bRewind );
	void LoadFromVisualization( CString sMoviePath );

	virtual void Update( float fDeltaTime );
	virtual void Draw();

	virtual void SetDiffuse( RageColor c ) { for(int i=0; i<m_iNumSprites; i++) m_Sprites[i].SetDiffuse(c); }

	void GainingFocus();
	void LosingFocus();

protected:
	Sprite m_Sprites[MAX_SPRITES];
	int m_iNumSprites;

	bool m_bCycleColor;
	bool m_bCycleAlpha;
	bool m_bRewindMovie;

	enum Effect {
		EFFECT_CENTER,
		EFFECT_STRETCH_STILL,
		EFFECT_STRETCH_SCROLL_LEFT,
		EFFECT_STRETCH_SCROLL_RIGHT,
		EFFECT_STRETCH_SCROLL_UP,
		EFFECT_STRETCH_SCROLL_DOWN,
		EFFECT_STRETCH_WATER,
		EFFECT_STRETCH_BUBBLE,
		EFFECT_STRETCH_TWIST,
		EFFECT_STRETCH_SPIN,
		EFFECT_PARTICLES_SPIRAL_OUT,
		EFFECT_PARTICLES_SPIRAL_IN,
		EFFECT_PARTICLES_FLOAT_UP,
		EFFECT_PARTICLES_FLOAT_DOWN,
		EFFECT_PARTICLES_FLOAT_LEFT,
		EFFECT_PARTICLES_FLOAT_RIGHT,
		EFFECT_PARTICLES_BOUNCE,
		EFFECT_TILE_STILL,
		EFFECT_TILE_SCROLL_LEFT,
		EFFECT_TILE_SCROLL_RIGHT,
		EFFECT_TILE_SCROLL_UP,
		EFFECT_TILE_SCROLL_DOWN,
		EFFECT_TILE_FLIP_X,
		EFFECT_TILE_FLIP_Y,
		EFFECT_TILE_PULSE,
		EFFECT_STRETCH_SCROLL_H,
		NUM_EFFECTS		// leave this at the end
	};
	Effect	m_Effect;

	RageVector2 m_vHeadings[MAX_SPRITES];	// only used in EFFECT_PARTICLES_BOUNCE

	RageVector2 m_vTexCoordVelocity;
	float m_PosX;
	float m_PosY;
	float m_Zoom;
	float m_Rot;
	float m_fRotationalVelocity;
	float m_fStretchScrollH_Y;
	float m_ShowTime;
	float m_HideTime;

	float m_TweenStartTime;
	float m_TweenX;
	float m_TweenY;
	float m_TweenSpeed;

	int m_TweenState;
	int m_TweenPassedX;
	int m_TweenPassedY;
};

#endif
