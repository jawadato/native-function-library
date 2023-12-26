A handful of additional functions for Unreal Engine.

![scrn_nfl_001_half](https://github.com/jawadato/native-function-library/assets/18325896/230a403d-9a7f-4642-a717-0b81f23315fc)

How to use:

> - Add a new Blueprint Function Library C++ class to your project, call it "NativeFunctionLibrary" for easiest integration.
> - Pay attention to the "YOURPROJECT_API" part, copy whatever this name is.
> - Paste the contents of both the header and cpp files from this repo into the respective files of your newly created class.
> - Replace "PROJECT_API" with previously copied name.
> - Save and compile the files, you can compile from within the Unreal Editor.

Afterwards, the functions should show up in the engine. These functions should work with any engine versions above 4.27.

> - For engine versions 5 and above, if you are relying on the Editor to compile the code then you may want to check the “Force Compilation at Startup” from the editor preferences otherwise you may need to manually compile the code every time you open the project.
