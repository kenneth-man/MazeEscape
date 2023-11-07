#ifndef _CONSTANTS_
#define _CONSTANTS_
#include <string>

using namespace std;

namespace helperConstants {
	const string titleName {R"(                                                                                                  
@@@@@@@@@@    @@@@@@   @@@@@@@@  @@@@@@@@  @@@@@@@@   @@@@@@    @@@@@@@   @@@@@@   @@@@@@@   @@@@@@@@  
@@@@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  
@@! @@! @@!  @@!  @@@       @@!  @@!       @@!       !@@       !@@       @@!  @@@  @@!  @@@  @@!       
!@! !@! !@!  !@!  @!@      !@!   !@!       !@!       !@!       !@!       !@!  @!@  !@!  @!@  !@!       
@!! !!@ @!@  @!@!@!@!     @!!    @!!!:!    @!!!:!    !!@@!!    !@!       @!@!@!@!  @!@@!@!   @!!!:!    
!@!   ! !@!  !!!@!!!!    !!!     !!!!!:    !!!!!:     !!@!!!   !!!       !!!@!!!!  !!@!!!    !!!!!:    
!!:     !!:  !!:  !!!   !!:      !!:       !!:            !:!  :!!       !!:  !!!  !!:       !!:       
:!:     :!:  :!:  !:!  :!:       :!:       :!:           !:!   :!:       :!:  !:!  :!:       :!:       
:::     ::   ::   :::  :: ::::   :: ::::   :: ::::  :::: ::    ::: :::   ::   :::   ::       :: ::::  
 :      :     :   : :  : :: : :  : :: ::   : :: ::   :: : :     :: :: :   :   : :   :        : :: ::
	)"};
	const string titleDescription {R"(
- Press `SPACEBAR` to start the game
- Press `Q` at any time to quit the game
- Controls:
	- `W`, `A`, `S`, `D` to move
	- `SPACEBAR` to interact/attack
- Goal: Try to escape!
- NB: Make sure your terminal is using UTF-8 encoding
	(in Windows you can check this using `chcp`, which should return `Active code page: 65001`.
	Set it manually with `chcp 65001`)
- NB: Make sure your terminal is using the font family `Cascadia mono`
	)"};
	const string terrain = "█";
	const string player = "╇";
	const string xBorder = "║";
	const string yBorder = "═";
	const string topLeftBorder = "╔";
	const string topRightBorder = "╗";
	const string botLeftBorder = "╚";
	const string botRightBorder = "╝";
	const string demon {R"(
		                                             ,--,  ,.-.
               ,                   \,       '-,-`,'-.' | ._
              /|           \    ,   |\         }  )/  / `-,',
              [ ,          |\  /|   | |        /  \|  |/`  ,`
              | |       ,.`  `,` `, | |  _,...(   (      .',
              \  \  __ ,-` `  ,  , `/ |,'      Y     (   /_L\
               \  \_\,``,   ` , ,  /  |         )         _,/
                \  '  `  ,_ _`_,-,<._.<        /         /
                 ', `>.,`  `  `   ,., |_      |         /
                   \/`  `,   `   ,`  | /__,.-`    _,   `\
               -,-..\  _  \  `  /  ,  / `._) _,-\`       \
                \_,,.) /\    ` /  / ) (-,, ``    ,        |
               ,` )  | \_\       '-`  |  `(               \
              /  /```(   , --, ,' \   |`<`    ,            |
             /  /_,--`\   <\  V /> ,` )<_/)  | \      _____)
       ,-, ,`   `   (_,\ \    |   /) / __/  /   `----`
      (-, \           ) \ ('_.-._)/ /,`    /
      | /  `          `/ \\ V   V, /`     /
   ,--\(        ,     <_/`\\     ||      /
  (   ,``-     \/|         \-A.A-`|     /
 ,>,_ )_,..(    )\          -,,_-`  _--`
(_ \|`   _,/_  /  \_            ,--`
 \( `   <.,../`     `-.._   _,-`
    )"};
}

#endif
