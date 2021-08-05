params ["_fadeOutTime","_fadedTime","_fadeInTime","_fadeInText","_fadedText","_fadeOutText","_playerClient"];
if (!hasInterface) exitWith {};
if (player == _playerClient) then {
titleCut [_fadeOutText, "BLACK OUT", _fadeOutTime];
sleep _fadeOutTime;
titleCut [_fadedText, "BLACK FADED", _fadedTime];
sleep _fadedTime; 
titleCut [_fadeInText, "BLACK IN", _fadeInTime];
};