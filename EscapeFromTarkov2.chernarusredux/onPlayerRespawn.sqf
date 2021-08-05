_inRaid = player getVariable ["inRaid",false];
enableEnvironment [false, false];
if (_inRaid) then {
[player,["inRaid",false]] remoteExecCall ["setVariable",0];
raidPlayerCount = raidPlayerCount - 1;
publicVariable "raidPlayerCount";
};
sleep 0.2;
player setPosASL (getPosASL (player getVariable "stash") vectorAdd [0,0,0.2]);


[
		player,                                            // Object the action is attached to
		"Extract",                                        // Title of the action
		"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Idle icon shown on screen
		"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Progress icon shown on screen
		format ["_this distance2D %1 < 4 or _this distance2D %2 < 4 or _this distance2D %3 < 4 or _this distance2D %4 < 4 or _this distance2D %5 < 4 or _this distance2D %6 < 4 or _this distance2D %7 < 4 or _this distance2D %8 < 4 or _this distance2D %9 < 4", getMarkerPos 'xtm_1', getMarkerPos 'xtm_2', getMarkerPos 'xtm_3', getMarkerPos 'xtm_4', getMarkerPos 'xtm_5', getMarkerPos 'xtm_6', getMarkerPos 'xtm_7', getMarkerPos 'xtm_8', getMarkerPos 'xtm_9'],                      // Condition for the action to be shown
		format ["_caller distance2D %1 < 4 or _caller distance2D %2 < 4 or _caller distance2D %3 < 4 or _caller distance2D %4 < 4 or _caller distance2D %5 < 4 or _caller distance2D %6 < 4 or _caller distance2D %7 < 4 or _caller distance2D %8 < 4 or _caller distance2D %9 < 4", getMarkerPos 'xtm_1', getMarkerPos 'xtm_2', getMarkerPos 'xtm_3', getMarkerPos 'xtm_4', getMarkerPos 'xtm_5', getMarkerPos 'xtm_6', getMarkerPos 'xtm_7', getMarkerPos 'xtm_8', getMarkerPos 'xtm_9'],                       // Condition for the action to progress
		{},                                                    // Code executed when action starts
		{},                                                    // Code executed on every progress tick
		{
			[3,3,3,"","Extracting...","",_caller] spawn KEK_fnc_fade;
			sleep 3;
			_caller setPosASL (getPosASL (hubObj) vectorAdd [0,0,0.2]);
			[player,["inRaid",false]] remoteExecCall ["setVariable",0];
			raidPlayerCount = raidPlayerCount - 1;
			publicVariable "raidPlayerCount";
		},                                                    // Code executed on completion
		{},                                                    // Code executed on interrupted
		[],                                                    // Arguments passed to the scripts as _this select 3
		8,                                                    // Action duration [s]
		100,                                                // Priority
		false,                                                // Remove on completion
		false                                                // Show in unconscious state
		] call BIS_fnc_holdActionAdd;    // MP compatible implementation

[] remoteExec ["mp_save",2];
sleep 3;
[player] call mp_load_player;


