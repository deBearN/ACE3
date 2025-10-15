#include "script_component.hpp"
/*
 * Author: Garth 'L-H' de Wet
 * Initialises the player object for the explosive system.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * None
 *
 * Public: No
 */

//Event for setting explosive placement angle/pitch:
[QGVAR(place), {
    params ["_explosive", "", "", "_unit"];

    call FUNC(setPosition);

    if (isServer) then {
        private _owner = [objNull, _unit] select (missionNamespace getVariable [QGVAR(setShotParents), false]);
        _explosive setShotParents [_owner, _unit];
    };
}] call CBA_fnc_addEventHandler;
[QGVAR(startDefuse), LINKFUNC(startDefuse)] call CBA_fnc_addEventHandler;

//When getting knocked out in medical, trigger deadman explosives:
//Event is global, only run on server (ref: ace_medical_fnc_setUnconscious)
if (isServer) then {
    [QGVAR(detonate), {
        params ["_unit", "_explosive", "_delay"];
        TRACE_3("server detonate EH",_unit,_explosive,_delay);
        private _owner = [objNull, _unit] select (missionNamespace getVariable [QGVAR(setShotParents), false]);
        _explosive setShotParents [_owner, _unit];
        [{
            params ["_explosive"];
            TRACE_1("exploding",_explosive);
            if (!isNull _explosive) then {
                [QEGVAR(common,triggerAmmo), _explosive, _explosive] call CBA_fnc_targetEvent;
            };
        }, _explosive, _delay] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;

    ["ace_unconscious", {
        params ["_unit", "_isUnconscious"];
        if (!_isUnconscious) exitWith {};
        TRACE_1("Knocked Out, Doing Deadman",_unit);
        [_unit] call FUNC(onIncapacitated);
    }] call CBA_fnc_addEventHandler;

    // Orient all Editor-placed SLAM (Bottom attack) mines facing upward
    {
        private _mine = _x;
        if (typeOf _mine == "ACE_SLAMDirectionalMine_Magnetic_Ammo") then {
            [_mine, MINE_PITCH_UP, 0] call CALLSTACK(BIS_fnc_setPitchBank);
        };
    } forEach allMines;
};

if (!hasInterface) exitWith {};
["ace_explosives_place", 
{
	params ["_explosive", "_dir", "_pitch", "_unit"];
	if (_explosive isKindOf "HX_AT_Mine_Ammo") then{
        _object = attachedTo _explosive;
        if (isNull _object) then {
            _startPosASL = getPosASL _explosive vectorAdd (vectorup _explosive vectorMultiply 0.1);
            _cameraDir =vectorUp _explosive vectorMultiply -1;
            _endPosASL = _startPosASL vectorAdd (_cameraDir vectorMultiply 2.5);
            _intersections = lineIntersectsSurfaces [_startPosASL, _endPosASL, _explosive, objNull, true, 1, "GEOM", "FIRE"];
            (_intersections select 0) params ["_touchingPoint", "_surfaceNormal", "", "_object"];
            if (_surfaceNormal vectorDotProduct  (_endPosASL vectorDiff _startPosASL) > 0) then {
                _surfaceNormal = _surfaceNormal vectorMultiply -1;
            };
            private _v1 = vectorNormalized (_surfaceNormal vectorMultiply -1);
            private _v2 = [];
            private _v3 = [];
            private _vectorDirAndUp = if (abs (_v1 select 2) < 0.94) then {
                _v3 = _v1 vectorCrossProduct [0, 0, 1];
                _v2 = _v3 vectorCrossProduct _v1;
                [_v1, _v2]
            } else {
                _v2 = vectorNormalized (_v1 vectorCrossProduct (_endPosASL vectorDiff _startPosASL));
                _v3 = _v1 vectorCrossProduct [0, 0, 1];
                [_v1, [1,0,0]];
            };
            private _posTag = (getPosASL _explosive) vectorAdd (_v1 vectorMultiply -0.01);  
            [_touchingPoint vectorAdd (_surfaceNormal vectorMultiply 0.01), _vectorDirAndUp, "z\ace\addons\tagging\UI\tags\red\circle.paa"] call ace_tagging_fnc_createTag;
        };
    };

}] call CBA_fnc_addEventHandler;

#include "initKeybinds.inc.sqf"

GVAR(PlacedCount) = 0;
GVAR(Setup) = objNull;
GVAR(pfeh_running) = false;
GVAR(CurrentSpeedDial) = 0;

["ace_interactMenuOpened", {
    //Cancel placement if interact menu opened
    if (GVAR(pfeh_running)) then {
        GVAR(placeAction) = PLACE_CANCEL;
    };

    //Show defuse actions on CfgAmmos (allMines):
    call FUNC(interactEH);

}] call CBA_fnc_addEventHandler;

["unit", {
    params ["_player"];
    [_player, QGVAR(explosiveActions)] call EFUNC(common,eraseCache);
}] call CBA_fnc_addPlayerEventHandler;

["ace_allowDefuse", {
    params["_mine", "_allow"];
    [_mine, _allow] call FUNC(allowDefuse);
}] call CBA_fnc_addEventHandler;
