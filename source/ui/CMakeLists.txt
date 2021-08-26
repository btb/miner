#
# Makefile for user-interface functions
#

# What libs to make
add_library(ui)

# What programs to make
add_executable(testgui)

# What object files for the lib
target_sources(ui PRIVATE ui.c mouse.c window.c uidraw.c button.c gadget.c listbox.c message.c popup.c scroll.c radio.c checkbox.c inputbox.c userbox.c menu.c harderr.c file.c keytrap.c icon.c keypress.c menubar.c keypad.c )

# What object files and libs for the test programs
target_sources(testgui PRIVATE testg.c func.c)
target_link_libraries(testgui io gr ui misc mem iff cflib cfile) #readfile func
target_link_options(testgui PRIVATE option stack=50k)
