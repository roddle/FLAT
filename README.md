0. CONTENTS
===========

1. Introduction
2. Building from source
3. Story
4. Controls
5. Credits
6. Resources
7. Known Issues
8. Dependencies



1. INTRODUCTION
===============

Hey and thanks for checking out FLAT!

FLAT was created by Johan "SteelRaven7" Hassel, Josh "Cheeseness" Bush, Johannes "jo_shadow" Peter and Anton Riehl for the 7 Day FPS Challenge 2012.

Inspired by early first person shooters, arcade genres and popular sci-fi, we aimed to create a unique and hopefully memorable gameplay experience.

In the several days following the conclusion of the 7 Day FPS Challenge, we spent time polishing numerous gameplay aspects and adding additional audio to the game. At this stage, we still consider it a work in progress, but we believe that it is enjoyable and playable in its current state.

A month or so after the 7DFPS challenge ended, we released FLAT under the GPL. You can find the source here: https://github.com/Cheeseness/FLAT

Thanks again, and don't hesitate to leave feedback if you feel like it!

/The FLAT Team


Please see the INSTALL file for compilation instructions.


2. BUILDING FROM SOURCE
=======================

FLAT uses `cmake` to automatically build the required makefiles, so `cmake` is a required dependency if you want to build FLAT from source using this method.

In the root directory (FLAT):

`$ cmake .`

`$ make`

The binary should be located in the `out`-folder after compilation.



3. STORY
========

You play as the last remaining individual of a race who has fallen under the mind control of the evil Pulse Dragon. Marooned on a crystaline world, you must fight your way through hordes of your own kind to slay the mighty Pulse Dragon and free your people.

(Seriously, we didn't have a lot of time to flesh out story <3)



4. CONTROLS
===========

Look around using the mouse, or the arrow keys.

Hold W and alternate between A/D to move forward (think ice-skating!).
Holding S allows you to accelerate backwards in the same manner.
When you have gained sufficient speed, you can "carve" or slide left/right by holding down A or D for longer periods.

Holding A or D and pressing space allows you to jump and dodge projectiles.

You can pick up new weapons and health kits from supply capsules. They play a sound when they spawn, so keep an eye out for the white beam that indicates one. Pressing H or Q will use a health kit.

Use the left mouse button, X or the Up key to shoot.

The escape key will pause the game.



5. CREDITS
==========

You can find us on twitter:
Johan "SteelRaven7" Hassel (code): @SteelRaven7
Josh "Cheeseness" Bush (3D art + bit of code + bit of audio): @twolofbees
Johannes "jo_shadow" Peter (concept art + audio): @jo_shadow
Anton Riehl (music): @antonriehl

Special thanks to @slime73 for assistance with MacOS builds!
Special thanks to aaorris



6. RESOURCES
============

Shotgun sound based on sound by PhreaKsAccount 
http://www.freesound.org/people/PhreaKsAccount/sounds/46263/

Pistol, SMG sound based on sound by Steveygos93
http://www.freesound.org/people/steveygos93/sounds/103626/

The Blender material used for the crystals came from the Blender Open Material Repository
http://matrep.parastudios.de/index.php?action=view&material=290-crystal



7. KNOWN ISSUES
===============

* Sometimes, on rare occasions, the camera will spin wildly at the start of the game on MacOS
* There are invisible crystals that the player can bump into
* The MacOS version of the Allegro 5 library has a bug preventing mouse input from working correctly in FLAT. MacOS users will need to use the left and right arrow keys to look around.
* On rare occasions, enemies may not spawn on MacOS
* Arch Linux users have reported crashes when initialising audio. A workaround can be found here: https://github.com/Cheeseness/FLAT/issues/32


8. DEPENDENCIES
===============

FLAT uses Allegro 5 ( http://alleg.sourceforge.net/ ). You will need the following packages.

Please note that the current Linux build of FLAT is 32 bit only, and may require additional 32 bit libraries.

allegro5
allegro5-addon-ttf
allegro5-addon-audio
allegro5-addon-acodec
allegro5-addon-image
