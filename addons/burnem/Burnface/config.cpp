#include "..\script_component.hpp"
class CfgPatches
{
	class BurnFaces
	{
		version = "1.0";
		units[] = {};
		weapons[] = {};
		requiredVersion = "0.1";
		requiredAddons[] = {};
	};
};
class CfgHeads
{
	class Default_A3{};
	class DefaultHead_A3: Default_A3{};
	class BurnFace: DefaultHead_A3
	{
		author = "PhoenixSystems";
		model = "\A3\Characters_F\Heads\m_white_01";
		texture = QPATHTOF(BurnFace\data\Burn_co.paa);
		material = QPATHTOF(BurnFace\data\Faceh.rvmat);
		materialWounded1 = "A3\Characters_F\Heads\Data\m_african_01_injury.rvmat";
		materialWounded2 = "A3\Characters_F\Heads\Data\m_african_01_injury.rvmat";
		textureHL = "\A3\Characters_F\Heads\Data\hl_black_bald_co.paa";
		materialHL = "\A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat";
		textureHL2 = "\A3\Characters_F\Heads\Data\hl_black_bald_co.paa";
		materialHL2 = "\A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat";
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\characters_f\heads\data\m_white_01_injury.rvmat","A3\characters_f\heads\data\m_white_01_injury.rvmat","A3\characters_f\heads\data\m_white_01_injury.rvmat"};
		};
	};
};
class CfgFaces
{
	class Default;
	class Man_A3: Default
	{
		class Default;
		class BurnFace: Default
		{
			author = "PhoenixSystems";
			displayname = "Burned Face";
			head = "BurnFace";
			identityTypes[] = {};
			texture = QPATHTOF(BurnFace\data\Burn_co.paa);
			material = QPATHTOF(BurnFace\data\Faceh.rvmat);
			materialWounded1 = "A3\Characters_F\Heads\Data\m_african_01_injury.rvmat";
			materialWounded2 = "A3\Characters_F\Heads\Data\m_african_01_injury.rvmat";
			textureHL = "\A3\Characters_F\Heads\Data\hl_black_bald_co.paa";
			materialHL = "\A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat";
			textureHL2 = "\A3\Characters_F\Heads\Data\hl_black_bald_co.paa";
			materialHL2 = "\A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat";
			disabled = 0;
		};
	};
};
class cfgMods
{
	author = "WebKnight";
	timepacked = "1716887405";
};
