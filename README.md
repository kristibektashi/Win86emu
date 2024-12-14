Win86emu
========

Win86emu(Windows x86 Emulator) is a usermode emulator that runs leagacy x86 desktop programs on the Windows RT platform.

The original version was written by [mamaich](http://forum.xda-developers.com/member.php?u=224595)([blog](http://mamaich-eng.blogspot.ru/)), but since [he broke his Windows RT device and has no plan to get a new one](http://forum.xda-developers.com/showpost.php?p=49948525&postcount=392), the peoject is abandoned. For more information, please visit [this thread](http://forum.xda-developers.com/showthread.php?t=2095934).

This repo is an attempt to merge together the several forks of the original Win86emu that exist on the internet, so that we have the best of all worlds, as well as updating the project to compile with Visual Studio 2019 and the Windows 8.1 SDK (so that it will still work on Windows RT 8.1). It is currently broken and emulated apps don't appear correctly (at least in Release builds). It also hasn't been tested on ARM yet. Below are the forks which this repo currently attemps to merge together on top of the original Win86emu. Each of them has been updated to compile with VS2019 and the Windows 8.1 SDK but is otherwise (mostly) unmodified from the corresponding source. 

https://github.com/MakiseKurisu/Win86emu (branch1)

https://archive.org/details/win86emu (branch2)

https://github.com/hiroki-repo/x86node-SP1-zip (branch3)

