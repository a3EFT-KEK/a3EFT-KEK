params ["_player"];

createDialog "traders";
_menu = findDisplay 69420;
_trader_1 = _menu displayCtrl 1;
_trader_2 = _menu displayCtrl 2;
_trader_3 = _menu displayCtrl 3;
_trader_4 = _menu displayCtrl 4;
_trader_5 = _menu displayCtrl 5;
_trader_6 = _menu displayCtrl 6;

_trader_1 ctrlSetText "pictures\traders\traderPavlov.paa";
_trader_2 ctrlSetText "pictures\traders\traderSurgeon.paa";
_trader_3 ctrlSetText "pictures\traders\traderMechanic.paa";
_trader_4 ctrlSetText "pictures\traders\traderAdams.paa";
_trader_5 ctrlSetText "pictures\traders\traderBoris.paa";
_trader_6 ctrlSetText "pictures\traders\traderRagman.paa";

_button_1 = _menu displayCtrl 101;
_button_2 = _menu displayCtrl 102;
_button_3 = _menu displayCtrl 103;
_button_4 = _menu displayCtrl 104;
_button_5 = _menu displayCtrl 105;
_button_6 = _menu displayCtrl 106;

_button_1 ctrlAddEventHandler ["MouseButtonDown",
{
	["Pavlov"] spawn KEK_fnc_trader;
}];
_button_2 ctrlAddEventHandler ["MouseButtonDown",
{
	["Surgeon"] spawn KEK_fnc_trader;
}];
_button_3 ctrlAddEventHandler ["MouseButtonDown",
{
	["Dimitri"] spawn KEK_fnc_trader;
}];
_button_4 ctrlAddEventHandler ["MouseButtonDown",
{
	["Adams"] spawn KEK_fnc_trader;
}];
_button_5 ctrlAddEventHandler ["MouseButtonDown",
{
	["Boris"] spawn KEK_fnc_trader;
}];
_button_6 ctrlAddEventHandler ["MouseButtonDown",
{
	["Ragman"]spawn KEK_fnc_trader;
}];