export LOAD_LIBRARY_PATH="/usr/local/lib"

.PHONY: gui
gui:
	g++ -Wall -o r -L/usr/local/lib -L. -lserialport motor_gui.cpp
