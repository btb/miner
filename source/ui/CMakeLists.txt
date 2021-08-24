#
# Makefile for user-interface functions
#

# What libs to make
add_library(ui)

# What programs to make
# add_executable(testg)

# What object files for the lib
target_sources(ui PRIVATE ui.c mouse.c window.c uidraw.c button.c gadget.c listbox.c message.c popup.c scroll.c radio.c checkbox.c inputbox.c userbox.c menu.c harderr.c file.c keytrap.c icon.c keypress.c menubar.c keypad.c )
#func.c #Couldn't find func.c - where are the functions??

# What object files and libs for the test programs
# target_sources(testg PRIVATE testg.c)
# target_link_libraries(testg io.lib gr.lib ui.lib misc.lib mem.lib readfile.lib iff.lib func.lib cflib.lib cfile.lib)
# target_link_options(testg PRIVATE option stack=50k)
