/****************************************************************************************************
 *                                                                                                  *
 * TextDraw Update v1.2 made by Abyss Morgan                                                        *
 *                                                                                                  *
 * Download: https://github.com/AbyssMorgan/SA-MP/tree/master/include/SAM                           *
 *                                                                                                  *
 * Functions:                                                                                       *
 * CountTextDraw();                                                                                 *
 * CountPlayerTextDraw(playerid);                                                                   *
 *                                                                                                  *
 ****************************************************************************************************/

#if defined _Text_Draw_Ex
	#endinput
#endif
#define _Text_Draw_Ex

new TextDrawCount = 0,
	PlayerTextDrawCount[MAX_PLAYERS];

#define CountTextDraw()				(TextDrawCount)
#define CountPlayerTextDraw(%0)		(PlayerTextDrawCount[(%0)])

//TextDrawCreate
stock Text:AC_TextDrawCreate(Float:x,Float:y,text[]){
	TextDrawCount++;
	return TextDrawCreate(x,y,text);
}

#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif
#define TextDrawCreate AC_TextDrawCreate

//CreatePlayerTextDraw
stock PlayerText:AC_CreatePlayerTextDraw(playerid,Float:x,Float:y,text[]){
	PlayerTextDrawCount[playerid]++;
	return CreatePlayerTextDraw(playerid,x,y,text);
}

#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
#else
    #define _ALS_CreatePlayerTextDraw
#endif
#define CreatePlayerTextDraw AC_CreatePlayerTextDraw

//TextDrawDestroy
stock AC_TextDrawDestroy(Text:text){
	TextDrawCount--;
	return TextDrawDestroy(text);
}

#if defined _ALS_TextDrawDestroy
    #undef TextDrawDestroy
#else
    #define _ALS_TextDrawDestroy
#endif
#define TextDrawDestroy AC_TextDrawDestroy

//DestroyPlayerTextDraw
stock AC_DestroyPlayerTextDraw(playerid,PlayerText:text){
	PlayerTextDrawCount[playerid]--;
	return DestroyPlayerTextDraw(playerid,text);
}

#if defined _ALS_DestroyPlayerTextDraw
    #undef DestroyPlayerTextDraw
#else
    #define _ALS_DestroyPlayerTextDraw
#endif
#define DestroyPlayerTextDraw AC_DestroyPlayerTextDraw

//EOF