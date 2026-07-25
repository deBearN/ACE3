#include "..\script_component.hpp"
params ["_unit"];

private _nextOilSnd = "run_flame_1";
private _flameStates = [
    "AmovPercMevaSrasWrflDf",
    "AmovPercMevaSrasWrflDfl",
    "AmovPercMevaSrasWrflDfr",
    "AmovPercMevaSrasWpstDf",
    "AmovPercMevaSrasWpstDfl",
    "AmovPercMevaSrasWpstDfr",
    "AmovPercMevaSlowWpstDf",
    "AmovPercMevaSlowWpstDfl",
    "AmovPercMevaSlowWpstDfr",
    "AmovPercMevaSlowWrflDf",
    "AmovPercMevaSlowWrflDfl",
    "AmovPercMevaSlowWrflDfr",
    "AmovPknlMevaSrasWrflDf",
    "AmovPknlMevaSrasWrflDfl",
    "AmovPknlMevaSrasWrflDfr",
    "AmovPknlMevaSrasWpstDf",
    "AmovPknlMevaSrasWpstDfl",
    "AmovPknlMevaSrasWpstDfr",
    "AmovPercMevaSnonWnonDf",
    "AmovPercMevaSnonWnonDfl",
    "AmovPercMevaSnonWnonDfr"
];
private _randomFlameSounds = ["run_flame_6", "run_flame_1", "run_flame_2", "run_flame_5", "run_flame_4"];

while {alive _unit} do {
    private _animState = animationState _unit;

    if (
        (getText (configFile >> "CfgVehicles" >> backpack _unit >> "WBK_BurnEm_FlamethrowerBaloons") != "") &&
        ((_unit ammo primaryWeapon _unit) != 0)
    ) then {
        switch true do {
            case (_animState in _flameStates): {
                switch _nextOilSnd do {
                    case "run_flame_1": { _nextOilSnd = "run_flame_2"; };
                    case "run_flame_2": { _nextOilSnd = "run_flame_3"; };
                    case "run_flame_3": { _nextOilSnd = "run_flame_4"; };
                    case "run_flame_4": { _nextOilSnd = "run_flame_5"; };
                    case "run_flame_5": { _nextOilSnd = _randomFlameSounds call BIS_fnc_SelectRandom; };
                    case "run_flame_6": { _nextOilSnd = "run_flame_1"; };
                    default { _nextOilSnd = "run_flame_1"; };
                };

                [_unit, _nextOilSnd, 25, 3] execVM QPATHTOF(WBK_FlamethrowerSystem\createSoundGlobal.sqf);
            };
            default {
                // no flame sound for other animation states
            };
        };
    };
    sleep 0.31;
};
