# Agon Utilities

---
**Table of contents**

- [About](#about)
- [Repository structure](#repository-structure)
- [Hardware](#hardware)
- [Utilities](#utilities)
    - [vmode](#vmode)
        - [vmode command line](#vmode-command-line)

**Additional local docs**

- [Agon Light Compilation Toolset](docs/toolset)
- [Typical development tasks](docs/development)

---

# About

Set of various utilities for the base MOS/VDP ecosystem on Agon Light.
The programs included are either written from scratch as part of this
project due to immediate needs of the author or ported from other
GitHub repos or other sources.

# Repository structure

The utilities reside either directly in the top level structure or are
loaded as git submodules. Please ensure the whole git structure is
initialize and available:

```
git submodule update --init --recursive
```

# Hardware

The [Agon Light](https://www.thebyteattic.com/p/agon.html) is an 8-bit
computer in nature running eZ80 core w/ 24-bit address space utilizing
512kB of onboard memory, with the capability of also operating in
backward-compatible, 16-bit Z80 mode and 64kB RAM. The machine is
accompanied by 'VDP' peripheral processor implemented using ESP32
running Arduino-authored firmware, w/ 8MB accompanying RAM.

Both eZ80 and ESP32 have own boot flash which can be reprogrammed
using various techniques (outside the focus of this repository). This
repository mostly focuses on tools for MOS operating system, running
on eZ80. The [toolset](docs/toolset) document has more details
on establishing building tools for Agon Light and this repository.

# Utilities

All the utilities are meant to be put in `/mos` directory of your SD card,
to be seamlessly executable from the MOS OS. The below chapters cover each
utility in this repository in detail, as it would function on MOS command line.

Each utility can be compiled in its directory using the accompanied tooling,
typically Makefile-based build. Over-arching project uses Gradle to orchestrate
diverse toolset ecosystem and build all tools at once.

To run overall build, please use:

```
./gradlew clean build
```

The resulting tools will be available in `build/dist/` directory.

## vmode

Lists video modes, gets current video mode details and switches VDP video mode
to the desired one. The utility also describes the mode afterward (as a top line).

The utility unfortunately hangs when run off `mos/` directory for unknown reasons
for now. It has to be executed by standard load/run sequence for now, investigation
will follow. The command line parameter syntax described below thus needs to be
altered like this:

```
load vmode.bin
run &040000 ...parameters...
```

### vmode command line

Listing the video modes (VDP 1.04+ assumed):

```
vmode list
```

Getting the video mode:

```
vmode get
```

Setting the video mode:

```
vmode <number>
vmode set <number>
```

Any command can be abbreviated by just its first character as well. Set command
can be issued without the command itself, just by specifying the video mode number.

_Please note: Video modes of Agon Light changed drastically between VDP 1.03 and 1.04,
see [here](https://github.com/breakintoprogram/agon-docs/wiki/VDP#screen-modes).
The utility supports assumes 1.04 mode table when reporting the mode at the top
of the screen, but will work fine on 1.03 and below versions of course (barring the
incorrect info given)._
