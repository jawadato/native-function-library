A handful of additional functions for Unreal Engine.

![scrn_nfl_001_half](https://github.com/jawadato/native-function-library/assets/18325896/230a403d-9a7f-4642-a717-0b81f23315fc)

To use, add a new Blueprint Function Library C++ class to your project. Name it "NativeFunctionLibrary" for easiest integration. Pay attention to the "YOURPROJECT_API" part, copy whatever this name is. Paste the contents of both header and cpp file into your newly created class files. Replace "PROJECT_API" with previously copied name. Save and compile the files, you can compile from within the Unreal Editor. Afterwards, the functions should show up in the engine.
These functions should work with any engine versions above 4.27.
