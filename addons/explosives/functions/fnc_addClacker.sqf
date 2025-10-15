#include "..\script_component.hpp"
/*
 * Author: Garth 'L-H' de Wet
 * Adds an explosive as a clacker item to the passed unit if the unit has the required item.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Explosive <OBJECT>
 * 2: Magazine classname <STRING>
 * 3: Extra variables <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, _explosive, "SatchelCharge_Remote_Mag", [ConfigFile >> "ACE_Triggers" >> "Command"]] call ACE_Explosives_fnc_addClacker;
 *
 * Public: Yes
 */

params ["_unit", "_explosive", "_magazineClass"];
TRACE_3("params",_unit,_explosive,_magazineClass);

// Config is the last item in the list of passed in items.
private _config = (_this select 3) select -1;

private _requiredItems = getArray(_config >> "requires");
private _hasRequired = true;
private _detonators = [_unit] call FUNC(getDetonators);
{
    if !(_x in _detonators) exitWith{
        _hasRequired = false;
    };
} forEach _requiredItems;

if !(_hasRequired) exitWith {};
private _config = configFile >> "CfgMagazines" >> _magazineClass >> "ACE_Triggers" >> configName _config;

private _clacker = _unit getVariable [QGVAR(Clackers), []];
GVAR(PlacedCount) = GVAR(PlacedCount) + 1;

_clacker pushBack [_explosive, getNumber(_config >> "FuseTime"), format [localize LSTRING(DetonateCode),
    GVAR(PlacedCount)], _magazineClass, configName ((_this select 3) select -1)];

_unit setVariable [QGVAR(Clackers), _clacker, true];

//White-listed explosives
Aux212_DemoCharges = [
    ["Aux212_X3_Thermal_Disruptor_Ammo", "X3" , "10m"],
    ["Aux212_X10_Thermal_Disruptor_Ammo","X10" , "30m"],
    ["Aux212_7PrG_Proton_Charge_Ammo","Proton Charge", "10m"], 
    ["JLTS_explosive_emp_10_Ammo", "EMP MK2", "10m"],
    ["JLTS_explosive_emp_50_ammo", "EMP MK5", "50m"]
    ];

{
    _ExType = Typeof _explosive;
    if (toLower TypeOf _explosive isEqualTo toLower (_x select 0)) then 
    {
        //Create tag
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
        _markerID = format["_USER_DEFINED %1", random 1000000];
        _marker = createMarker [_markerID, position _explosive, 1, _unit];
        _marker setMarkerType "jmm_g_dot";
        _marker setMarkerColor "ColorCIS";
        _marker setMarkerText format["%1 %2 %3", _x select 1, _x select 2, format [localize LSTRING(DetonateCode), GVAR(PlacedCount)]];
    };
}forEach Aux212_DemoCharges;
//display clacker code message:
[format [localize LSTRING(DetonateCode), GVAR(PlacedCount)]] call EFUNC(common,displayTextStructured);

[QGVAR(clackerAdded), [_unit, _explosive, GVAR(PlacedCount)]] call CBA_fnc_localEvent;
