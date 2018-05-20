/*
   segment.h

   Declare external reference of the segment symbol that makerom outputs 
    ( Not used in the sample this time.)

   Copyright (C) 1997-1999, NINTENDO Co,Ltd.	
*/


#ifndef SEGMENT_H
#define SEGMENT_H

extern char _codeSegmentStart[];         /* code segment start */
extern char _codeSegmentEnd[];           /* code segment end */

extern u8 _wbankSegmentRomStart[];
extern u8 _pbankSegmentRomStart[];
extern u8 _pbankSegmentRomEnd[];
extern u8 _tune1SegmentRomStart[];
extern u8 _tune1SegmentRomEnd[];

#define WBANK_START	_wbankSegmentRomStart
#define PBANK_START	_pbankSegmentRomStart
#define PBANK_END	_pbankSegmentRomEnd
#define MUSIC1_START	_tune1SegmentRomStart
#define MUSIC1_END	_tune1SegmentRomEnd

#endif /* SEGMENT_H */
