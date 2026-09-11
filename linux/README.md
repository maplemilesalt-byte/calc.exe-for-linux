# Experimental Linux port

This directory contains the experimental Linux port of the Windows Calculator codebase.

The first milestone is to isolate the calculator's platform-independent logic from the Win32 GUI and establish a native Linux build.

## Porting strategy

- Keep the original calculator/math behavior where practical.
- Replace Win32 window/input/resource APIs incrementally.
- Avoid rewriting the math engine unless necessary.
- Keep Linux-specific code under `linux/` while the port is experimental.

## First milestone

Build a small native Linux frontend that can exercise the calculator logic. GUI work comes after the core build is working.
