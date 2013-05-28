//
//  Global.h
//  Fever
//
//  Created by Arthur Fox on 14/02/2013.
//  Copyright (c) 2013 OMA. All rights reserved.
//

#ifndef Fever_Global_h
#define Fever_Global_h

//#include <string>
//#include <iostream>
//#include <sstream>
//#include <iomanip>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "engine.h"
#include "Path.h"

#define RESOURCE_PATH           "Fever.app/Contents/Resources/"
#define RESOURCE_TITLE_FONT     "ldmusic.ttf"
#define RESOURCE_FONT           "Insignia.otf"//"FuturaMedium.ttf"
#define RESOURCE_PLAYER         "Blob2.png"
#define RESOURCE_COIN           "SimpleCoin2.png"

#define LEVEL_PATH              "/Users/arthurfox/Desktop/Programming/Xcode/Project_MusicToGame/Levels/"
#define LEVEL_EXTENSION         ".lvl"
#define LEVEL_NOT_LOADED        "NULL"
#define LEVEL_TEMP              "/Users/arthurfox/Desktop/Programming/Xcode/Project_MusicToGame/Levels/TempOutput.lvl"

#define MUSIC_SUCCESS           "/Users/arthurfox/Desktop/Programming/Xcode/Project_MusicToGame/Songs/Secret.wav"
#define MUSIC_FAIL              "/Users/arthurfox/Desktop/Programming/Xcode/Project_MusicToGame/Songs/Error.wav"

#define FORMATS_AUDIO           "wav,mp3,WAV,MP3,AU"
#define FORMATS_LEVEL           "lvl"

//Debugging variables
const bool MATLAB_ON = true;

//Update attributes
const bool VARIABLE_TIME_STEP = true;
const int FRAMES_PER_SECOND = 60;
const int UPDATES_PER_SECOND = 100;
const int LIMIT_UPDATES = 3; 
const float FIXED_TIME_STEP = 1000.0f/UPDATES_PER_SECOND;

//Screen attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int SCREEN_BPP = 32;

//The dimensions of the level 
const int LEVEL_WIDTH = SCREEN_WIDTH; //WRONG! - THIS VARIES BETWEEN SONGS!
const int LEVEL_HEIGHT = SCREEN_HEIGHT;

//File attributes
const int MAX_PATH_SIZE = 200;

//Music attributes
const int DEFAULT_VOLUME = 128;
const int PAUSE_VOLUME = 30; // IS THIS NEEDED?

//Font attributes
const int SMALL_FONT = 1;
const int MEDIUM_FONT = 2;
const int LARGE_FONT = 3;
const int TITLE_FONT = 4;

// ************************************************************
//      Should all these variables even be stored here?
//

//Dimensions of player
const int PLAYER_WIDTH = 100;
const int PLAYER_HEIGHT = 70;

//Player Constants
const int INIT_JUMP = 1000; //766;
const int INIT_GRAVITY = 3090;
const int INIT_WALK = 736;

//Coin Constants
const int COIN_WIDTH = 45;
const int COIN_HEIGHT = 45;

//Score constants
const int INIT_SCORE = 0;
const int INIT_MULT = 1;

//Level constants
const int WALL_WIDTH = 30;//CHECK: CHANGE THIS VALUE WITH WINDOW SIZE?
const float LEVEL_SPEED_FACTOR = 3; //CHECK: THIS VALUE SHOULD NOT BE ARBITRARY?
const float LEVEL_PADDING = PLAYER_HEIGHT*1.5;
const int DEFAULT_LEVEL_SPEED = 350;
// ************************************************************

//Color attributes
const int WHITE_COLOUR = 1;

// Global gives access to global variables, functions and includes.
class Global 
{
public:	
	//Singleton pattern
	static Global* SharedGlobal();	
    
    //Static functions
    static bool IsThreadRunning()                   {return ms_genThreadRunning;}
    static void SetThreadRunning( bool running )    {ms_genThreadRunning = running;}
    
    //Inline functions
    inline bool IsMuted() const                     {return m_muted;}
    inline void MuteUnMute()                        {m_muted = !m_muted;}
    
    void Initialisation();
    void CleanUp();
    
    TTF_Font* GetFont( int font ) const;
    SDL_Color GetColor( int color ) const;
    
	SDL_Surface* LoadImage( const std::string& filename ) const;
	void ApplySurface( int x, int y, SDL_Surface* pSource, SDL_Surface* pDestination, SDL_Rect* clip = NULL ) const;
    
    void EvalMatlabString( const char* str );
    
private:
	//Singleton instance
	static Global* ms_pGlobal;
    static Path* ms_pPath;
    
    //Static functions
    static bool ms_genThreadRunning;
    
    //Private Variables
    Engine *m_pMateng;
    TTF_Font  *m_pSmallFont, *m_pMediumFont, *m_pLargeFont, *m_pTitleFont;
    SDL_Color m_whiteColour;
    bool m_muted;
    
    //Private Functions
	Global();    
    void InitSDL() const;
    void InitMatlab();
    void InitFontsColors();
    void InitMusic();
};

#endif