#define FILTERSCRIPT
/*
#define NO_TAGS //#pragma warning disable 213 //tag mismatch
#define MIXED_SPELLINGS //warning 234: function is deprecated (symbol "TextDrawBackgroundColor") Use `TextDrawBackgroundColour` 

#pragma warning disable 213 //tag mismatch
*/
#define NO_TAGS //#pragma warning disable 213 //tag mismatch

/*
	# TODO LIST:
	- [x] UPDATE INCLUDE TO OPEN.MP
		- [x] UPDATE CALLBACKS
	- [x] CHANGE ACTORS TO DYNAMIC ACTORS (STREAMER)
	- [ ] IMPLEMENT ROBBERY_ACTORS TO GAMEMODE ROBBERY_SYSTEM
	- [ ] 
*/

#include <open.mp>
#include <actor_robbery2>

public OnFilterScriptInit()
{
	printf(" ");
	printf("  -----------------------------------");
	printf("  |  My first open.mp filterscript! |");
	printf("  -----------------------------------");
	printf(" ");
	
		//--- ACNR Actors Compleatly by abolfazl ;)
    new gun0 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun0,0);
	printf("Actor Created: %d", gun0);
	//
	new gun1 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun1,1);	
	printf("Actor Created: %d", gun1);
	//
	new gun2 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun2,2);
	printf("Actor Created: %d", gun2);
	//
	new gun3 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun3,3);
	printf("Actor Created: %d", gun3);
	//
	new gun4 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun4,4);
	printf("Actor Created: %d", gun4);
	//
	new gun5 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun5,5);
	printf("Actor Created: %d", gun5);
	//
	new gun6 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun6,6);
	printf("Actor Created: %d", gun6);
	//
	new gun7 = Robbery_CreateDynamicActor(179,295.600982,-82.528480,1001.515625,358.474029 		,0, 0, 0);
	//SetActorVirtualWorld(gun7,7);
	printf("Actor Created: %d", gun7);
	//--
	new bar = Robbery_CreateDynamicActor(11, 496.540069,-77.690093,998.765075,1.526236     		,0, 0, 0);
	//SetActorVirtualWorld(bar,0);
	printf("Actor Created: %d", bar);
	//--
	new club = Robbery_CreateDynamicActor(172,501.734191,-20.511922,1000.679687,93.438293  		,0, 0, 0);
	//SetActorVirtualWorld(club,0);
	printf("Actor Created: %d", club);
	//--
	new gard1 = Robbery_CreateDynamicActor(163,2364.264160,2374.246826,10.820312,92.207115 		,0, 0, 0);
	//SetActorVirtualWorld(gard1,0);
	printf("Actor Created: %d", gard1);
	//
	new gard2 = Robbery_CreateDynamicActor(163,2364.286132,2381.138183,10.820312,88.530639 		,0, 0, 0);
	//SetActorVirtualWorld(gard2,0);
	printf("Actor Created: %d", gard2);
	//
	new gard3 = Robbery_CreateDynamicActor(164, 2311.246337,2322.784667,10.820312, 275.337371 		,0, 0, 0);
	////SetActorVirtualWorld(gard3,0);
	printf("Actor Created: %d", gard3);
	//--
	new casino1 = Robbery_CreateDynamicActor(171,1141.161865,-5.236854,1000.671875,91.921867 		,0, 0, 0);
	//SetActorVirtualWorld(casino1,1);
	printf("Actor Created: %d", casino1);
	//
	new casino2 = Robbery_CreateDynamicActor(171,1141.164062,-3.148595,1000.671875  ,96.923652		,0, 0, 0);
	//SetActorVirtualWorld(casino2,3);
	printf("Actor Created: %d", casino2);
	//--
	new gym = Robbery_CreateDynamicActor(80,765.653869,-58.378597,1000.656250,224.292129 			,0, 0, 0);
	//SetActorVirtualWorld(gym,0);
	printf("Actor Created: %d", gym);
	//--
	new burg1 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg1,1);
	printf("Actor Created: %d", burg1);
	//
	new burg0 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg0,0);
	printf("Actor Created: %d", burg0);
	//
	new burg2 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg2,2);
	printf("Actor Created: %d", burg2);
	//
	new burg3 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg3,3);
	printf("Actor Created: %d", burg3);
	//
	new burg4 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg4,4);
	printf("Actor Created: %d", burg4);
	//
	new burg5 = Robbery_CreateDynamicActor(205,376.464141,-65.834091,1001.507812,181.290451 		,0, 0, 0);
	//SetActorVirtualWorld(burg5,5);
	printf("Actor Created: %d", burg5);
	//--
	new pizza0 = Robbery_CreateDynamicActor(155,374.663909,-117.261978,1001.492187,181.275039  	,0, 0, 0);
	//SetActorVirtualWorld(pizza0,0);
	printf("Actor Created: %d", pizza0);
	//--
	new cluck1 = Robbery_CreateDynamicActor(167,370.973632,-4.491292,1001.858886,185.756332 		,0, 0, 0);
	//SetActorVirtualWorld(cluck1,1);
	printf("Actor Created: %d", cluck1);
	//
	new cluck0 = Robbery_CreateDynamicActor(167,370.973632,-4.491292,1001.858886,185.756332 		,0, 0, 0);
	//SetActorVirtualWorld(cluck0,0);
	printf("Actor Created: %d", cluck0);
	//
	new cluck2 = Robbery_CreateDynamicActor(167,370.973632,-4.491292,1001.858886,185.756332 		,0, 0, 0);
	//SetActorVirtualWorld(cluck2,2);
	printf("Actor Created: %d", cluck2);
	//
	new cluck3 = Robbery_CreateDynamicActor(167,370.973632,-4.491292,1001.858886,185.756332 		,0, 0, 0);
	//SetActorVirtualWorld(cluck3,3);
	printf("Actor Created: %d", cluck3);
	//--
	new casino3 = Robbery_CreateDynamicActor(171, 1141.321411,-4.089776,1000.671875 ,96.653755  	,0, 0, 0);
	//SetActorVirtualWorld(casino3,2);
	printf("Actor Created: %d", casino3);
	//--
	new store0 = Robbery_CreateDynamicActor(194, -10.466575,-179.954940,1003.546875,359.867309  	,0, 0, 0);
	//SetActorVirtualWorld(store0,0);
	printf("Actor Created: %d", store0);
	//
	new store1 = Robbery_CreateDynamicActor(194, -10.466575,-179.954940,1003.546875,359.867309  	,0, 0, 0);
	//SetActorVirtualWorld(store1,1);
	printf("Actor Created: %d", store1);
	//
	new store2 = Robbery_CreateDynamicActor(194, -10.466575,-179.954940,1003.546875,359.867309  	,0, 0, 0);
	//SetActorVirtualWorld(store2,2);
	printf("Actor Created: %d", store2);
	//
	new store3 = Robbery_CreateDynamicActor(194, -10.466575,-179.954940,1003.546875,359.867309  	,0, 0, 0);
	//SetActorVirtualWorld(store3,3);
	printf("Actor Created: %d", store3);
	//
	new store4 = Robbery_CreateDynamicActor(194, -10.466575,-179.954940,1003.546875,359.867309  	,0, 0, 0);
	//SetActorVirtualWorld(store4,4);
	printf("Actor Created: %d", store4);
	
	//-- clag buge | nabashe behtare :|
	new clag = Robbery_CreateDynamicActor(166, 2155.032470,1599.828125,1006.166015 ,271.163360   	,0, 0, 0);
	//SetActorVirtualWorld(clag,0);
	printf("Actor Created: %d", clag);
	//-- drag buge | nabashe behtare :|
	new drag = Robbery_CreateDynamicActor(189, 1953.793945,1017.987487,992.468750 ,268.587127   	,0, 0, 0);
	//SetActorVirtualWorld(drag,0);
	printf("Actor Created: %d", drag);
	
	//--
	new hall = Robbery_CreateDynamicActor(147,359.706329,173.593750,1008.389343 ,269.790008   		,0, 0, 0);
	//SetActorVirtualWorld(hall,0);
	printf("Actor Created: %d", hall);
	//--
	new cia = Robbery_CreateDynamicActor(165,246.487792,120.392517,1003.265014 ,180.720108  		,0, 0, 0);
	//SetActorVirtualWorld(cia,0);
	printf("Actor Created: %d", cia);
	//--
	new fbi = Robbery_CreateDynamicActor(71,251.259384,69.695549,1003.640625 ,98.488189   			,0, 0, 0);
	//SetActorVirtualWorld(fbi,0);
	printf("Actor Created: %d", fbi);
	//--
	new uni = Robbery_CreateDynamicActor(50,-2034.687622,-118.221527,1035.171875,291.860992  		,0, 0, 0);
	//SetActorVirtualWorld(uni,0);
	printf("Actor Created: %d", uni);
	//--- ACNR Actors Compleatly by abolfazl ;)
	

	return 1;
}
/*
public OnPlayerUpdate(playerid)
{
	new Float:pox, Float:poy, Float:poz;
	GetPlayerPos(playerid, pox, poy, poz);
	
	for(new i = 0; i < MAX_ROBBERY_ACTORS; i++)  
	{
		new sid, Float:ax, Float:ay, Float:az, Float:aa, avw, ams, amx;
		Robbery_GetActorData(i, sid, ax, ay, az, aa, avw, ams, amx);
		if(IsPlayerInRangeOfPoint(playerid, 20, ax, ay, az))
	    {
			printf("%d, %d, %f, %f, %f, %f, $d, %d, %d", i, sid, ax, ay, az, aa, avw, ams, amx); 
	        SendClientMessage(playerid, -1, "Aim to Rob!");
		}
	}
	
	return 1;
}
*/
public OnPlayerStartRobbery(playerid, DynamicActorid, bool:robbed_recently)
{
	printf("OnPlayerStartRobbery(%d, %d, bool:robbed_recently", playerid, DynamicActorid);
	return 1;
}

public OnPlayerFinishRobbery(playerid, DynamicActorid, robbedmoney, type)
{
	printf("OnPlayerFinishRobbery(%d, %d, %d, type", playerid, DynamicActorid, robbedmoney);
	return 1;
}

public OnPlayerRequestRobbery(playerid, DynamicActorid)
{
	printf("OnPlayerRequestRobbery(%d, %d", playerid, DynamicActorid);
	return 1;
}

