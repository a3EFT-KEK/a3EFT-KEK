
class trader
{
	idd = 69421;
	movingEnable = false;
	
	class ControlsBackground
	{
		
	};
	class Controls
	{
		class Background
		{
			type = 0;
			idc = 1;
			x = safeZoneX + safeZoneW * 0.04375;
			y = safeZoneY + safeZoneH * 0.07777778;
			w = safeZoneW * 0.9375;
			h = safeZoneH * 0.89222223;
			style = 0;
			text = "";
			colorBackground[] = {0.102,0.102,0.102,1};
			colorText[] = {0.7373,0.2275,0.1333,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class Frame
		{
			type = 0;
			idc = 2;
			x = safeZoneX + safeZoneW * 0.054375;
			y = safeZoneY + safeZoneH * 0.09111112;
			w = safeZoneW * 0.923125;
			h = safeZoneH * 0.85444445;
			style = 0+64;
			text = "Chernorussian Free Market";
			colorBackground[] = {0.102,0.102,0.102,0};
			colorText[] = {0.902,0.902,0.702,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class Trader
		{
			type = 0;
			idc = 3;
			x = safeZoneX + safeZoneW * 0.08375;
			y = safeZoneY + safeZoneH * 0.12666667;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {0.9882,0.2078,0.3098,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class Stash_Trader
		{
			type = 5;
			idc = 100;
			x = safeZoneX + safeZoneW * 0.0775;
			y = safeZoneY + safeZoneH * 0.38666667;
			w = safeZoneW * 0.308125;
			h = safeZoneH * 0.53666667;
			style = 16;
			colorBackground[] = {0.2,0.2,0.2,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {0.0369,0.2824,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			maxHistoryDelay = 0;
			rowHeight = 0;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class Stash_Player
		{
			type = 5;
			idc = 101;
			x = safeZoneX + safeZoneW * 0.6525;
			y = safeZoneY + safeZoneH * 0.38666667;
			w = safeZoneW * 0.308125;
			h = safeZoneH * 0.53666667;
			style = 16;
			colorBackground[] = {0.2,0.2,0.2,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {0.0369,0.2824,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			maxHistoryDelay = 0;
			rowHeight = 0;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class Name_Trader
		{
			type = 0;
			idc = 4;
			x = safeZoneX + safeZoneW * 0.231875;
			y = safeZoneY + safeZoneH * 0.12555556;
			w = safeZoneW * 0.155;
			h = safeZoneH * 0.04111112;
			style = 0+2;
			text = "Trader Name";
			colorBackground[] = {0.9255,0.8314,0.3882,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			
		};
		class Name_Player
		{
			type = 0;
			idc = 5;
			x = safeZoneX + safeZoneW * 0.78875;
			y = safeZoneY + safeZoneH * 0.12555556;
			w = safeZoneW * 0.155;
			h = safeZoneH * 0.04111112;
			style = 0+2;
			text = "Player Name";
			colorBackground[] = {0.9255,0.8314,0.3882,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			
		};
		class funds
		{
			type = 0;
			idc = 6;
			x = safeZoneX + safeZoneW * 0.6625;
			y = safeZoneY + safeZoneH * 0.30444445;
			w = safeZoneW * 0.28;
			h = safeZoneH * 0.04111112;
			style = 0;
			text = "Funds:";
			colorBackground[] = {0.9255,0.8314,0.3882,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			
		};
		class Buying
		{
			type = 0;
			idc = 2;
			x = safeZoneX + safeZoneW * 0.405;
			y = safeZoneY + safeZoneH * 0.42111112;
			w = safeZoneW * 0.2325;
			h = safeZoneH * 0.21888889;
			style = 0+64;
			text = "Buying";
			colorBackground[] = {0.102,0.102,0.102,0};
			colorText[] = {0.902,0.902,0.702,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class buy
		{
			type = 1;
			idc = 102;
			x = safeZoneX + safeZoneW * 0.461875;
			y = safeZoneY + safeZoneH * 0.44555556;
			w = safeZoneW * 0.123125;
			h = safeZoneH * 0.03666667;
			style = 0+2;
			text = "Buy";
			borderSize = 0;
			colorBackground[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {0.902,0.902,0.6,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0.902,0.902,0.6,1};
			colorDisabled[] = {0.2,0.2,0.2,0};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class buy_more
		{
			type = 1;
			idc = 104;
			x = safeZoneX + safeZoneW * 0.595625;
			y = safeZoneY + safeZoneH * 0.51444445;
			w = safeZoneW * 0.03;
			h = safeZoneH * 0.03666667;
			style = 0+2;
			text = ">";
			borderSize = 0;
			colorBackground[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {0.902,0.902,0.6,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0.902,0.902,0.6,1};
			colorDisabled[] = {0.2,0.2,0.2,0};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class buy_less
		{
			type = 1;
			idc = 103;
			x = safeZoneX + safeZoneW * 0.420625;
			y = safeZoneY + safeZoneH * 0.51444445;
			w = safeZoneW * 0.03;
			h = safeZoneH * 0.03666667;
			style = 0+2;
			text = "<";
			borderSize = 0;
			colorBackground[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {0.902,0.902,0.6,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0.902,0.902,0.6,1};
			colorDisabled[] = {0.2,0.2,0.2,0};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class amount
		{
			type = 0;
			idc = 105;
			x = safeZoneX + safeZoneW * 0.471375;
			y = safeZoneY + safeZoneH * 0.51;
			w = safeZoneW * 0.1075;
			h = safeZoneH * 0.04111112;
			style = 0;
			text = "Amount: 1";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.5);
			
		};
		class Selling
		{
			type = 0;
			idc = 2;
			x = safeZoneX + safeZoneW * 0.405;
			y = safeZoneY + safeZoneH * 0.69;
			w = safeZoneW * 0.2325;
			h = safeZoneH * 0.19444445;
			style = 0+64;
			text = "Selling";
			colorBackground[] = {0.102,0.102,0.102,0};
			colorText[] = {0.902,0.902,0.702,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class sell
		{
			type = 1;
			idc = 106;
			x = safeZoneX + safeZoneW * 0.471875;
			y = safeZoneY + safeZoneH * 0.80333334;
			w = safeZoneW * 0.1025;
			h = safeZoneH * 0.03666667;
			style = 0+2;
			text = "Sell";
			borderSize = 0;
			colorBackground[] = {0.6,0.6,0.6,1};
			colorBackgroundActive[] = {0.902,0.902,0.6,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0.902,0.902,0.6,1};
			colorDisabled[] = {0.2,0.2,0.2,0};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0.902,0.902,0.6,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class buy_price
		{
			type = 0;
			idc = 201;
			x = safeZoneX + safeZoneW * 0.429375;
			y = safeZoneY + safeZoneH * 0.58333334;
			w = safeZoneW * 0.1825;
			h = safeZoneH * 0.04111112;
			style = 0;
			text = "Total Price: ";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.5);
			
		};
		class buy_price_copy1
		{
			type = 0;
			idc = 202;
			x = safeZoneX + safeZoneW * 0.429375;
			y = safeZoneY + safeZoneH * 0.73;
			w = safeZoneW * 0.1825;
			h = safeZoneH * 0.04111112;
			style = 0;
			text = "Sell for:  ";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.5);
			
		};
		
	};
	
};
