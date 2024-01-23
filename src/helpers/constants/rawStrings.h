#ifndef _RAWSTRINGS_
#define _RAWSTRINGS_
#include <string>
#include "./types.h"

using namespace std;

namespace rawStrings {
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
	const string error {R"(
 ___                 
| __|_ _ _ _ ___ _ _ 
| _|| '_| '_/ _ \ '_|
|___|_| |_| \___/_|  
	)"};
	const string titleDescription {R"(
- Controls:
	- `SPACEBAR` = start
	- `Q` = quit
	- `W`, `A`, `S`, `D` = movement
	- `E` = interact/attack
- Goal: You start in an underground city. Find the co-ordinates towards the surface.
- NB: Make sure your terminal is using UTF-8 encoding
	(in Windows you can check this using `chcp`, which should return `Active code page: 65001`.
	Set it manually with `chcp 65001`)
- NB: Make sure your terminal is using the font family `Cascadia mono`
	)"};
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
