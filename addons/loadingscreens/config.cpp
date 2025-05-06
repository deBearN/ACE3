class CfgPatches
{
	class Aux212_LoadingScreens
	{
		author="Regacy";
		requiredAddons[]=
		{"A3_Data_F_Enoch_Loadorder"};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
	};
};

class RscPicture;
class RscVideo;
class RscStandardDisplay;

class RscStructuredText;
class RscActiveText;
class RscActivePicture: RscActiveText {};
class TitleIconSingleplayer;
class TitleSingleplayer;
class RscText;
class RscButton;
class RscTitles
{
	class SplashNoise
	{
		class BackgroundNoise: RscPicture
		{
			text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Start_Up.jpg";
		};
	};
	class SplashBohemia
	{
		idd=-1;
		movingEnable=0;
		duration=3;
		fadein=0;
		fadeout=0;
		name="$STR_A3_SplashBohemia_0";
		controls[]=
		{
			"Picture",
			"TextPresents"
		};
		class Picture: RscPicture
		{
			idc=1200;
			text=""; 
			x="SafeZoneX + SafeZoneW / 2 - (25 * 		(0.025 * SafezoneH)) / 2";
			y="SafeZoneY +	SafeZoneH / 2 - (35 * 		(0.025 * SafezoneH)) / 2";
			w="30 * 		(0.025 * SafezoneH)";
			h="35 * 		(0.025 * SafezoneH)";
		};
		class TextPresents: RscText
		{
			text="";
		};
	};
	class SplashArma3
	{
		idd=-1;
		movingEnable=0;
		duration=3;
		fadein=0;
		fadeout=0;
		name="$STR_A3_SplashArma3_0";
		controls[]=
		{
			"Picture"
		};
		class Picture: RscPicture
		{
			idc=1200;
			text="\z\ace\addons\loadingscreens\Images\logos\ghost_company_ca.paa";
			x="SafeZoneX + SafeZoneW / 2 - (30 * 		(0.025 * SafezoneH)) / 2";
			y="SafeZoneY +	SafeZoneH / 2 - (35 * 		(0.025 * SafezoneH)) / 2";
			w="30 * 		(0.025 * SafezoneH)";
			h="35 * 		(0.025 * SafezoneH)";
		};
	};
	class SplashCopyright
	{
		idd=-1;
		movingEnable=0;
		duration=3;
		fadein=0;
		fadeout=0;
		name="$STR_A3_SplashCopyright_0";
		controls[]=
		{
			"PictureA3Logo",
			"PictureBIlogo",
			"PicturePhysXLogo",
			"LegalText"
		};
		class PictureA3Logo: RscPicture
		{
			idc=1200;
			text="\z\ace\addons\loadingscreens\Images\logos\ghost_company_shields_ca";
			x="SafeZoneX + SafeZoneW / 1.894 - (25 * 		(0.025 * SafezoneH)) / 2";
			y="SafeZoneY +	SafeZoneH / 2 - (30 * 		(0.025 * SafezoneH)) / 2";
			w="22 * 		(0.025 * SafezoneH)";
			h="30 * 		(0.025 * SafezoneH)";
		};
		class PictureBIlogo: RscPicture
		{
			text="";
		};
		class PicturePhysXLogo: RscPicture
		{
			text="";
		};
		class LegalText: RscStructuredText
		{
			text="";
		};
	};
};
class RscDisplayMain: RscStandardDisplay
{
	class Controls
	{
		delete Spotlight;
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete SpotlightNext;
		delete SpotlightPrev;
		class Logo: RscActivePicture
		{
			text="\z\ace\addons\loadingscreens\Images\logos\ghost_company_title_ca.paa";
			tooltip="212th Attack Battalion Members Wiki";
			x="0.495 - 	5 * 	(pixelW * pixelGrid * 2)";
			y="safezoneY + (1.5 - 0.5 * 	5) * 	(pixelH * pixelGrid * 2)"; // 1.5
			w="2.1 * 	5 * 	(pixelW * pixelGrid * 2)";
			h="1.5 * 	5 * 	(pixelH * pixelGrid * 2)";
			onButtonClick="";
			url="https://sites.google.com/view/memberswiki";
		};
		class LogoDiscord: RscActivePicture
		{
			text="\z\ace\addons\loadingscreens\Images\logos\212thDiscord.paa";
			tooltip="212th Attack Battalion Discord";
			x="-.58 - 	5 * 	(pixelW * pixelGrid * 2)";
			y="safezoneY + (50.5 - 0.5 * 	5) * 	(pixelH * pixelGrid * 2)";
			w=".75 * 	5 * 	(pixelW * pixelGrid * 2)";
			h=".75 * 	5 * 	(pixelH * pixelGrid * 2)";
			onButtonClick="";
			url="https://discord.gg/MFXm3Sb";
		};
		class ConnectOperation: RscButton
		{
			idc=-1;
			text="Join Operations Server";
			tooltip="Server for all Skirmishes and Main Operations";
			style=2;
			onbuttonclick="connectToServer ['15.235.13.223', 2302, '212']";
			colorBackground[]={0,0,0,0.7};
			colorBackgroundActive[]={1,0,0,0,2};
			borderSize=0.055;
			colorBorder[]={0,0,0,0};
			x="safeZoneX + safeZoneW - 2.4125";
			y="safeZoneY + 0.075 * safeZoneH";
            w = "0.125 * safezoneW";
            h = "0.03 * safezoneH";
		};
		class ConnectTraining1: RscButton
		{
			idc=-1;
			text="Join Training Server 1";
			tooltip="Server for all 'CR to CT' and 'Standard Qualifications' trainings";
			style=2;
			onbuttonclick="connectToServer ['51.161.118.10', 2302, '212']";
			colorBackground[]={0,0,0,0.7};
			colorBackgroundActive[]={1,0,0,0,2};
			borderSize=0.055;
			colorBorder[]={0,0,0,0};
			x="safeZoneX + safeZoneW - 2.4125";
			y="safeZoneY + 0.115 * safeZoneH";
            w = "0.125 * safezoneW";
            h = "0.03 * safezoneH";
		};
		class ConnectTraining2: RscButton
		{
			idc=-1;
			text="Join Training Server 2";
			tooltip="Server for all 'Advanced Qualification' trainings";
			style=2;
			onbuttonclick="connectToServer ['51.161.118.10', 2502, '212']";
			colorBackground[]={0,0,0,0.7};
			colorBackgroundActive[]={1,0,0,0,2};
			borderSize=0.055;
			colorBorder[]={0,0,0,0};
			x="safeZoneX + safeZoneW - 2.4125";
			y="safeZoneY + 0.155 * safeZoneH";
            w = "0.125 * safezoneW";
            h = "0.03 * safezoneH";
		};
		class ConnectFTX: RscButton
		{
			idc=-1;
			text="Join FTX Server";
			tooltip="Server for all field training exercises";
			style=2;
			onbuttonclick="connectToServer ['15.235.13.223', 2602, '212']";
			colorBackground[]={0,0,0,0.7};
			colorBackgroundActive[]={1,0,0,0,2};
			borderSize=0.055;
			colorBorder[]={0,0,0,0};
			x="safeZoneX + safeZoneW - 2.4125";
			y="safeZoneY + 0.195 * safeZoneH";
            w = "0.125 * safezoneW";
            h = "0.03 * safezoneH";
		};
		class ConnectFunOp: RscButton
		{
			idc=-1;
			text="Join Fun Operation Server";
			tooltip="Server for trying something other than Starsim";
			style=2;
			onbuttonclick="connectToServer ['15.235.13.223', 2702, '212']";
			colorBackground[]={0,0,0,0.7};
			colorBackgroundActive[]={1,0,0,0,2};
			borderSize=0.055;
			colorBorder[]={0,0,0,0};
			x="safeZoneX + safeZoneW - 2.4125";
			y="safeZoneY + 0.235 * safeZoneH";
            w = "0.125 * safezoneW";
            h = "0.03 * safezoneH";
		};
		class TitleOptions1: TitleSingleplayer
		{
			idc=1014;
			text="$STR_A3_RscDisplayMain_TitleOptions_text";
			x="2 + (	5 + 	10) * 	(pixelW * pixelGrid * 2)";
		};
		class TitleIconOptions1: TitleIconSingleplayer
		{
			idc=1114;
			text="\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\menu_options_ca.paa";
			tooltip="$STR_A3_RscDisplayMain_TitleOptions_text";
			x="0.5 + (	5 + 	4) * 	(pixelW * pixelGrid * 2)";
		};
	};
	enableDisplay=0;
	class RscActiveText;
	class RscActivePicture: RscActiveText
	{
		style=48;
		color[]={1,1,1,0.5};
		colorActive[]={1,1,1,1};
	};
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Main_Menu.jpg";
		};
	};
	
};
class RscDisplayLoading
{
	class Variants
	{
		class LoadingOne
		{
			idd=250;
			class controls
			{
				class LoadingPic: RscPicture
				{
					idc=1;
					x="SafeZoneX";
					y="SafeZoneY";
					h="SafeZoneH";
					w="SafeZoneW";
					text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Leaving_Server_Browser.jpg";
				};
			};
		};
		class LoadingTwo : LoadingOne {
			class controls: controls
			{
				class LoadingPic1: LoadingPic
				{
					text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Leaving_Server_Browser_02.jpg";
				};
			};
		};
		class LoadingThree : LoadingOne {
			class controls: controls
			{
				class LoadingPic2: LoadingPic
				{
					text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Leaving_Server_Browser_03.jpg";
				};
			};
		};
	};
};
class RscTitle;
class RscHTML;
class RscProgress;
class RscPictureKeepAspect;

class RscDisplayLoadMission: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPictureKeepAspect
		{
			idd = 122;
			x = "SafeZoneX";
			y = "SafeZoneY";
			h = "SafeZoneH";
			w = "SafeZoneW";
			text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Loading_Into_Mission.jpg";
		};
	};
};

class RscDisplayClient: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			idc=1;
			x="SafeZoneX";
			y="SafeZoneY";
			h="SafeZoneH";
			w="SafeZoneW";
			text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Loading_Into_Server.jpg";
		};
	};
};

class RscDisplayStart: RscStandardDisplay
{
	class controls
	{
		class LoadingPic: RscPictureKeepAspect
		{
			idd = 102;
			x = "SafeZoneX";
			y = "SafeZoneY";
			h = "SafeZoneH";
			w = "SafeZoneW";
			text="\z\ace\addons\loadingscreens\Images\Backgrounds\Picture_Leaving_Server_Browser.jpg";
		};
	};
};