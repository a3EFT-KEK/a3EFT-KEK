//USE LIKE THIS:
//#include "functions\eta\tasks\damage_handling.hpp"
//bossunitsid call fnc_eta_damage;

fnc_eta_damage = {
	params["_unit"];
	//this disables vanilla damage handling and replaces it by a custom system
	_unit addEventHandler ["HandleDamage", {
		private _unit = _this select 0;
		private _hitSelection = _this select 1;

		//checks if the target was hit in a certain bodypart
		if (_hitSelection in ["legs"]) then {
			//saves hitpoints of this bodypart to a global variable
			private _temp_damage = missionNamespace getVariable["_eta_damage_handling",0];
			_temp_damage = _temp_damage + 0.25;
			missionNamespace setVariable["_eta_damage_handling",_temp_damage,true];
			//only applies body damage when the target will die through it
			if (_temp_damage >= 1) then {
				_unit setDamage _temp_damage;
			}
			//otherwise applies part damage
			else
			{
				_unit setHitPointDamage ["legs", _temp_damage, false];
			};
		}
		//seperate damage handling for all other bodyparts, makes it possible to kill even without shooting at the legs, if you have a LOT of bullets
		else
		{
			_temp_damage = missionNamespace getVariable["_eta_damage_handling_body",0];
			_temp_damage = _temp_damage + 0.0025;
			missionNamespace setVariable["_eta_damage_handling_body",_temp_damage,true];
			_unit setDamage _temp_damage;
		};
		_damage = 0;
		_damage
	}];
};
