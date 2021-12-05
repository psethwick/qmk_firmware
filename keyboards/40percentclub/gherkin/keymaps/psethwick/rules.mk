# Bootloader selection
BOOTLOADER = dfu

# Build Options
#   comment out to disable the options.
#
VIRTSER_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pr

VPATH += keyboards/gboards
SRC += g/engine.c 
LTO_ENABLE = yes
OPT_DEFS += -DONLYQWERTY

