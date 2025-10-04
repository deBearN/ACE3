class CfgPatches
{
	class WBK_Flame_AditionalAnims
	{
		units[]={};
		weapons[]={};
		requiredVersion=1.02;
		requiredAddons[]={"a3_anims_f"};
	};
};





class DefaultEventhandlers;






class CfgMovesBasic
{
	class Default;
	class StandBase;
	class HealBase: Default
	{
		disableWeapons=1;
		disableWeaponsLong=1;
		showWeaponAim=0;
		canPullTrigger=0;
		duty=0.2;
		limitGunMovement=0;
		aiming="empty";
		aimingBody="empty";
		actions="HealActionBase";
		looped=0;
	};
	class ManActions
	{
		Disable_Gesture[]=
		{
			"Disable_Gesture",
			"Gesture"
		};
		Flame_Hit_1[]=
		{
			"Flame_Hit_1",
			"Gesture"
		};
	};
};
class CfgGesturesMale
{
	class ManActions
	{
	};
	class Actions;
	class Default;
	class BlendAnims {
		am_CenterOfSkeleton[]=
		{
			"head",
			1,
			"neck1",
			1,
			"neck",
			1,
			"Spine",
			0.2,
			"Spine1",
			0.30000001,
			"Spine2",
			1,
			"Spine3",
			1,
			"pelvis",
			"MaskStart"
		};
	};
	class States
	{
		class Disable_Gesture: Default
		{
			speed=1;
			file="\A3\anims_f\Data\Anim\Sdr\mov\erc\stp\non\non\AmovPercMstpSnonWnonDnon.rtm";
			disableWeapons=0;
			interpolationRestart=2;
			enableOptics=1;
			weaponIK=1;
			looped=0;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
		};
		class Flame_Hit_1: Default
		{
			speed=-4.2;
			looped=0;
			file="z\aux212_burnem\WBK_FlameAdditionalAnims\Flame_Hit_1.rtm";
			mask="handsWeapon";
			disableWeapons=1;
			interpolationRestart=2;
			leftHandIKBeg=1;
			leftHandIKCurve[]={0,1,0.05,0,0.78,0,0.85,1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={0,1,0.2,1,0.25,0,0.87,0,0.91,1};
			rightHandIKEnd=1;
			weaponIK=1;
			canReload=0;
			headBobStrength=-1;
			headBobMode=2;
			canPullTrigger=0;
		};
	};
};



