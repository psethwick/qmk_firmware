# Bootloader selection
BOOTLOADER = dfu

# Build Options
#   comment out to disable the options.
#
MOUSEKEY_ENABLE = no	  # Mouse keys
EXTRAKEY_ENABLE = yes	  # Audio control and System control

VPATH += keyboards/gboards
SRC += g/engine.c 

