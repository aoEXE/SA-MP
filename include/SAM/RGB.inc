/****************************************************************************************************
 *                                                                                                  *
 *                                        R G B A Conversion                                        *
 *                                                                                                  *
 * Copyright � 2016 Abyss Morgan. All rights reserved.                                              *
 *                                                                                                  *
 * Download: https://github.com/AbyssMorgan/SA-MP/tree/master/include/SAM                           *
 *                                                                                                  *
 * File Version: 2.3                                                                                *
 *                                                                                                  *
 * Functions:                                                                                       *
 * RGBAToHex(color,&red,&green,&blue,&alpha); //ShiftRGBAToHex                                      *
 * HexToRGBA(&color,red,green,blue,alpha);    //ShiftHexToRGBA                                      *
 * RGBToHex(color,&red,&green,&blue);         //ShiftRGBToHex                                       *
 * HexToRGB(&color,red,green,blue);           //ShiftHexToRGB                                       *
 * RGBAToRGB(color);                          //ShiftRGBAToRGB                                      *
 * RGBToRGBA(color,alpha);                    //ShiftRGBToRGBA                                      *
 * RGBToARGB(color,alpha);                    //ShiftRGBToARGB                                      *
 * ARGBToRGB(color);                          //ShiftARGBToRGB                                      *
 * RGBAToARGB(color);                         //ShiftRGBAToARGB                                     *
 * ARGBToRGBA(color);                         //ShiftARGBToRGBA                                     *
 * GetRFromRGBA(color);                       //RGBA:0xFAB0A0FF R:0xFA000000                        *
 * GetGFromRGBA(color);                       //RGBA:0xFAB0A0FF G:0x00B00000                        *
 * GetBFromRGBA(color);                       //RGBA:0xFAB0A0FF B:0x0000A000                        *
 * GetAFromRGBA(color);                       //RGBA:0xFAB0A0FF A:0x000000FF                        *
 * GetRHexFromRGBA(color);                    //RGBA:0xFAB0A0FF R:0xFA                              *
 * GetGHexFromRGBA(color);                    //RGBA:0xFAB0A0FF G:0xB0                              *
 * GetBHexFromRGBA(color);                    //RGBA:0xFAB0A0FF B:0xA0                              *
 * GetAHexFromRGBA(color);                    //RGBA:0xFAB0A0FF A:0xFF                              *
 * GetColor(color);                           //Return {RGB}                                        *
 *                                                                                                  *
 ****************************************************************************************************/

#if defined _rgb_function
	#endinput
#endif
#define _rgb_function

#define ShiftRGBAToHex(%0,%1,%2,%3,%4)	(((%1) = ((%0) >>> 24)),((%2) = (((%0) >>> 16) & 0xFF)),((%3) = (((%0) >>> 8) & 0xFF)),((%4) = ((%0) & 0xFF)))
#define ShiftHexToRGBA(%0,%1,%2,%3,%4)	((%0) = ((%4) & 0xFF) | (((%3) & 0xFF) << 8) | (((%2) & 0xFF) << 16) | ((%1) << 24))

#define ShiftRGBToHex(%0,%1,%2,%3)		(((%1) = (((%0) >>> 16) & 0xFF)),((%2) = (((%0) >>> 8) & 0xFF)),((%3) = ((%0) & 0xFF)))
#define ShiftHexToRGB(%0,%1,%2,%3)		((%0) = ((%3) & 0xFF) | (((%2) & 0xFF) << 8) | (((%1) & 0xFF) << 16))

#define ShiftRGBAToRGB(%0)				(((%0) >>> 8) & 0xFFFFFF)
#define ShiftRGBToRGBA(%0,%1)			(((%0) << 8) | (%1))

#define ShiftRGBToARGB(%0,%1)			((%0) | (%1 << 24))
#define ShiftARGBToRGB(%0)				((%0) & 0x00FFFFFF)

#define ShiftRGBAToARGB(%0)				((((%0) << 24) & 0xFF000000) | (((%0) >>> 8) & 0xFFFFFF))
#define ShiftARGBToRGBA(%0)				((((%0) << 8) & 0xFFFFFF00) | (((%0) >>> 24) & 0xFF))

#define GetRFromRGBA(%0)				((%0) & 0xFF000000)
#define GetGFromRGBA(%0)				((%0) & 0x00FF0000)
#define GetBFromRGBA(%0)				((%0) & 0x0000FF00)
#define GetAFromRGBA(%0)				((%0) & 0x000000FF)

#define GetRHexFromRGBA(%0)				(((%0) >>> 24) & 0xFF)
#define GetGHexFromRGBA(%0)				(((%0) >>> 16) & 0xFF)
#define GetBHexFromRGBA(%0)				(((%0) >>> 8) & 0xFF)
#define GetAHexFromRGBA(%0)				((%0) & 0xFF)

stock GetColor(color){
    new string[10];
    format(string,sizeof(string),"{%06x}",ShiftRGBAToRGB(color));
    return string;
}

#define RGBAToHex						ShiftRGBAToHex
#define HexToRGBA						ShiftHexToRGBA
#define RGBToHex						ShiftRGBToHex
#define HexToRGB						ShiftHexToRGB
#define RGBAToRGB						ShiftRGBAToRGB
#define RGBToRGBA						ShiftRGBToRGBA
#define RGBToARGB						ShiftRGBToARGB
#define ARGBToRGB						ShiftARGBToRGB
#define RGBAToARGB						ShiftRGBAToARGB
#define ARGBToRGBA						ShiftARGBToRGBA

//EOF