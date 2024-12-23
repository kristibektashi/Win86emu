Win86emu
========
CURRENTLY BROKEN!!!!!!

Win86emu(Windows x86 Emulator) is a usermode emulator that runs leagacy x86 desktop programs on the Windows RT platform.

The original version was written by [mamaich](http://forum.xda-developers.com/member.php?u=224595)([blog](http://mamaich-eng.blogspot.ru/)), but since [he broke his Windows RT device and has no plan to get a new one](http://forum.xda-developers.com/showpost.php?p=49948525&postcount=392), the peoject is abandoned. For more information, please visit [this thread](http://forum.xda-developers.com/showthread.php?t=2095934).

This repo is an attempt to merge together the several forks of the original Win86emu that exist on the internet, so that we have the best of all worlds, as well as updating the project to compile with Visual Studio 2019 and the Windows 8.1 SDK (so that it will still work on Windows RT 8.1). It is currently broken and emulated apps don't appear correctly (at least in Release builds). Eventually I might fix it so that it works at least as well as the original Win86emu (but hopefully better). It also hasn't been tested on ARM yet. Below are the forks which this repo currently attemps to merge together on top of the original Win86emu. Each of them has been updated to compile with VS2019 and the Windows 8.1 SDK but is otherwise (mostly) unmodified from the corresponding source. 

https://github.com/MakiseKurisu/Win86emu (branch1)

https://archive.org/details/win86emu (branch2)

https://github.com/hiroki-repo/x86node-SP1-zip (branch3)

Build instructions:

0. Install VS2019 and the Windows 8.1 SDK
1. Clone this repo with git
2. Build either Debug or Release configuration and either Win32 (a.k.a. x86*) or ARM architecture. x64 is not supported
3. Copy `output\bin\<architecture>\<configuration>\*.*` to `C:\x86node\`
4. Copy `output\bin\stub_dll\<configuration>\system32\*.*` to `C:\x86node\Windows\system32\`
5. Copy `extras\x86node\*.*` to `C:\x86node\`
6. Run x86 programs using the batch files in C:\x86node\ (or manually, if you want to)

PDB files are generated in `output\pdb\`

*Yes you can build Win86Emu for x86 and therefore emulate x86 apps on x86, this is for debugging purposes mostly since you can just run these apps natively on x86 anyway
