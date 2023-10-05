# Agon Light Compilation Toolset

Three major C compilers are available to Agon Light community when it
comes to writing code for the main eZ80 operating system MOS. All three
are used interchangeably in this repository and its sub-repositories,
mostly for educational purposes and due to their varying capabilities.

# Compilers

## Zilog ZDS II

[**Zilog ZDS II**](https://zilog.com/index.php?option=com_zcm&task=view&soft_id=54&Itemid=74)
is a compiler/linked suite capable of creating both Z80 and eZ80 code,
running natively in Windows. This project assumes a seamless Wine-based
installation w/ ZDS binaries readily available to the Linux ecosystem,
i.e., shell scripts available on path, with equivalent names in lowercase,
executing Wine to run them in `.wine/drive_c/{zds_installation}` directory.

To install ZDS installer, just download the installation media, install wine
and run the ZDS installer (while specifying simple-enough path on `C:`, then
creating simple scripts in your PATH, i.e. like `/usr/local/bin/ez80lib`:

```
#!/bin/bash
ZDS_DIR=/home/user/.wine/drive_c/Zilog/ZDS
wine $ZDS_DIR/bin/eZ80lib.exe "$@"
```

## Z88DK

[Z88DK](https://github.com/z88dk/z88dk/wiki/Platform---AgonLight) is
a portable C compiler capable of producing reasonably well optimized code
without much hassle, with support for Agon Light already built in its libraries,
more details [here](https://github.com/z88dk/z88dk/wiki/Platform---AgonLight).

This compiler is currently not able to work in native eZ80 mode, though
(as of Oct 2023). All utilities requiring larger address space either
for the data they operate with or due to their sheer size cannot use
this compiler. Equally so if they are coded in C++.

## AgDev fork of CE C/C++ Toolchain

The most advanced, native Linux toolchain capable of producing eZ80 native
code and compiling both C and C++ code is built on top of LLVM back-end.
It was originally authored for the TI-84 calculator, then ported to Agon:

* [CE C/C++ Toolchain]() - original code base
* [AgDev](https://github.com/pcawte/AgDev) - fork and port to Agon Light applied on top of binary distribution

_Please note: until further notice, the toolset used needs to come from
the latest binary distribution of CE Toolchain being overlayed by the AgDev repo.
As of writing this readme, compiling CE Toolchain from
its [sources](https://github.com/CE-Programming/toolchain) and overlaying
it with AgDev content results in perfectly fine working toolset, which
unfortunately creates binaries incompatible with Agon (incorrect structure)._
