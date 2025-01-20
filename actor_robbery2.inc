/*
	[DECLARATIONS]
		FOR CHANGES SEARCH // UPDATE
*/
/* // UPDATE
#if !defined _samp_included
	#error Please include a_samp before actor_robbery.
#endif
*/
 // UPDATE
#include <open.mp> 
#include <streamer> 
/* // UPDATE
#if !defined KEY_AIM
	#define KEY_AIM  128
#endif
*/
//#define KEY_AIM KEY_HANDBRAKE // UPDATE

#if !defined PreloadAnimLib
	#define PreloadAnimLib(%1,%2) ApplyAnimation(%1,%2,"null",0.0,false,false,false,false,false) // UPDATE
#endif

#define MAX_ROBBERY_DynamicActorS		(50)

#define TYPE_SUCCESS        (0)
#define TYPE_FAILED         (1)
#define TYPE_UNFINISHED     (2)

#define MIN_MONEY_ROB       500
#define MAX_MONEY_ROB       10000
#define ROBBERY_WAIT_TIME   (5)



enum E_DynamicActor_ROBBERY_DATA
{
	DynamicActor_skin,
	Float:DynamicActor_x,
	Float:DynamicActor_y,
	Float:DynamicActor_z,
	Float:DynamicActor_ang,
	DynamicActor_vw,
	money_min,
	money_max,

	bool:DynamicActor_created,
	DynamicActor_robbedRecently
}
static
	robbery_data[MAX_ROBBERY_DynamicActorS][E_DynamicActor_ROBBERY_DATA],
	i_DynamicActor = 0;

forward RunDynamicActorAnimationSequence(playerid, DynamicActorid, animation_pattern);
forward OnPlayerStartRobbery(playerid, DynamicActorid, bool:robbed_recently);
forward OnPlayerFinishRobbery(playerid, DynamicActorid, robbedmoney, type);
forward OnPlayerRequestRobbery(playerid, DynamicActorid);


/*
	Function:
		Robbery_CreateDynamicActor

	Info:
		Creates the robbery DynamicActor according to the position set.

	Param:
	* skinid -> Skin ID of the robbery DynamicActor
	* Float:x -> Coordinate X of the robbery DynamicActor
	* Float:y -> Coordinate X of the robbery DynamicActor
	* Float:z -> Coordinate X of the robbery DynamicActor
	* Float:ang -> Facing angle of the robbery DynamicActor
	* DynamicActor_vwid -> virtualid of the robbery DynamicActor
	* r_moneymin -> Minimum money to be robbed from the robbery DynamicActor
	* r_moneymax -> Maximum money to be robbed from the robbery DynamicActor

*/



#pragma deprecated GetDynamicActorRobberyData
stock GetDynamicActorRobberyData(DynamicActorid, &skinid, &Float:x, &Float:y, &Float:z, &Float:ang, &DynamicActor_vwid, &r_moneymin, &r_moneymax) {
	#pragma unused DynamicActorid, skinid, x, y, z, ang, DynamicActor_vwid, r_moneymin, r_moneymax
}

#pragma deprecated Please use new function name Robbery_CreateDynamicActor.
stock CreateDynamicActorRobbery(skinid, Float:x, Float:y, Float:z, Float:ang, DynamicActor_vwid = 0, r_moneymin = MIN_MONEY_ROB, r_moneymax = MAX_MONEY_ROB) {
	#pragma unused skinid, x, y, z, ang, DynamicActor_vwid, r_moneymin, r_moneymax
	return -1;
}

stock Robbery_CreateDynamicActor(skinid, Float:x, Float:y, Float:z, Float:ang, DynamicActor_vwid = 0, r_moneymin = MIN_MONEY_ROB, r_moneymax = MAX_MONEY_ROB) {
	new DynamicActorid = GetDynamicActorFreeID();

	if(DynamicActorid == -1) {
		print("ERROR: Robbery_CreateDynamicActor - MAX_ROBBERY_DynamicActor reached, increase the limit size.");
		return -1;
	}

	CreateDynamicActor(skinid, x, y, z, ang);
	SetDynamicActorVirtualWorld(DynamicActorid, DynamicActor_vwid);

	robbery_data[DynamicActorid][DynamicActor_created] = true;
	robbery_data[DynamicActorid][DynamicActor_skin] = skinid;
	robbery_data[DynamicActorid][DynamicActor_x] = x;
	robbery_data[DynamicActorid][DynamicActor_y] = y;
	robbery_data[DynamicActorid][DynamicActor_z] = z;
	robbery_data[DynamicActorid][DynamicActor_ang] = ang;
	robbery_data[DynamicActorid][DynamicActor_vw] = DynamicActor_vwid;
	robbery_data[DynamicActorid][money_min] = r_moneymin;
	robbery_data[DynamicActorid][money_max] = r_moneymax;

	return (i_DynamicActor ++);
}

/*
	Function:
		Robbery_GetDynamicActorData

	Info:
		Retrieves the DynamicActor data

	Param:
		* DynamicActorid -> ID of robbery DynamicActor you want to retrieve data from.
		* &skinid -> Skin ID of the robbery DynamicActor
		* &Float:x -> Coordinate X of the robbery DynamicActor
		* &Float:y -> Coordinate X of the robbery DynamicActor
		* &Float:z -> Coordinate X of the robbery DynamicActor
		* &Float:ang -> Facing angle of the robbery DynamicActor
		* &DynamicActor_vwid -> virtualid of the robbery DynamicActor
		* &r_moneymin -> Minimum money to be robbed from the robbery DynamicActor
		* &r_moneymax -> Maximum money to be robbed from the robbery DynamicActor
*/

stock Robbery_GetDynamicActorData(DynamicActorid, &skinid, &Float:x, &Float:y, &Float:z, &Float:ang, &DynamicActor_vwid, &r_moneymin, &r_moneymax) {
	if(DynamicActorid == INVALID_DynamicActor_ID) {
		print("ERROR: GetDynamicActorRobberyData - Invalid DynamicActorid input.");
		return 1;
	}

	skinid = robbery_data[DynamicActorid][DynamicActor_skin];
	x = robbery_data[DynamicActorid][DynamicActor_x];
	y = robbery_data[DynamicActorid][DynamicActor_y];
	z = robbery_data[DynamicActorid][DynamicActor_z] ;
	ang = robbery_data[DynamicActorid][DynamicActor_ang] ;
	DynamicActor_vwid = robbery_data[DynamicActorid][DynamicActor_vw];
	r_moneymin = robbery_data[DynamicActorid][money_min];
	r_moneymax = robbery_data[DynamicActorid][money_max];
	return 1;
}

/*
Function:
	GetDynamicActorFreeID

Info:
	Retrieves the unused ID of an DynamicActor.

Param:
	None

*/

static stock GetDynamicActorFreeID()
{
	for(new i = 0; i < MAX_ROBBERY_DynamicActorS; i++)  {
		if(!robbery_data[i][DynamicActor_created]) {
			return i;
		}
	}
	return -1;
}

/*
	Robbery IMPL
*/

public RunDynamicActorAnimationSequence(playerid, DynamicActorid, animation_pattern) {
	switch(animation_pattern) {
		case 0: {
			ClearDynamicActorAnimations(DynamicActorid);
			ApplyDynamicActorAnimation(DynamicActorid, "SHOP", "SHP_Rob_HandsUp", 4.1, 0, 1, 1, 1, 0);

			SetTimerEx("RunDynamicActorAnimationSequence", 1000 * ROBBERY_WAIT_TIME, false, "iii", playerid, DynamicActorid, 1);

			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			for(new i = 0, j = MAX_PLAYERS; i <= j; i++) {
				if(!IsPlayerConnected(i)) {
					continue;
				}
				PlayerPlaySound(i, 3401, x, y, z);
			}
		}
		case 1: {
			if(!IsPlayerInRangeOfPoint(playerid, 10.0, robbery_data[DynamicActorid][DynamicActor_x], robbery_data[DynamicActorid][DynamicActor_y], robbery_data[DynamicActorid][DynamicActor_z])) {
				CallLocalFunction("OnPlayerFinishRobbery", "iiii", playerid, DynamicActorid, 0, TYPE_UNFINISHED);
			}
			else {
				ClearDynamicActorAnimations(DynamicActorid);
				ApplyDynamicActorAnimation(DynamicActorid, "SHOP", "SHP_Rob_GiveCash", 4.1, 0, 1, 1, 1, 0);

				SetTimerEx("RunDynamicActorAnimationSequence", 1000 * ROBBERY_WAIT_TIME, false, "iii", playerid, DynamicActorid, 2);
			}
		}
		case 2: {
			ClearDynamicActorAnimations(DynamicActorid);
			ApplyDynamicActorAnimation(DynamicActorid, "PED", "DUCK_cower", 4.1, 1, 1, 1, 1, 1);

			SetTimerEx("RunDynamicActorAnimationSequence", 1000 * 60 * ROBBERY_WAIT_TIME, false, "iii", playerid, DynamicActorid, 3);

			new robberyChance = random(100);
			if(robberyChance > 40) {
				CallLocalFunction("OnPlayerFinishRobbery", "iiii", playerid, DynamicActorid, (random(robbery_data[DynamicActorid][money_max] - robbery_data[DynamicActorid][money_min]) + robbery_data[DynamicActorid][money_min]), TYPE_SUCCESS);
			}
			else {
				CallLocalFunction("OnPlayerFinishRobbery", "iiii", playerid, DynamicActorid, 0, TYPE_FAILED);
			}
		}
		case 3: {
			ClearDynamicActorAnimations(DynamicActorid);
			PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
		}
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	EnablePlayerCameraTarget(playerid, true);

	PreloadAnimLib(playerid, "PED");
	PreloadAnimLib(playerid, "SHOP");

	#if defined DynamicActorrob_OnPlayerConnect
		return DynamicActorrob_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys) // UPDATE
{
	if((newkeys & KEY_AIM) == KEY_AIM && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		switch(GetPlayerWeapon(playerid))
		{
			case 22 .. 33:
			{
				new DynamicActorid = GetPlayerCameraTargetDynActor(playerid);

				if(DynamicActorid == INVALID_ACTOR_ID) {
					return 1;
				}

				if(!robbery_data[DynamicActorid][DynamicActor_created]) {
					// this fixes the issue with normal create DynamicActors.
					// there was a bug that you aim at an DynamicActor and rob it even though it wasn't created by DynamicActor_robbery.
					return 1;
				}

				if(!OnPlayerRequestRobbery(playerid, DynamicActorid))
				{
					return 1;
				}

				if(gettime() - robbery_data[DynamicActorid][DynamicActor_robbedRecently] < 60 * ROBBERY_WAIT_TIME) {
					return CallLocalFunction("OnPlayerStartRobbery", "iii", playerid, DynamicActorid, true);
				}

				robbery_data[DynamicActorid][DynamicActor_robbedRecently] = gettime();
				RunDynamicActorAnimationSequence(playerid, DynamicActorid, 0);
				CallLocalFunction("OnPlayerStartRobbery", "iii", playerid, DynamicActorid, false);
			}
		}
	}
   	#if defined DynamicActorrob_OnPlayerKeyStateChange
		return DynamicActorrob_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
   		return 1;
	#endif
}

/* OnPlayerRequestRobbery
	Usage: return 0 to disallow the robbery.
	See test.pwn for example.
*/

public OnPlayerRequestRobbery(playerid, DynamicActorid)
{
	#if defined DynamicActorrob_OnPlayerRequestRobbery
		return DynamicActorrob_OnPlayerRequestRobbery(playerid, DynamicActorid);
	#else
		return 1; // Default version always wants to returns >1 to allow robbery
	#endif
}

//OnPlayerKeyStateChange hook directives

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange DynamicActorrob_OnPlayerKeyStateChange

#if defined DynamicActorrob_OnPlayerKeyStateChange
    forward DynamicActorrob_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

//OnPlayerConnect directives

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect DynamicActorrob_OnPlayerConnect
#if defined DynamicActorrob_OnPlayerConnect
    forward DynamicActorrob_OnPlayerConnect(playerid);
#endif

//OnPlayerRequestRobbery directives

#if defined _ALS_OnPlayerRequestRobbery
    #undef OnPlayerRequestRobbery
#else
    #define _ALS_OnPlayerRequestRobbery
#endif
#define OnPlayerRequestRobbery DynamicActorrob_OnPlayerRequestRobbery
#if defined DynamicActorrob_OnPlayerRequestRobbery
    forward DynamicActorrob_OnPlayerRequestRobbery(playerid);
#endif
