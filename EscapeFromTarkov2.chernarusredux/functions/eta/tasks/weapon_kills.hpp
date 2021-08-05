//USE LIKE THIS:
//#include "functions\eta\tasks\weapon_kills.hpp"
//[UNITWHICHWILLGETKILLED,"weaponclass_name"] call fnc_eta_weapon_kills;

//Note that you can use allUnits as a the base_unit

//RETURNS THE NUMBER OF PEOPLE KILLED BY THE WEAPON AFTER IT FIRST GOT CALLED, NOTE THAT IT DOES NOT DIFFERENCIATE BETWEEN WHICH PLAYER KILLED THEM
//if you want to reset the number use:
//missionNamespace setVariable[format["eta_%1_kills","YOURWEAPON"],0];

fnc_eta_weapon_kills = {
	params["_unit","_weapon"];
	eta_weapon = _weapon;
	_unit addEventHandler ["Killed", {
		params ["_unit", "_killer", "_instigator", "_useEffects"];
		if (_killer in allPlayers and currentWeapon _killer == eta_weapon) then {
			missionNamespace setVariable[format["eta_%1_kills",eta_weapon],missionNamespace getVariable[format["eta_%1_kills",eta_weapon],0]];
		};
	}];
	missionNamespace getVariable[format["eta_%1_kills",eta_weapon],0]
};
